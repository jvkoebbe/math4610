# Example Description: Version 1.

In this example, the addition of the omp.h file is investigated with no changes
in the code. Whatever is included in omp.h is basically ignored. The goal is to
show how this file can be included. Note that this example uses two different
compile commands to exclude and include the openmp api. That is, the results
generated arise from slightly different compilation commands. The -f flag on the
**gcc** command will include information from **omp.h**.

## The Code for this Example:

        #include <stdio.h>
        #include <stdlib.h>
        #include <omp.h>

        int main(int argc, char *argv[])
        {
          printf("Hello World!\n");
          return 0;
        }

This is included in the file **helloWorld.c**.

## Compiling Instructions:

Type in the commands:

1. A vanilla compilation with no opnemp api pieces included.

        koebbe% gcc -o helloWorld_vanilla helloWorld.c
        koebbe% ./helloWorld_vanilla

The output from this pair of commands is the following:

        Hello World!

2. A compilation with opnemp api pieces included.

        koebbe% gcc -fopenmp -o helloWorld_omp helloWorld.c
        koebbe% ./helloWorld_omp

The output from this pair of commands is the following:

        Hello World!

## Assumptions:

1. The command prompt in the terminal ends with the % character.

2. The **-fopenmp** includes the needed information to use bits and pieces of
   **omp.h**.

3. Note that the output from running the executables in the above example are
   different. Students should try both.

<hr>

<a href="../README.md"> Previous </a>
  &nbsp;&nbsp; | &nbsp;&nbsp;
<a href="../README.md"> Table of Contents  </a>
  &nbsp;&nbsp; | &nbsp;&nbsp;
<a href="../version_2/README.md"> Next </a>

<hr>

