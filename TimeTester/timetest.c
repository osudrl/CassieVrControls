#include <stdio.h>   
#include <time.h>   
#include <inttypes.h>

long int timeDiffMillis(struct timespec* timeA_p, struct timespec* timeB_p)
{
  return (((timeA_p->tv_sec * 1000000000) + timeA_p->tv_nsec) -
           ((timeB_p->tv_sec * 1000000000) + timeB_p->tv_nsec)) / 1000000;
}

int main(int argc, char **argv)
{
  struct timespec start, end;
  clock_gettime(CLOCK_MONOTONIC, &start);

  char input[50];
  scanf("%50s",input);

  clock_gettime(CLOCK_MONOTONIC, &end);

  long int intTE  = timeDiffMillis(&end, &start);

  printf("This much time elapsed: %lu", intTE);

  return 0; 
}