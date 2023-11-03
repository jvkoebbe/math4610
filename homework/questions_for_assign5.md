# Questions for Homework 5

**Question 1:** Write code to solve an upper triangular system of equations. This is the backsubstitution algorithm for class. Put this in an object file or Python file if programming in Python. Test on at least one $10\times 10$ upper triangular system of equations.

**Question 2** What are the minimum conditions on an upper triangular system for your algorithm to produce a unique solution?

**Question** Repeat your work on Question 1 with modifications to the algoritihm for a code that will produce the solution of a lower triangular linear system of equation. We worked on this in class in the context of the LU factorization of a matrix and solving linear systems via LU factorization.

**Question 4.** Write a code that will solve a linear system of equations using Gaussian Eliminaton (GE). The input to the code will be a square matrix, $A$, a right hand side vector, $b$, and the number of rows and column in the matrix. You should have separate routines for the elimination step and the backsubstitution step. In a software manual you would need to explain the relationship between the two codes and their usage.

**Question 5.** Write a module/object file that will take as input a matrix, $A$, and vector, $y$, and possibly the size of the matrix $n$, and produce a vector, $b$, that is the product of the matrix multiplied into the vector from the left.

**Question 6.** Test the result of your work from Question 4 on diagonally dominant matrices as discussed in class. That is, use the following steps to define a single test of your code. You can define a loop to test your code on any number of problems you need.

**a.** Select a value, $n$, for the size of the matrix.

**b.** Generate a diagonally dominant matrix by filling the test matrix with numbers between zero and one. Then modify the diagonal entries by adding all the entries in each row together adding a positive number tothat sum and then replacing the diagonal entry in the row with the resulting sum.

**c.** Define a vector, $y$, of length $n$, with all entries in the vector equal to one.

**d.** Compute the product of the matrix, $A$, and vector, $y$, which will produce a vector, $b$, for a test linear system.

**e.** Use your code for Gaussian Elimination to solve the resulting system, $Ax=b$.

**f.** Compare the solution, $x$, to the vector of ones generated above. The computed solution should be close to the vector of ones in $y$.

**Question 7.** Repeat the work from the previous Questions, but aim the work at using the LU factoriation of matrix. Recall that this approach will require only a small modification to your code in the elimination phase and the additional work of solving a lower triangular matrix before solvingthe associated upper triangular system of equations.

**Question 8.** Since GE and LU require about the same amount of work, say $O(n^3)$ and forward elination and backsubstitution require about the same amount of work, say $O(n^2)$, write out the following work loads for your solvers. Assume that the matrix does not change and the right hand side vector may vary.

* GE requires $O(n^3)$ + $O(n^2)$ operations per linear system.

* LU factorization requires a single $O(n^3)$ elimination for all systems plus $2\times O(n^2)$ operatioons.

Is there a value of $n$ such that these two methods break even in terms of the amount of work necessary to perform the work.

**Question 9.** Build a "package" or shared library of codes that contain the work from this set of Questions. In the package, only include what you need to solve linear systems. Your code should be completely self-contained with a test code as described in Question 6.

**Question 10.** Write up a software manual for the package of codes you created.