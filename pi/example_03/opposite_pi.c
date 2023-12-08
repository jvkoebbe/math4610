#include <stdio.h>
#include <omp.h>

static long num_steps = 1000000;
double step;

int main()
{
  //
  // set up storage in variables for the code
  //
  int i;
  double x;
  double pi;
  double sum = 0.0;
  double startTime, endTime, runTime;

  step = 1.0 / (double) num_steps;

  startTime = omp_get_wtime();
    
  for(i=num_steps-1; i>=0; i--)
  {
    x = ( i + 0.5 ) * step;
    sum = sum + 4.0 / ( 1.0 + x * x );
  }
  pi = step * sum;
  //
  endTime = omp_get_wtime();
  runTime = endTime - startTime;
  //
  // output for the run
  // ------------------
  //
  printf("\n pi with %ld steps is %lf in %lf seconds\n\n", num_steps, pi, runTime);

}
