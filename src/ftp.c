/*
** ftp.c for ftp in /home/arthok/Rendu/C/PSU_2016_myftp/include
** 
** Made by Arthur XXXXXX
** Login   <arthur.XXXXXX@epitech.eu>
** 
** Started on  Mon May 15 14:20:11 2017 Arthur XXXXXX
** Last update Thu May 18 08:21:31 2017 Arthur XXXXXX
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include "ftp.h"

void	check_args(int ac, char **av)
{
  DIR	*dir;

  if (ac != 3)
    error_print(USAGE);
  if (atoi(av[1]) <= 0)
    error_print(USAGE);
  if ((dir = opendir(av[2])) == NULL)
    error_print(PATH);
  closedir(dir);
}

void	error_print(char *str)
{
  fprintf(stderr, "%s\n", str);
  exit(-1);
}

void	my_putstr(char *str)
{
  write(1, str, strlen(str));
}

void	my_write(char *str, int socket_client)
{
  write(socket_client, str, strlen(str));
  exit(0);
}

int	my_strcmp(char *str, char *str2)
{
  int n = 0;

  while (str[n] != '\0')
    {
      str[n] = toupper(str[n]);
      n++;
    }
  if (strcmp(str, str2) == 0)
    return (0);
  return (-1);
}
