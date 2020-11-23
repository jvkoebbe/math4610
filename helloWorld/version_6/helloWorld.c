#include <stdio.h>
#include <stdlib.h>
#ifdef _OPENMP
  #include <omp.h>
#else
  #define omp_get_thread_num() 1
#endif

int main(int argc, char *argv[])
{
  printf("Hello World!\n");
  //
  // the next function call will set the number of threads used to 5. Note that
  // this has nothing to do with the number of processors
  // ----------------------------------------------------
  //
  omp_set_num_threads(5);
  //
  // parallel directive applied to a block of code
  // ---------------------------------------------
  //
  #pragma omp parallel
  {
    printf("Hello world from thread %d\n", omp_get_thread_num());
  //}
  //
  // parallel directive applied to a block of code
  // ---------------------------------------------
  //
  #pragma omp barrier
  //{
  //#pragma omp parallel

    printf("I am listening via thread %d\n", omp_get_thread_num());
  }
  //
  // done with the parallel directive
  // --------------------------------
  printf("I am sequential now.\n");
  //
  // done
  // ----
  //
  return 0;
  //
}
