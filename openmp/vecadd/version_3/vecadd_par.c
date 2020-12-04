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
  #define omp_get_thread_num() 0
  #define omp_set_num_threads(n) 1
#endif

int main(int argc, char *argv[])
{
  printf("\nBefore going parallel\n\n");
  //
  // setup some storage for the vector addition
  // ------------------------------------------
  //
  int n = 100000;
  int x[n];
  int y[n];
  int z[n];
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
  x[0] = 0;
  y[0] = -1;
  for(int i=1; i<n; i++)
  {
    x[i] = i;
    y[i] = -y[i-1];
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
for(int k=0; k<1000; k++) {

omp_set_num_threads(4);
#pragma omp parallel
{
  #pragma omp for
  for(int i=0; i<n; i++)
  {
    z[i] = x[i] + y[i];
  }
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
  for(int i=0; i<3; i++)
  {
    printf("i =    %d,   x = %d,   y = %d,   z = %d,    \n", i, x[i], y[i], z[i]);
  }
  for(int i=n-3; i<n; i++)
  {
    printf("i = %d,   x = %d,   y = %d,   z = %d,    \n", i, x[i], y[i], z[i]);
  }
  //
  // print out the cpu time used
  // ---------------------------
  //
  printf("\nCPU Time Used:   %e.\n", cpu_time_used);
  //
  // last message
  // ------------
  //
  printf("\nI am done with parallel for now.\n\n");
  //
  return 0;
}
