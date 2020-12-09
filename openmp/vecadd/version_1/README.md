# Example Description: Version 1.

In this example, the basic routine for adding two vectors is treated. The
example is very simple, but will provide a baseline for computer timing of
routines. In the rest of the examples, we will try to get more performance from
the code using parallelism and compiler flags and directives. The choice in this
set of examples is OpenMP.

## The Code for this Example:

Look for the second directive in the code for the for loop.

        #include <stdio.h>
        #include <stdlib.h>
        //
        // include the timing header file
        // ------------------------------
        //
        #include <time.h>

        int main(int argc, char *argv[])
        {
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
          // to see any clock time, you need to run this a bunch of times
          // ------------------------------------------------------------
          //
          for(int k=0; k<10000; k++)
          {
            //
            // now, add-em
            // -----------
            //
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
          // print out a few values at the beginning and end of the arrays
          // -------------------------------------------------------------
          //
          for(int i=0; i<3; i++)
          {
            printf("i = %d,   x = %d,   y = %d,   z = %d,    \n", i, x[i], y[i], z[i]);
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
          // all done
          // --------
          //
          return 0;
          //
        }

This is included in the file **vecadd.c**.

## Compiling Instructions:

 The following is a vanilla compilation with no opnemp api pieces included.

        koebbe% gcc -o vecadd vecadd.c
        koebbe% ./vecadd

   The output from this pair of commands is the following:

        i = 0,   x = 0,   y = -1,   z = -1,    
        i = 1,   x = 1,   y = 1,   z = 2,    
        i = 2,   x = 2,   y = -1,   z = 1,    
        i = 99997,   x = 99997,   y = 1,   z = 99998,    
        i = 99998,   x = 99998,   y = -1,   z = 99997,    
        i = 99999,   x = 99999,   y = 1,   z = 100000,    

        CPU Time Used:   2.687000e+00.

There are some important things to note about the code.

## Comments on the Code:

1. The example of adding vectors is presented since it is easy and does not need
   shared memory to produce a correct result. The input vectors are not changed
   and each of the operations is independent.

2. In the parallel version, each computation only involves the ith component.

3. Note that the loop is repeated a large number of times. This is so that the
   code will register some actual CPU time. If you run the loop, most newer
   computers will run this so fast that it appears there is no time off the
   clock.

4. In many complex simulation codes, vector additions are done many, many times.
   So, looping over the vector addition may mimic the time needed to run a
   complicated simulation.

## Assumptions:

1. There is no need to compile a parallel version of the code since the code
   only involves sequential execution.. 

<hr>

<a href="../README.md"> Previous </a>
  &nbsp;&nbsp; | &nbsp;&nbsp;
<a href="../README.md"> Table of Contents  </a>
  &nbsp;&nbsp; | &nbsp;&nbsp;
<a href="../version_2/README.md"> Next </a>

<hr>

