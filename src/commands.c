/*
** commands.c for commands in /home/arthok/Rendu/C/PSU_2016_myftp
** 
** Made by Arthur XXXXXX
** Login   <arthur.XXXXXX@epitech.eu>
** 
** Started on  Tue May 16 14:25:50 2017 Arthur XXXXXX
** Last update Mon May 22 10:20:59 2017 Arthur XXXXXX
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "ftp.h"

int		cdup(int socket_client, t_server *server)
{
  int		n;
  if (server->path[0] == '/' && server->path[1] == '\0')
    {
      write(socket_client, _250_, strlen(_250_));
      return (1);
    }
  n = strlen(server->path);
  while (server->path[n] != '/')
    n--;
  server->path[n] = '\0';
  if (server->path[0] != '/')
    {
      server->path[0] = '/';
      server->path[1] = '\0';
    }
  write(socket_client, _250_, strlen(_250_));
  return (1);
}

int		pwd(int socket_client, t_server *server)
{
  dprintf(socket_client, "257 \"%s\"\r\n", server->path);
  return (1);
}

int		checker(char **tab, int socket_client)
{
  if (tab[0] == NULL)
    return (-1);
  if (my_strcmp(tab[0], "QUIT") == 0)
    my_write(_221_, socket_client);
  return (0);
}

int		help(int socket_client, char **tab)
{
  if (my_strcmp(tab[0], "HELP") == 0)
    {
      write(socket_client, _214_, strlen(_214_));
      write(socket_client, "The comands are : CDUP\nCWD\nHELP\r\n",
	    strlen("The comands are : CDUP\nCWD\nHELP\r\n"));
      write(socket_client, "214 HELP OK.\r\n", strlen("214 HELP OK.\r\n"));
      return (1);
    }
  return (0);
}

int		user_connection(int co, char **tab, int socket_client)
{
  if (co == 0)
    return (0);
  if (my_strcmp(tab[0], "USER") == 0)
    {
      write(socket_client, _331_, strlen(_331_));
      if (tab[1] != '\0' && strcmp(tab[1], "Anonymous") == 0)
	return (2);
      return (1);
    }
  if (my_strcmp(tab[0], "PASS") == 0 && co == 2 && tab[1] == NULL)
    {
      write(socket_client, _230_, strlen(_230_));
      return (0);
    }
  if (my_strcmp(tab[0], "PASS") == 0 && co == 2 && tab[1] != NULL)
    write(socket_client, _430_, strlen(_430_));
  else
    write(socket_client, _530_, strlen(_530_));
  if (co == 2)
    return (2);
  return (1);
}
