# Example Description: Version 3.

In this example, a way to avoid error messages on compilation of codes that
might have runtime functions specified in the code. We can do this with a little
work up front and through the following bit of code. At the top of your
file containing the hello world code insert

        #ifdef _OPENMP
          #include <omp.h>
        #else
          #define omp_get_thread_num() 1
        #endif

This conditional structure will include the OpenMP library if the **_OPENMP**
environment variable is not null. If the variable is null, the string that is
used to call the OpenMP function will be replaced with a value of 1. This avoids
the problems with compilation encountered in the previous example.

## The Code for this Example.

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
          printf("Hello World from thread %d\n", omp_get_thread_num());
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
   executed. When you run the code, you should see output from the printf
   lines in the code. The output should look like:

        Hello World!
        Hello world from thread 1
        I am sequential now.

2. A compilation with opnemp api pieces included.

       % gcc -fopenmp -o helloWorld_omp helloWorld.c

   This compilation will work and produce an appropriate executable for the
   example. The output will look like the following.

        Hello World!
        Hello world from thread 0
        I am sequential now.

## Assumptions:

1. The 5 lines explained above should be added into any code using the OpenMP
   API. It will save time and allow you to keep one version of the code you are
   working on.

2. If more runtime functions are included in a code, you should add a line in
   the **#define** declaration for each of the runtime functions you have
   included in the code. 

3. Students should note that there is no parallelism being used in the version
   of the code in this example. We will add in parallel blocks in the next
   example.


<hr>

<a href="../version_2/README.md"> Previous </a>
  &nbsp;&nbsp; | &nbsp;&nbsp;
<a href="../README.md"> Table of Contents  </a>
  &nbsp;&nbsp; | &nbsp;&nbsp;
<a href="../version_4/README.md"> Next </a>

<hr>

