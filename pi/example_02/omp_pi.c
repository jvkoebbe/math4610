#include <stdio.h>
#include <omp.h>

static long num_steps = 10000000;
double step;

#define NUM_THREADS 16

int main()
{
  int i;
  int nthreads;
  double pi;
  //
  // the variable sum has been promoted to an array to provide a place for each
  // of the threads
  // --------------
  //
  double sum[NUM_THREADS];
  double startTime, endTime, runTime;
  step = 1.0 / (double) num_steps;
  omp_set_num_threads(NUM_THREADS);
  startTime = omp_get_wtime();
  #pragma omp parallel
  {
    //
    // in using openmp, the following variables are declared inside the C
    // code block and this means they are local - the values are kept in the
    // thread's memory stack
    // ---------------------
    //
    int i;
    int id;
    int nthrds;
    double x;
    //
    // each thread will get a copy of this value for local storage - this gives
    // an index to use the appropriate location in the sum array which is shared
    // -------------------------------------------------------------------------
    //
    id = omp_get_thread_num();
    //
    // this code will communicate the total number of threads to the individual
    // threads in the parallel region, a copy of the variable nthrds is needed
    // to keep track of the data needed to compute a portion of the integral.
    // ---------------------------------------------------------------------- 
    //
    nthrds = omp_get_num_threads();
    //
    // this line verifies the actual number of threads used in the computation.
    // even if you want to specify the number of threads used, the environment
    // variables may override the number of threads you really want to use. So
    // this line takes one of the threads (any of the threads will do the trick)
    // and asks for the actual number of threads
    // -----------------------------------------
    // 
    if(id == 0) nthreads = nthrds;
    //
    // finally, we get to the loop that is doing the work
    //
    // 1. the look uses the thread id as an index for the array of sums
    // 2. the sum for each of the thread ids is initialized to zero.
    // 3. the number of steps range is tested and the variable i is incremented
    //    by nthreads.
    //
    // note that the increment in i by nthreads is interlacing the contributions
    // and will be correct only due to the fact that the the form of the
    // midpoint rule is the same on each interval.
    //
    for(i=id, sum[id]=0.0; i<num_steps; i=i+nthrds)
    {
      x = ( i + 0.5 ) * step;
      sum[id] += 4.0 / ( 1.0 + x * x );
    }
    //
    // this is a loop to sum up the values for the integral obtained in the
    // parallel block - note that the following loop uses the loop limit of
    // nthreads which is a shared variable due to where it is declared.
    // ----------------------------------------------------------------
    //
    for(i=0, pi = 0.0; i<nthreads; i++) pi += sum[i] * step;
  }
  endTime = omp_get_wtime();
  runTime = endTime - startTime;
  printf("\n   time = %e    pi = %e\n\n", runTime, pi);

}
