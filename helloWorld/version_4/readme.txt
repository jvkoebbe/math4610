Example Description:

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
      printf("Hello world from thread %d\n", omp_get_thread_num());
    }

This is a simple example of how to use a directive in the OpenMP API

Compiling Instructions:

Type in the commands:

1. In this part of the example, the compilation does not include the OpenMP flag
   and so the method outlined above sets the one runtime function output to 1.

    % gcc -o helloworld_vanilla helloworld.c

   There should be no errors in this case and the resulting binary file can be
   executed.

2. A compilation with opnemp api pieces included.

   % gcc -fopenmp -o helloworld_vanilla helloworld.c

   This compilation will work and produce an appropriate executable for the
   example.

Assumptions:

1. If you compare the output from the last example and the current example, you
   will notice a difference. The use of the parallel directive results in more
   than one print from within the parallel code block.

2. What happens in this code is that if your computer is running 8 threads, each
   of these will perform the code in the parallel block. So, there will be a
   print for each of the threads.

