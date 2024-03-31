#include <stdlib.h>
#include <stdio.h>

int Debug_level = 0;

#define DEBUGON
#ifdef DEBUGON
#define DEBUG(level, fmt, ...) \
  if (Debug_level >= level)    \
  (fprintf(stderr, fmt, __VA_ARGS__))
#else DEBUG(level, fmt, ...)
#endif

int sum(int x, int y, int z)
{
  char c = 2;
  int a = 0;

  DEBUG(2, "x=%d\n", x);
  DEBUG(2, "y=%d\n", y);
  DEBUG(2, "z=%d\n", z);
  DEBUG(2, "a=%ld\n", (long)a);

  a = 5;

  DEBUG(3, "a=%d\n", a);

  return (c + x + y + z + a) / 3;
}

int main(int argc, char *argv[])
{
  int i, j, k;
  int result;
  if (argv[4])
    Debug_level = atoi(argv[4]);

  DEBUG(1, "Number of parameters = %d\n", argc);

  if (argc < 4)
  {
    printf("Please specify three numbers as parameters and Debug mode optional 4-ths.\n");
    exit(1);
  }

  i = atoi(argv[1]);

  DEBUG(1, "i=%d\n", i);

  j = atoi(argv[2]);

  DEBUG(1, "j=%d\n", j);

  k = atoi(argv[3]);

  DEBUG(1, "k=%d\n", k);

  result = sum(i, j, 12) + sum(j, k, 19) + sum(i, k, 13);

  printf("%d\n", result);

  return 0;
}
