#include <unistd.h>

int main(void)
{
  write(1, "\e[6n", 5);
  write(1, "\n", 1);
  return(0);
}
