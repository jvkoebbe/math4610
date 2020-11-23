#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main(int argc, char *argv[])
{
  printf("Hello World!\n");
  #pragma omp parallel
  {
    printf("Hello world from thread %d\n", omp_get_thread_num());
  }
  printf("I am sequential now.\n");
  return 0;
}
