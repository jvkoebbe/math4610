//
// Matrix Multiplication Loop Comparison
//
// written by: Joe Koebbe
//
// description: The code, written in C has been written to compare the cpu-time
//              for 6 reoordering of the indices in the formula for the product.
//              Due to the way storage works, there are slightly different
//              execution times for the loops when reordered. The code simply
//              copied the lines of code and then reordered the indices and then
//              executed nested loops to computer a matrix product. The results
//              are printed after the execution.
//             
// include some header files
// -------------------------
//
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main()
{


  int n=256;
  double A[n][n], B[n][n], C[n][n];
  double startit, endit, runit;

  startit = omp_get_wtime();
  for(int i=0; i<n; i++)
  {
    for(int j=0; j<n; j++)
    {
      for(int k=0; k<n; k++)
        {
          C[i][j] = C[i][j] + A[i][k] * B[k][j];
        }
    }
  }
  endit = omp_get_wtime();
  runit = endit - startit;
  printf("i,j,k-loops time = %f\n", runit);

  startit = omp_get_wtime();
  for(int j=0; j<n; j++)
  {
    for(int i=0; i<n; i++)
    {
      for(int k=0; k<n; k++)
        {
          C[i][j] = C[i][j] + A[i][k] * B[k][j];
        }
    }
  }
  endit = omp_get_wtime();
  runit = endit - startit;
  printf("j,i,k-loops time = %f\n", runit);

  startit = omp_get_wtime();
  for(int i=0; i<n; i++)
  {
    for(int k=0; k<n; k++)
    {
      for(int j=0; j<n; j++)
        {
          C[i][j] = C[i][j] + A[i][k] * B[k][j];
        }
    }
  }
  endit = omp_get_wtime();
  runit = endit - startit;
  printf("i,k,j-loops time = %f\n", runit);

  startit = omp_get_wtime();
  for(int k=0; k<n; k++)
  {
    for(int i=0; i<n; i++)
    {
      for(int j=0; j<n; j++)
        {
          C[i][j] = C[i][j] + A[i][k] * B[k][j];
        }
    }
  }
  endit = omp_get_wtime();
  runit = endit - startit;
  printf("k,i,j-loops time = %f\n", runit);

  startit = omp_get_wtime();
  for(int k=0; k<n; k++)
  {
    for(int j=0; j<n; j++)
    {
      for(int i=0; i<n; i++)
        {
          C[i][j] = C[i][j] + A[i][k] * B[k][j];
        }
    }
  }
  endit = omp_get_wtime();
  runit = endit - startit;
  printf("k,j,i-loops time = %f\n", runit);

  startit = omp_get_wtime();
  for(int j=0; j<n; j++)
  {
    for(int k=0; k<n; k++)
    {
      for(int i=0; i<n; i++)
        {
          C[i][j] = C[i][j] + A[i][k] * B[k][j];
        }
    }
  }
  endit = omp_get_wtime();
  runit = endit - startit;
  printf("j,k,i-loops time = %f\n", runit);

}
