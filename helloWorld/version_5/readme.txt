Example Description:

Keeping with the extension of concepts approach, the code in this example adds
in one new feature. There is an additional call to a OpenMP runtime function
that will set the number of threads to use.

    omp_set_num_threads(5);

This call must be put into the code before a parallel block. The routine cannot
be called inside the parallel block. In addition, the call applies to any
parallel block of code after the number of threads have been set.

In the example, the actual code looks like 

    omp_set_num_threads(5);
    #pragma omp parallel
    {
      printf("Hello world from thread %d\n", omp_get_thread_num());
    }

This is a simple example of how to use a runtime method to control the way your
program will execute on a multi-core device.

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
