# Example Description: Version 2.

In this example, we will look at parallelization of a loop. The operation
involves the addition of two vectors that are large in the number of entries in
the vector. This is a simple component-wise addition and does not require the
use of any shared variables. The code uses the following directive inside a
parallel region. This is

        #pragma omp for

There are no braces in this case since the directive is actually inside the
parallel region in the code.

## The Code for this Example:

Look for the second directive in the code for the for loop.

        #include <stdio.h>
        #include <stdlib.h>
        #include <time.h>
        //
        // the usual default stuff to compile in both sequential and parallel
        // versions
        // ---------
        //
        #ifdef _OPENMP
          #include <omp.h>
        #else
          #define omp_get_thread_num() 0
        #endif

        int main(int argc, char *argv[])
        {
          printf("\nBefore going parallel\n\n");
          //
          // setup some storage for the vector addition
          // ------------------------------------------
          //
          int n = 10;
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

        #pragma omp parallel
        {
          #pragma omp for
          for(int i=0; i<n; i++)
          {
            z[i] = x[i] + y[i];
        //
        // the next line prints out different thread numbers as they are
        // encountered
        // -----------
        //
        printf("thread = %d\n", omp_get_thread_num());
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

This is included in the file **vecadd_par.c**.

## Compiling Instructions:

Type in the commands:

1. A vanilla compilation with no opnemp api pieces included.

        koebbe% gcc -o vecadd_vanilla vecadd_par.c
        koebbe% ./vecadd_vanilla

   The output from this pair of commands is the following:

        Before going parallel

        thread = 0
        thread = 0
        thread = 0
        thread = 0
        thread = 0
        thread = 0
            *
            *
            *
        thread = 0
        thread = 0
        thread = 0
        thread = 0
        thread = 0
        thread = 0
        thread = 0
        thread = 0
        thread = 0
        thread = 0
        thread = 0
        thread = 0
        thread = 0
        thread = 0
        thread = 0
        thread = 0
        thread = 0
        thread = 0
        thread = 0
        i =    0,   x = 0,   y = -1,   z = -1,    
        i =    1,   x = 1,   y = 1,   z = 2,    
        i =    2,   x = 2,   y = -1,   z = 1,    
        i = 0,   x = 0,   y = -1,   z = -1,    
        i = 1,   x = 1,   y = 1,   z = 2,    
        i = 2,   x = 2,   y = -1,   z = 1,    

        CPU Time Used:   0.000000e+00.

        I am done with parallel for now.

2. A compilation with opnemp api pieces included.

        koebbe% gcc -fopenmp -o vecadd_omp vecadd_par.c
        koebbe% ./vecadd_par.exe

   The output from this pair of commands is the following:

        Before going parallel

        thread = 0
        thread = 2
        thread = 1
        thread = 2
        thread = 0
        thread = 1
        thread = 2
        thread = 0
        thread = 1
        thread = 2
        thread = 0
        thread = 1
        thread = 2
        thread = 0
        thread = 1
        thread = 2
        thread = 0
        thread = 2
        thread = 1
        thread = 0
        thread = 2
        thread = 1
        thread = 0
        thread = 1
            *
            *
            *
        thread = 2
        thread = 0
        thread = 2
        thread = 0
        thread = 2
        thread = 1
        thread = 0
        thread = 2
        thread = 1
        thread = 0
        thread = 2
        thread = 1
        thread = 0
        thread = 1
        thread = 2
        thread = 0

        i =    0,   x = 0,   y = -1,   z = -1,    
        i =    1,   x = 1,   y = 1,   z = 2,    
        i =    2,   x = 2,   y = -1,   z = 1,    
        i = 0,   x = 0,   y = -1,   z = -1,    
        i = 1,   x = 1,   y = 1,   z = 2,    
        i = 2,   x = 2,   y = -1,   z = 1,    

        CPU Time Used:   4.370000e-01.

        I am done with parallel for now.

There are some important things to note about the code.

## Comments on the Code:

1. The threads are printed in this case to make sure the code is setting up the
threads. In the vanilla case, there is only one thread and that is thread 0. The
parallel code will actually use a total of three threads when n=3.

2. This code was included to make sure the two versions would run and produce
meaningful output. The actual parallel region is actually very small.

## Assumptions:

1. There is no need to compile the vanilla (sequential) version of the code is
only necessary to show how variables are handled in a standard C code. 

2. The **-fopenmp** includes the needed information to use bits and pieces of
   **omp.h**.

3. Note that the output from running the executables in the above example are
   different. Students should try additional examples.
