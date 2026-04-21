/*
** commands.c for commands in /home/arthok/Rendu/C/PSU_2016_myftp
** 
** Made by Arthur XXXXXX
** Login   <arthur.XXXXXX@epitech.eu>
** 
** Started on  Tue May 16 14:25:50 2017 Arthur XXXXXX
** Last update Sun May 21 19:04:29 2017 Arthur XXXXXX
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <dirent.h>
#include "ftp.h"

int	cwd(char **tab, int socket_client, t_server *server)
{
  DIR	*dir;

  if (tab[1] == NULL || (dir = opendir(tab[1])) == NULL)
    {
      write(socket_client, _550_, strlen(_550_));
      return (1);
    }
  else
    {
      if (strcmp(tab[1], "..") == 0)
	  pwd(socket_client, server);
      write(socket_client, _250_, strlen(_250_));
      server->path = tab[1];
    }
  return (1);
}
