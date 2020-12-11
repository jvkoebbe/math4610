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
            for(int i=0; i<n; i++)
            {
              isum = isum + x[i] * y[i];
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

This is included in the file **dotprd.c**.

## Compiling Instructions:

 The following is a vanilla compilation with no opnemp api pieces included.

        koebbe% gcc -o dotprd dotprd.c
        koebbe% ./dotprd.exe

   The output from this pair of commands is the following:

        dot product value = 50000
        CPU Time Used:   2.187000e+00.


There are some important things to note about the code.

## Comments on the Code:

1. The example of the dot product of two vectors is presented since it is easy
   but needs shared memory to produce a correct result. The input vectors are
   not changed and each of the operations is independent. However, the sum is
   updated each time through the loop.

2. In the parallel version, each computation only involves reading the ith
   component of a vector, while the update requires writing to a location in
   memory using different threads.

3. Note that the loop is repeated a large number of times. This is so that the
   code will register some actual CPU time. If you run the loop, most newer
   computers will run this so fast that it appears there is no time off the
   clock.

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
