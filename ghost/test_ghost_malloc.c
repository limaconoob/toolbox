#include <stdio.h>
#include <stdlib.h>

char *bonjour()
{
  char *str;
  char *tmp;

  str = (char*)malloc(25);
  str[24] = '\0';
  int i = -1;
  while (++i < 24)
  { str[i] = 'a'; }
  tmp = str;
  free(str);
  return (tmp);
}

int main(void)
{
  char *str = bonjour();
  printf("%s", str);
  return (0);
}
