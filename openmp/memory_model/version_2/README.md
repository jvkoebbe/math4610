# Example Description: Version 1.

This example includes examples of how the OpenMP memory model works. The first
example shows how private variables are used in parallel regions in a code. The
code included looks at a few simple cases and prints out the values  

**Figure 1.** The following figure was taken from the site blogspot.com.

![Memory Model Figure](../images/image_01.jpg "Fig. 1")

The figure depicts how memory is shared by the threads instantiated in an OpenMP
implementation. The shared memory (in the middle) is available at all times for
any thread to use. Private memory is allocated for individual threads and is
only available to the specific thread. This lasts as long as a parallel
structure is in play.

This example presents how variables/memory is treated by OpenMP.

## The Code for this Example:

The code includes variables in and out of a parallel structure with the same
name and variables that are only declared in a parallel block of code.

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

## Comments on the Code:

1. The variable x appears in a couple of places. Before the parallel region the
value stored in x is 5. Inside the parallel region, the variable is set to 10
and when the code goes past the end of the parallel block of code, the value
printed out is the original value of 5. The declaration of a private variable
implies that the version inside the parallel block is independent of what goes
on outside the parallel block. There are ways to ensure the region outside and
inside parallel structures can communicate with each other. 

2. As an example of how the memory models work, the variable x in the code
appears in three locations. Before the parallel region, x, is an integer and
is assigned to the value 5. Once inside the parallel region using either the
parallel or sequential versions, the value is of type int. This apparently need
not be done inside the braces.

3. The variable, y, is also of type int declared prior to the parallel region
and then is reassigned a new value. 

4. The variable z is only used in the parallel region. Once the parallel code
has executed, the variable z is no longer defined. That is the reason for
putting negative output in the printf statements. Note that each thread has its
own copy of the variable z.

5. The output lines are placed prior to the parallel block, in the parallel
block and after the parallel block of code.

6. Also, there is a whole bunch of blank lines towards the end of the output.
This is due to the fact that each and every thread runs a copy of the parallel
block. The number of blank lines is the same as the number of threads in the
thread team. 

7. Note that there are a couple of **clauses** in the OpenMP directive in the
code. These are:

    a. private(x) - this tells the code that the variable is treated as
       private in the parallel block,

    b. firstprivate(y) - this initializes the first value of the private
       variable, y, in the parallel structure to the value of the shared
       variable y just before the parallel region is executed.

## Assumptions:

1. There is no need to compile the vanilla (sequential) version of the code is
only necessary to show how variables are handled in a standard C code. 

2. The **-fopenmp** includes the needed information to use bits and pieces of
   **omp.h**.

3. Note that the output from running the executables in the above example are
   different. Students should try additional examples.
