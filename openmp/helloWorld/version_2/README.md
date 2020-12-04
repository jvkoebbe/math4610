# Example Description: Version 2.

In this example, the addition of the omp.h file and a runtime function from the
OpenMP API are both included. Due to the inclusion of the instrinsic function

      omp_get_thread_num()

which will return an integer that holds the thread number that is currently 
doing work. Note that the number of threads need not be the same as the number
of processors - more on this later. The main reason for this example is to show
that using runtime functions requires the use of the **-fopenmp** flag in order
for the compilation to work.

## The Code for this Example:

        #include <stdio.h>
        #include <stdlib.h>
        #include <omp.h>

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

This is included in the file **helloWorld.c**

## Compiling Instructions:

Type in the commands:

1. An attempt at a  vanilla compilation with no opnemp api pieces included.
   Typing in the compilation command

        % gcc -o helloWorld_vanilla helloWorld.c

   will generate the following error message.

        /tmp/ccPvGJtf.o: In function `main': helloWorld.c:(.text+0x1c):
        undefined reference to `omp_get_thread_num' collect2: error: ld
        returned 1 exit status

The error message includes a reference to the OpenMP API runtime function,
**omp_get_thread_num()** as a part of the output.

2. A compilation with openmp api pieces included.

        % gcc -fopenmp -o helloWorld_omp helloWorld.c

This compilation will work and produce an appropriate executable for the
example.

If the code is executed, something like the following will appear in your
console.

        Hello World!
        Hello World from thread 0
        Hello World from thread 5
        Hello World from thread 2
        Hello World from thread 8
        Hello World from thread 6
        Hello World from thread 7
        Hello World from thread 1
        Hello World from thread 9
        Hello World from thread 4
        Hello World from thread 10
        Hello World from thread 3
        Hello World from thread 11
        I am sequential now.

## Assumptions:

1. There are no results from the vanilla compilation version of the example. If
   the code will not compile, there is no way to run the code.

2. The documentation for the intrinsic method **omp_get_thread_num()** along
   with a description of what the function does will be covered in more detail
   later in the examples or in documentation for the OpenMP API that can be
   found at [www.openmp.org]www.openmp.org).


<hr>

<a href="../version_1/README.md"> Previous </a>
  &nbsp;&nbsp; | &nbsp;&nbsp;
<a href="../README.md"> Table of Contents  </a>
  &nbsp;&nbsp; | &nbsp;&nbsp;
<a href="../version_3/README.md"> Next </a>

<hr>

