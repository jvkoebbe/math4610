#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//
// the usual default stuff to compile in both sequential and parallel versions
// ---------------------------------------------------------------------------
//
#ifdef _OPENMP
  #include <omp.h>
#else
  #define omp_get_thread_num() 1
#endif

int main(int argc, char *argv[])
{
  printf("\nBefore going parallel\n\n");
  //
  // setup some storage for the vector addition
  // ------------------------------------------
  //
  int n = 10000;
  double x[n];
  double y[n];
  double z[n];
  //
  // time variables for performance issues
  // -------------------------------------
  //
  clock_t start, end;
  double cpu_time_used;
  //
  // put some values in the vectors
  // ------------------------------
  //
  for(int i=0; i<n; i++)
  {
    x[i] = rand();
    y[i] = rand();
  }
  //
  // get the start time
  // ------------------
  //
  start = clock();
  //
  // now, add-em
  // -----------
  //
#pragma omp parallel
{
  #pragma parallel for
  for(int i=0; i<n; i++)
  {
    z[i] = x[i] + y[i];
  }
}
  //
  // get the end time from the work
  // ------------------------------
  //
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  //
  // print out a few values at both ends
  // -----------------------------------
  //
  for(int i=0; i<10; i++)
  {
    printf("i =    %d,   x = %e,   y = %e,   z = %e,    \n", i, x[i], y[i], z[i]);
  }
  for(int i=n-11; i<n; i++)
  {
    printf("i = %d,   x = %e,   y = %e,   z = %e,    \n", i, x[i], y[i], z[i]);
  }
  //
  // print out the cpu time used
  // ---------------------------
  //
  printf("\n\nCPU Time Used:   %e.\n\n", cpu_time_used);
  //
  // last message
  // ------------
  //
  printf("\nI am done with parallel for now.\n\n");
  //
  return 0;
}
