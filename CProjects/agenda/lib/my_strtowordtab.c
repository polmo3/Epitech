/*
** my_strtowordtab.c for my_strtowordtab in /home/gwendoline/rendu/Piscine_Synthese/projTester
**
** Made by 
** Login   <gwendoline@epitech.net>
**
** Started on  Thu Jun 18 19:51:22 2015 
** Last update Tue Jun 30 09:57:22 2015 Gwendoline Rodriguez
*/

#include "header.h"

int             get_nb_words(char *s)
{
  int   i;
  int   cpt;

  i = 0;
  cpt = 0;
  if (!s)
    return (0);
  while (s[i])
    {
      if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')
          || (s[i] >= '0' && s[i] <= '9') || s[i] == '/' || s[i] == '_')
        {
          cpt = cpt + 1;
          while (s[i] && ((s[i] >= 'a' && s[i] <= 'z')
                          || (s[i] >= 'A' && s[i] <= 'Z') || s[i] == '_'
                          || (s[i] >= '0' && s[i] <= '9') || s[i] == '/'))
            i++;
        }
      i++;
    }
  return (cpt);
}

int             get_nb_char(char *s, int i)
{
  int           cpt;

  cpt = 0;
  while (s[i] && ((s[i] >= 'a' && s[i] <= 'z')
		  || (s[i] >= 'A' && s[i] <= 'Z') || s[i] == '_'
		  || (s[i] >= '0' && s[i] <= '9') || s[i] == '/'))
    {
      cpt++;
      i++;
    }
  return (cpt);
}

char            *get_next_word(char *word, char *str, int i)
{
  int           j;

  j = 0;
  while ((str[i] >= 'a' && str[i] <= 'z')
         || (str[i] >= 'A' && str[i] <= 'Z') || str[i] == '_'
         || (str[i] >= '0' && str[i] <= '9') || str[i] == '/')
    word[j++] = str[i++];
  word[j] = '\0';
  return (word);
}

char            **my_strtowordtab(char *str)
{
  int           i;
  int           w;
  char          **tab;

  i = -1;
  w = 0;
  tab = malloc(sizeof(char *) * (get_nb_words(str) + 1));
  while (str && str[++i])
    {
      if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')
          || (str[i] >= '0' && str[i] <= '9') || str[i] == '/'  || str[i] == '_')
        {
          tab[w] = malloc(sizeof(char) * (get_nb_char(str, i) + 1));
          tab[w] = get_next_word(tab[w], str, i);
	  i = i + get_nb_char(str, i);
	  w++;
        }
    }
  tab[w] = NULL;
  return (tab);
}