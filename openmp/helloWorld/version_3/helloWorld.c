#include <stdio.h>
#include <stdlib.h>
#ifdef _OPENMP
  #include <omp.h>
#else
  #define omp_get_thread_num() 0
#endif

int main(int argc, char *argv[])
{
  printf("Hello World!\n");
  printf("Hello world from thread %d\n", omp_get_thread_num());
  printf("I am sequential now.\n");
  return 0;
}
