# Example Description: Version 3.

In this version of the vector addition operation we will introduce OpenMP
directives to try to speed up execution of the loop that adds the components
of two vectors. The parallel construct used to optimize performance of a for
loop in a code written in C.

        #pragma omp for

This directive must appear in a parallel region. There are no braces in this
case since the directive is actually inside a parallel region in the code. There
is a shortcut to this that we will try out in another version of this exercise.

The first thing to notice is that a **printf** is inserted in the code to make
sure the various threads are actually doing something. In a production level
code this should not be included unless you are debugging things. Print
statements and the like take a lot of time.

Note that without the **omp for** directive each thread will execute all of the
code in the parallel region. With the directive, OpenMP will optimize the for
loop.

## The Code for this Example:

Look for the second directive in the code for the for loop.

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
        //
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
                //printf("thread = %d\n", omp_get_thread_num());
                //
              }

            } // end of #pragma omp parallel

          } // end of loop over the number of vector sums to computer
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

This is included in the file **vecadd_omp.c**.

## Compiling Instructions:

Type in the commands:

1. A vanilla compilation with no opnemp api pieces included is obtained when the
   following commands are used.

        koebbe% gcc -o vecadd_vanilla vecadd_omp.c
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
            *    <- this indicates a lot of outpout lines
            *
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

        koebbe% gcc -fopenmp -o vecadd_omp vecadd_omp.c
        koebbe% ./vecadd_omp.exe

   In testing the code for whether or not the threads are being used, the vector
   size was set to 3. The output from this pair of commands is the following.
   Notice the thread numbers are 0 through 2, one thread for each of the
   components.

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
        thread = 2
        thread = 0
        thread = 1
        thread = 0
        thread = 2
        thread = 1
            *
            *    <- this indicates a lot of outpout lines
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

3. The code without enabling OpenMP and **printf** statment results in the
   following output for the non-omp case.

        Before going parallel

        i =    0,   x = 0,   y = -1,   z = -1,    
        i =    1,   x = 1,   y = 1,   z = 2,    
        i =    2,   x = 2,   y = -1,   z = 1,    
        i = 99997,   x = 99997,   y = 1,   z = 99998,    
        i = 99998,   x = 99998,   y = -1,   z = 99997,    
        i = 99999,   x = 99999,   y = 1,   z = 100000,    

        CPU Time Used:   2.500000e-01.

        I am done with parallel for now.

4. The code without the **printf** statment and with OpenMP enabled results in
   the following output for

        Before going parallel

        i =    0,   x = 0,   y = -1,   z = -1,    
        i =    1,   x = 1,   y = 1,   z = 2,    
        i =    2,   x = 2,   y = -1,   z = 1,    
        i = 99997,   x = 99997,   y = 1,   z = 99998,    
        i = 99998,   x = 99998,   y = -1,   z = 99997,    
        i = 99999,   x = 99999,   y = 1,   z = 100000,    

        CPU Time Used:   1.421000e+00.

        I am done with parallel for now.

## Comments on the Code:

1. The threads are printed in this case to make sure the code is setting up the
threads. In the vanilla case, there is only one thread and that is thread 0. The
parallel code will actually use a total of three threads when n=3.

2. This code was included to make sure the two versions would run and produce
meaningful output. The actual parallel region is actually very small.

## Assumptions:

1. The **-fopenmp** includes the needed information to use bits and pieces of
   **omp.h**.

2. The worst result is the full run with OpenMP enabled. The reason for this is
   the overhead for doing the work of setting up the threads and doing the very
   simple computation of adding two numbers cannot be overcome in this code.

3. The one thing we do know in this setting is that all of the threads are being
   used when the code is run with OpenMP enabled.

<hr>

<a href="../version_2/README.md"> Previous </a>
  &nbsp;&nbsp; | &nbsp;&nbsp;
<a href="../README.md"> Table of Contents  </a>
  &nbsp;&nbsp; | &nbsp;&nbsp;
<a href="../version_4/README.md"> Next </a>

<hr>
