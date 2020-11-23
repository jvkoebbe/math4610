Example Description:

In this example, the addition of the omp.h file and an runtime function from the
OpenMP API are both included. Due to the inclusion of the instrinsic function

  omp_get_thread_num()

which will return an integer that holds the thread number that is currently 
doing work. Note that the number of threads is not the same as the number of
processors - more on this later. The main reason for this example is to show
that using runtime functions requires the use of the -fopenmp flag in order for
the compilation to work.

Compiling Instructions:

Type in the commands:

1. An attempt at a  vanilla compilation with no opnemp api pieces included.
   Typing in the compilation command

    % gcc -o helloworld_vanilla helloworld.c

   will generate the following error message.

    /tmp/ccPvGJtf.o: In function `main':
    helloWorld.c:(.text+0x1c): undefined reference to `omp_get_thread_num'
    collect2: error: ld returned 1 exit status

   The error message includes a reference to the OpenMP API runtime function,
   omp_get_thread_num() as a part of the output.

2. A compilation with opnemp api pieces included.

   % gcc -fopenmp -o helloworld_vanilla helloworld.c

   This compilation will work and produce an appropriate executable for the
   example.

Assumptions:

1. There are no results from the vanilla compilation version of the example. If
   the code will not compile, there is no way to run the code.

2. The documentation for the intrinsic method omp_get_thread_num() along with
   a description of what the function does will be covered in more detail later
   in the examples or in documentation for the OpenMP API that can be found at
   www.openmp.org.
