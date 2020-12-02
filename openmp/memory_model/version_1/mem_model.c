#include <stdio.h>
#include <stdlib.h>
#ifdef _OPENMP
  #include <omp.h>
#else
  #define omp_get_thread_num() 0
#endif

int main(int argc, char *argv[])
{
  printf("\nBefore the parallel region in the code\n\n");
  //
  // set some variables before going parallel
  // ----------------------------------------
  //
  int x = 5;
  int y = 20;
  //
  // print out what is going on before the parallel section of this code
  // -------------------------------------------------------------------
  //
  printf("    x = %d     y = %d     z = %d   from thread %d\n\n",
               x, y, -1, omp_get_thread_num());
  //
  // head into a parallel region to see how storage works
  // ----------------------------------------------------
  //
  #pragma omp parallel private(x) firstprivate(y)
  {
    int x = 10;
    printf("    x = %d    y = %d     z = %d   from thread %d\n",
               x, y, -2, omp_get_thread_num());
    int z = x + y;
    printf("    x = %d    y = %d     z = %d   from thread %d\n",
               x, y, z, omp_get_thread_num());
    y = 30;
    printf("    x = %d    y = %d     z = %d   from thread %d\n",
               x, y, z, omp_get_thread_num());
    printf("\n");
  }
  //
  // print out the values outside the parallel regions
  // -------------------------------------------------
  //
  printf("    x = %d    y = %d     z = %d   from thread %d\n\n",
             x, y, -3, omp_get_thread_num());
  //
  printf("I am done with parallel for now.\n\n");
  //
  return 0;
}
