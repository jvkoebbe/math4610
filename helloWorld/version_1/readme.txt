Example Description:

In this example, the addition of the omp.h file is investigated with no changes
in the code. Whatever is included in omp.h is basically ignored. The goal is to
show how this file can be included. Note that this example uses two different
compile commands to exclude and include the openmp api. That is, the results
generated is that slightly different compilation commands are used. The -f flag
on the gcc command will include information from omp.h.

Compiling Instructions:

Type in the commands:

1. A vanilla compilation with no opnemp api pieces included.

   % gcc -o helloworld_vanilla helloworld.c
   % ./helloworld_vanilla

2. A compilation with opnemp api pieces included.

   % gcc -fopenmp -o helloworld_omp helloworld.c
   % ./helloworld_omp

Assumptions:

1. The command prompt in the terminal ends with the % character.

2. The -fopenmp includes the needed information to use bits and pieces of omp.h.

3. Note that the output from running the executables in the above example are
   different. Students should try both.
