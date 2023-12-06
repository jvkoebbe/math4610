#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#ifdef _OPENMP
  #include <omp.h>
#else
  #define omp_get_num_threads() 0
  #define omp_set_num_threads(int) 0
  #define omp_get_thread_num() 0
#endif

#define matrix_dimension 10

int n = matrix_dimension;
float ynrm;

int main()
{
  float A[n][n];
  float v0[n];
  float v1[n];
  float y[n];
  //
  // create a matrix
  //
  srand((unsigned int)(time(NULL)));
  float a = 5.0;
  for(int i=0; i<n; i++)
  {
    for(int j=0; j<n; j++)
    {
      A[i][j] = ((float)rand()/(float)(RAND_MAX) * a);
    }
    v0[i] = ((float)rand()/(float)(RAND_MAX) * a);
  }
  //
  // modify the diagonal entries for diagonal dominance
  // --------------------------------------------------
  //
  for(int i=0; i<n; i++)
  {
    float sum = 0.0;
    for(int j=0; j<n; j++)
    {
      sum = sum + fabs(A[i][j]);
    }
    A[i][i] = A[i][i] + sum;
  }
  //
  // generate a vector of ones
  // -------------------------
  //
  for(int j=0; j<n; j++)
  {
    v0[j] = 1.0;
  }
//
// power iteration test
// --------------------
//
  float tol = 0.0000001;
  float error = 10.0 * tol;
  float lam1, lam0;
  int maxiter = 100;
  int iter = 0;
  //
  // loop starts here for the power method
  // -------------------------------------
  //
  while ( error > tol && iter < maxiter ) 
  {
    for(int i=0; i<n; i++)
    {
      y[i] = 0;
      for(int j=0; j<n; j++)
      {
        y[i] = y[i] + A[i][j] * v0[j];
      }
    } 
    //
    // compute the norm of the output
    // ------------------------------
    //
    ynrm = 0.0;
    for(int i=0; i<n; i++)
    {
      ynrm = ynrm + y[i] * y[i];
    }
    ynrm = sqrt(ynrm);
    //
    // normalize the vector from the computation above
    // -----------------------------------------------
    //
    for(int i=0; i<n; i++)
    {
      v1[i] = y[i] / ynrm;
    } 
    //
    // compute the next product
    // ------------------------
    //
    for(int i=0; i<n; i++)
    {
      y[i] = 0.0;
      for(int j=0; j<n; j++)
      {
        y[i] = y[i] + A[i][j] * v1[j];
      }
    }
    //
    // the following is an approximation of the eigenvalue using the Rayleigh
    // rayleigh quotient
    // -----------------
    //
    lam1 = 0.0;
    for(int i=0; i<n; i++)
    {
      lam1 = lam1 + v1[i] * y[i];
    }
    //
    // error computations and updates for the next iteration
    // ------------------------------------------------------
    //
    error = fabs(lam1-lam0);
    lam0 = lam1;
    for(int i=0; i<n; i++)
    {
      v0[i] = v1[i];
    }
    //
    // update the iteration counter
    // ----------------------------
    //
    iter++;
  //
  // end of loop
  // -----------
  }

  printf("in %d iterations, eigenvalue = %f\n", iter, lam1);
}
