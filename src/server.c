/*
** server.c for server in /home/arthok/Rendu/C/PSU_2016_myftp
** 
** Made by Arthur XXXXXX
** Login   <arthur.XXXXXX@epitech.eu>
** 
** Started on  Mon May 15 13:34:01 2017 Arthur XXXXXX
** Last update Sat May 20 14:36:09 2017 Arthur XXXXXX
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include "ftp.h"

int			check_command(char **tab, int socket_client, t_server *server)
{
  int			n;

  n = -1;
  if (my_strcmp(tab[0], "PASS") == 0)
    return (1);
  if (my_strcmp(tab[0], "NOOP") == 0 || my_strcmp(tab[0], "HELP") == 0)
    n = help(socket_client, tab);
  if (my_strcmp(tab[0], "PWD") == 0)
    n = pwd(socket_client, server);
  if (my_strcmp(tab[0], "CDUP") == 0)
    n = cdup(socket_client, server);
  if (my_strcmp(tab[0], "CWD") == 0)
    n = cwd(tab, socket_client, server);
  return (n);
}

char			*read_line(char *line, int socket_client)
{
  char			*tmp;

  memset(line, 0, 198);
  if ((tmp = malloc(sizeof(char) * 200)) == NULL)
    error_print(READ);
  while (line[strlen(line) - 1] != '\n' && line[strlen(line) - 2] != '\r')
    {
      memset(tmp, 0, 198);
      read(socket_client, tmp, 198);
      strcat(line, tmp);
    }
  if (line[0] == ' ')
    line [0] = 'Z';
  return (line);
}

void			launch_command(int socket_client, int co, t_server *server)
{
  char			*line;
  char			**tab;
  int			n;

  fseek(stdin, 0, SEEK_END);
  if ((line = malloc(sizeof(char) * 200)) == NULL)
    error_print(READ);
  while (1)
    {
      if ((line = read_line(line, socket_client)) == NULL)
	launch_command(socket_client, co, server);
      if ((tab = my_str_to_wordtab(line)) == NULL)
	error_print(READ);
      if (checker(tab, socket_client) == -1)
	launch_command(socket_client, co, server);
      if ((co = user_connection(co, tab, socket_client)) != 0)
	launch_command(socket_client, co, server);
      if ((n = check_command(tab, socket_client, server)) == -1)
	write(socket_client, _500_, strlen(_500_));
      else if (n == 0)
	write(socket_client, _200_, strlen(_200_));
    }
  close(socket_client);
  exit(0);
}

void			server_launch(int socket_id, t_server *server)
{
  pid_t			pid;
  struct sockaddr_in	client_address;
  unsigned int		len;
  int			socket_client;

  while (1)
    {
      if ((socket_client = accept(socket_id,
				  (struct sockaddr *)&client_address, &len)) == -1)
	exit(0);
      if ((pid = fork()) == 0)
	{
	  close(socket_id);
	  write(socket_client, _220_, strlen(_220_));
	  launch_command(socket_client, 1, server);
	}
      else
	close(socket_client);
    }
}

int			main(int ac, char **av)
{
  struct sockaddr_in	server_address;
  int			socket_id;
  t_server		*server;

  check_args(ac, av);
  if ((server = malloc(sizeof(t_server))) == NULL)
    error_print(SOCKET);
  socket_id = socket(AF_INET, SOCK_STREAM, 0);
  if (socket_id == -1)
    error_print(SOCKET);
  server_address.sin_family = AF_INET;
  server_address.sin_addr.s_addr = htonl(INADDR_ANY);
  server_address.sin_port = htons(atoi(av[1]));

  if (bind(socket_id, (struct sockaddr *)&server_address,
	   sizeof(server_address)) == -1)
    error_print(BIND);
  if (listen(socket_id, 5) == -1)
    error_print(LISTEN);
  server->path = av[2];
  server_launch(socket_id, server);
  return (0);
}
