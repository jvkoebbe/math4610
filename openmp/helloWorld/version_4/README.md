# Example Description: Version 4.

In this example, a parallel block is added to the code. The code that is added
looks like

        #pragma omp parallel
        {
          *
          *               parallel block code goes in here
          *
        }

Directives and runtime functions can be included into a parallel region using
the #pragma declaration. This tells the compiler that a preprocessing of the
code will be done. The token omp in the line tells the compiler to include the
OpenMP functions and directives. The token parallel is an actual OpenMP
directive. Note that there are braces that tell the compiler which block of code
will be preprocessed.

In the example, the actual code looks like 

        #pragma omp parallel
        {
          printf("Hello World from thread %d\n", omp_get_thread_num());
        }

This is a simple example of how to use a directive in the OpenMP API. Note that
the code within the code block will be executed by each and every active thread.

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
          printf("Hello World!\n");
          #pragma omp parallel
          {
            printf("Hello World from thread %d\n", omp_get_thread_num());
          }
          printf("I am sequential now.\n");
          return 0;
        }

This is included in the file **helloWorld.c**.

## Compiling Instructions:

Type in the commands:

1. In this part of the example, the compilation does not include the OpenMP flag
   and so the method outlined above sets the one runtime function output to 1.

        % gcc -o helloWorld_vanilla helloWorld.c

   There should be no errors in this case and the resulting binary file can be
   executed. Since the code is run sequentially, the output will look like the
   following:

        Hello World!
        Hello World from thread 1
        I am sequential now.

2. A compilation with opnemp api pieces included.

   % gcc -fopenmp -o helloWorld_vanilla helloWorld.c

   This compilation will work and produce an appropriate executable for the
example.

        Hello World!
        Hello World from thread 9
        Hello World from thread 3
        Hello World from thread 1
        Hello World from thread 4
        Hello World from thread 2
        Hello World from thread 8
        Hello World from thread 5
        Hello World from thread 6
        Hello World from thread 7
        Hello World from thread 10
        Hello World from thread 0
        Hello World from thread 11
        I am sequential now.

The computer used in this example has 12 processors and the default number of
threads matched the number of processors. This is not necessarily the case as we
will see in the next couple of examples. Rerun the code several times and since
the processes are run asynchronously, the order will change each time the
executable is run.

## Assumptions:

1. If you compare the output from the last example and the current example, you
   will notice a difference. The use of the parallel directive results in more
   than one print from within the parallel code block.

2. What happens in this code is that if your computer is running 8 threads, each
   of these will perform the code in the parallel block. So, there will be a
   print for each of the threads.


<hr>

<a href="../version_3/README.md"> Previous </a>
  &nbsp;&nbsp; | &nbsp;&nbsp;
<a href="../README.md"> Table of Contents  </a>
  &nbsp;&nbsp; | &nbsp;&nbsp;
<a href="../version_5/README.md"> Next </a>

<hr>

