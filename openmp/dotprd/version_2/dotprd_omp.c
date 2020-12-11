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
#endif

int main(int argc, char *argv[])
{
  //
  // setup some storage for the vector addition
  // ------------------------------------------
  //
  int n = 100000;
  int x[n];
  int y[n];
  int isum;
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
  // to see any clock time, you need to run this a bunch of times
  // ------------------------------------------------------------
  //
  for(int k=0; k<10000; k++)
  {
    //
    // now, add-em
    // -----------
    //
    isum = 0;
    #pragma omp parallel for schedule(static)
    for(int i=0; i<n; i++)
    {
      #pragma omp critical
      {
      isum = isum + x[i] * y[i];
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
  // print out a few values at the beginning and end of the arrays
  // -------------------------------------------------------------
  //
  printf("dot product value = %d", isum);
  //
  // print out the cpu time used
  // ---------------------------
  //
  printf("\nCPU Time Used:   %e.\n", cpu_time_used);
  //
  // all done
  // --------
  //
  return 0;
  //
}
