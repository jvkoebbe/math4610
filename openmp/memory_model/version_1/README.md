# Example Description: Version 1.

This example includes examples of how the OpenMP memory model works. The first
example shows how private variables are used in parallel regions in a code. The
code included looks at a few simple cases and prints out the values  






**gcc** command will include information from **omp.h**.

## The Code for this Example:

        #include <stdio.h>
        #include <stdlib.h>
        #ifdef _OPENMP
          #include <omp.h>
        #else
          #define omp_get_thread_num() 1
        #endif

        int main(int argc, char *argv[])
        {
          printf("\nBefore the parallel region in the code\n\n");
          //
          // set some variables before going parallel
          // ----------------------------------------
          //
          int x = 5;
          int y = 20;
          //
          // print out what is going on before the parallel section of this code
          // -------------------------------------------------------------------
          //
          printf("    x = %d     y = %d     z = %d   from thread %d\n\n",
                       x, y, -1, omp_get_thread_num());
          //
          // head into a parallel region to see how storage works
          // ----------------------------------------------------
          //
          #pragma omp parallel private(x) firstprivate(y)
          {
            x = 10;
            printf("    x = %d    y = %d     z = %d   from thread %d\n",
                       x, y, -2, omp_get_thread_num());
            int z = x + y;
            printf("    x = %d    y = %d     z = %d   from thread %d\n",
                       x, y, z, omp_get_thread_num());
            y = 30;
            printf("    x = %d    y = %d     z = %d   from thread %d\n",
                       x, y, z, omp_get_thread_num());
            printf("\n");
          }
          //
          // print out the values outside the parallel regions
          // -------------------------------------------------
          //
          printf("    x = %d    y = %d     z = %d   from thread %d\n\n",
                     x, y, -3, omp_get_thread_num());
          //
          printf("I am done with parallel for now.\n\n");
          //
          return 0;
        }
        
This is included in the file **mem_model.c**.

## Compiling Instructions:

Type in the commands:

1. A vanilla compilation with no opnemp api pieces included.

        koebbe% gcc -o mem_model_vanilla mem_model.c
        koebbe% ./mem_model_vanilla

   The output from this pair of commands is the following:

        Before the parallel region in the code

            x = 5     y = 20     z = -1   from thread 1

            x = 10    y = 20     z = -2   from thread 1
            x = 10    y = 20     z = 30   from thread 1
            x = 10    y = 30     z = 30   from thread 1

            x = 10    y = 30     z = -3   from thread 1

        I am done with parallel for now.


2. A compilation with opnemp api pieces included.

        koebbe% gcc -fopenmp -o mem_model_omp mem_model.c
        koebbe% ./mem_model_omp.exe

   The output from this pair of commands is the following:

        Before the parallel region in the code

            x = 5     y = 20     z = -1   from thread 0

            x = 10    y = 20     z = -2   from thread 2
            x = 10    y = 20     z = 30   from thread 2
            x = 10    y = 30     z = 30   from thread 2

            x = 10    y = 20     z = -2   from thread 5
            x = 10    y = 20     z = -2   from thread 8
            x = 10    y = 20     z = -2   from thread 4
            x = 10    y = 20     z = -2   from thread 6
            x = 10    y = 20     z = -2   from thread 9
            x = 10    y = 20     z = -2   from thread 0
            x = 10    y = 20     z = 30   from thread 5
            x = 10    y = 20     z = 30   from thread 8
            x = 10    y = 20     z = -2   from thread 7
            x = 10    y = 20     z = -2   from thread 1
            x = 10    y = 20     z = -2   from thread 10
            x = 10    y = 20     z = -2   from thread 3
            x = 10    y = 20     z = 30   from thread 4
            x = 10    y = 20     z = -2   from thread 11
            x = 10    y = 20     z = 30   from thread 6
            x = 10    y = 20     z = 30   from thread 9
            x = 10    y = 20     z = 30   from thread 0
            x = 10    y = 30     z = 30   from thread 5
            x = 10    y = 30     z = 30   from thread 8
            x = 10    y = 20     z = 30   from thread 7
            x = 10    y = 20     z = 30   from thread 1
            x = 10    y = 20     z = 30   from thread 10
            x = 10    y = 20     z = 30   from thread 3
            x = 10    y = 30     z = 30   from thread 4
            x = 10    y = 20     z = 30   from thread 11
            x = 10    y = 30     z = 30   from thread 6
            x = 10    y = 30     z = 30   from thread 9
            x = 10    y = 30     z = 30   from thread 0


            x = 10    y = 30     z = 30   from thread 7
            x = 10    y = 30     z = 30   from thread 1
            x = 10    y = 30     z = 30   from thread 10
            x = 10    y = 30     z = 30   from thread 3

            x = 10    y = 30     z = 30   from thread 11








            x = 5    y = 20     z = -3   from thread 0

        I am done with parallel for now.

There are some important things to note about the code.

1. The variable x appears in a couple of places. Before the parallel region the
value stored in x is 5. Inside the parallel region, the variable is set to 10
and when the code goes past the end of the parallel block of code, the value
printed out is the original value of 5. The declaration of a private variable
implies that the version inside the parallel block is independent of what goes
on outside the parallel block.

## Assumptions:

1. The command prompt in the terminal ends with the % character.

2. The **-fopenmp** includes the needed information to use bits and pieces of
   **omp.h**.

3. Note that the output from running the executables in the above example are
   different. Students should try both.
