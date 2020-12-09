# Example Description: Version 2.

As an extension of the basic routine for adding two vectors we will compile the
same code using compiler optimization flags. Most compilers have flags for using
the compiler to optimize the performance of a code. In **gcc** the flag to use
is the **-O** flag on the command line. The actual commands are shown below. The
actual code has not changed from the basic version and is repeated for
completeness.

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

This is included in the file **vecadd_Ox.c**.

## Compiling Instructions:

 The following is a **-O1** compilation with no opnemp api pieces included.

        koebbe% gcc -O1 -o vecadd_O1 vecadd_Ox.c
        koebbe% ./vecadd_O1

   The output from this pair of commands is the following:

        i = 0,   x = 0,   y = -1,   z = -1,    
        i = 1,   x = 1,   y = 1,   z = 2,    
        i = 2,   x = 2,   y = -1,   z = 1,    
        i = 99997,   x = 99997,   y = 1,   z = 99998,    
        i = 99998,   x = 99998,   y = -1,   z = 99997,    
        i = 99999,   x = 99999,   y = 1,   z = 100000,    

        CPU Time Used:   6.090000e-01.

 Students should try:

        koebbe% gcc -O2 -o vecadd_O2 vecadd_Ox.c
        koebbe% ./vecadd_O2

 and

        koebbe% gcc -O3 -o vecadd_O3 vecadd_Ox.c
        koebbe% ./vecadd_O2

 to see if there is any benefit to including these flags. In an informal test of
 these codes, it appears that as the level increases the CPU time is reduced.

 For more on available optimization flags click on the following link:

[gcc optimization documentation](https://gcc.gnu.org/onlinedocs/gcc/Optimize-Options.html)

There are some important things to note about the code.

## Comments on the Code:

1. You can choose different levels for the O-flag. These start with **-O1** as
   the level of optimization.

2. You can choose levels of 1, 2, or 3. Each of these provides a higher level of
   optimization as the value increases.

3. These optimizations are done independently of any OpenMP API information.

4. Be careful with this optimization. In some cases, the optimization will not
   provide correct results.

5. Another issue with the **-Ox** flag is that the compiler will try to
   optimize the entire code. OpenMP allows the user to target optimization in
   a code.

## Assumptions:

1. It is assumed that we will need to time the code. So, the **time.h** header
   is included in the file so that the **clock()** can be used to estimate the
   CPU time used to execute the code.

<hr>

<a href="../version_1/README.md"> Previous </a>
  &nbsp;&nbsp; | &nbsp;&nbsp;
<a href="../README.md"> Table of Contents  </a>
  &nbsp;&nbsp; | &nbsp;&nbsp;
<a href="../version_3/README.md"> Next </a>

<hr>
