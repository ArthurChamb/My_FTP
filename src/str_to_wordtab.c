/*
** str_to_wordtab.c for str_to_wordtab in /home/arthok/Rendu/C/PSU_2016_myftp/src
** 
** Made by Arthur XXXXXX
** Login   <arthur.XXXXXX@epitech.eu>
** 
** Started on  Tue May 16 12:18:08 2017 Arthur XXXXXX
** Last update Tue May 16 12:45:02 2017 Arthur XXXXXX
*/

#include <stdlib.h>

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    i++;
  return (i);
}

int	check_carac_a(char *str, int i, int a)
{
  if ((str[i] > 0 && str[i] < 48) || (str[i] == 32)
	  || (str[i] > 57 && str[i] < 65)
	  || (str[i] > 90 && str[i] < 97)
	  || (str[i] > 122) || str[i] == '\0')
    return (a);
  return (a + 1);
}

int	check_carac(char *str, int i)
{
  if ((str[i] > 0 && str[i] < 47) || (str[i] == 32)
	  || (str[i] > 57 && str[i] < 65)
	  || (str[i] > 90 && str[i] < 97)
	  || (str[i] > 122) || str[i] == '\0')
    return (0);
  return (1);
}

char	**nb_words(char *str)
{
  int	i;
  int	words;
  char **tab;

  i = 0;
  words = 1;
  while (str[i] != '\0')
    {
      if ((str[i] > 0 && str[i] < 47) || (str[i] == 32)
	  || (str[i] > 57 && str[i] < 65)
	  || (str[i] > 90 && str[i] < 97)
	  || (str[i] > 122))
	words++;
      i++;
    }
  if ((tab = malloc(sizeof(char *) * words + 1)) == NULL)
    return (NULL);
  return (tab);
}

char	**my_str_to_wordtab(char *str)
{
  char	**tab;
  int	a;
  int	i;
  int	c;

  tab = nb_words(str);
  i = 0;
  a = 0;
  while (my_strlen(str) > i)
    {
      if ((tab[a] = malloc(sizeof(char) * my_strlen(str))) == NULL)
	return (NULL);
      c = 0;
      while (check_carac(str, i) != 0)
	{
	  tab[a][c] = str[i];
	  c++;
	  i++;
	}
      tab[a][c] = 0;
      a = check_carac_a(str, i - 1, a);
      i++;
    }
  tab[a] = NULL;
  return (tab);
}
