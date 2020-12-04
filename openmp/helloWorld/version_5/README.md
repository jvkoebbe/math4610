# Example Description: Version 5.

Keeping with the extension of concepts approach, the code in this example adds
in one new feature. There is an additional call to an OpenMP runtime function
that will set the number of threads used in the execution of the code.

        omp_set_num_threads(5);

This call must be put into the code before a parallel block. The routine cannot
be called inside the parallel block. In addition, the call applies to any
parallel block of code after the number of threads have been set.

In the example, the actual code looks like 

        omp_set_num_threads(5);
        #pragma omp parallel
        {
          printf("Hello World from thread %d\n", omp_get_thread_num());
        }

This is a simple example of how to use a runtime method to control the way your
program will execute on a multi-core device.

## The Code for this Example.

Notice that the code below **#defines** two functions from the OpenMP API so
that a non-OpenMP compilation is possible. Also, both values are set to "1"
which maps to a single thread or processor which is the same as a sequential
running of a code.

        #include <stdio.h>
        #include <stdlib.h>
        #ifdef _OPENMP
          #include <omp.h>
        #else
          #define omp_get_thread_num() 1
          #define omp_set_num_threads() 1
        #endif

        int main(int argc, char *argv[])
        {
          printf("Hello World!\n");
          //
          // the next function call will set the number of threads used to 5.
          // Note that this has nothing to do with the number of processors
          // --------------------------------------------------------------
          //
          omp_set_num_threads(5);
          //
          // parallel directive applied to a block of code
          // ---------------------------------------------
          //
          #pragma omp parallel
          {
            printf("Hello World from thread %d\n", omp_get_thread_num());
          }
          //
          // done with the parallel directive
          // --------------------------------
          printf("I am sequential now.\n");
          //
          // done
          // ----
          //
          return 0;
          //
        }

This is included in the file **helloWorld.c**.

## Compiling Instructions:

Type in the commands:

1. In this part of the example, the compilation does not include the OpenMP flag
   and so the method outlined above sets the one runtime function output to 1.

    % gcc -o helloWorld_vanilla helloWorld.c

   There should be no errors in this case and the resulting binary file can be
   executed. The output from running the code is the same a previous versions.

        Hello World!
        Hello World from thread 1
        I am sequential now.

2. A compilation with opnemp api pieces included.

   % gcc -fopenmp -o helloWorld_omp helloWorld.c

   This compilation will work and produce an appropriate executable for the
   example. The output looks like the following.

        Hello World!
        Hello World from thread 3
        Hello World from thread 2
        Hello World from thread 1
        Hello World from thread 0
        Hello World from thread 4
        I am sequential now.

   In this simple example, using a 12 processor box, only 5 threads are used due
   to the addition of the line in the code 

        omp_set_num_threads(5);

This specifies only 5 threads should be used. The output above should make sense
for this version.

## Assumptions:

1. The number of threads and cores on your computer do not need to be the same.
   You can ask for more threads than cores and vice versa. If you specify more
   threads than cores, some of the threads will need to wait their turn.

2. In specifying the threads, we will need to be careful that we do not start
   data races. This will be covered later in the course.

3. Try running the executable with the same number of threads, say 5. Do this
   multiple times. You should see different orderings of the threads when the
   output shows up. So, the threads are each doing work, but the order of the
   work in a parallel block does not necessarily go in order.

4. Like most things Unix/C/C++ the thread numbers start with index 0, not 1.


<hr>

<a href="../version_4/README.md"> Previous </a>
  &nbsp;&nbsp; | &nbsp;&nbsp;
<a href="../README.md"> Table of Contents  </a>
  &nbsp;&nbsp; | &nbsp;&nbsp;
<a href="../version_6/README.md"> Next </a>

<hr>

