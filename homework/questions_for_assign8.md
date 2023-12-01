# Questions for Homework 8

**Question 1:** Build a code that will produce approximate solutions for linear
systems of equations using Jacobi iteration. The algorithm has been presented in
class and you can find great references through Wikipedia and many other
sites on-line. The code should be implemented on a system of at least 100
equations in 100 with a diagonally dominant matrix.

**Question 2** Apply the Jacobi algorithm on a Leslie matrix by modifying the
matrix-vector multiplications. What problems arise at the outset. Compare the
Jacobi iteration approach to the LU-factorization approach in terms of accuracy
of the approximation and efficiency and other issues. Define an algorithm that
will compute the action of the inverse on a right hand side vector for the
system
\[
  L\ n_0 = n_1\ \ \ \ \longrightarrow\ \ \ \ n_0 = L n_1
\]
Recall that this is not the same problem as finding an equilibrium age-class
distribution.

**Question 4** Implement the Gauss-Seidel algorithm for producing
approximations for linear systems of equations. Try the algorithm out on an
appropriate linear system of equations that has at least 100 equations in 100
unknowns.

**Question 4.** Compare the LU factorization to both the Jacobi iteration and
the Gauss-Seidel approach in terms of number of operations. All you need to do
is put in a counter in the code that counts the number of operations in terms of
addition, subtraction, multiplication, and division.

**Question 5.** Test the usage of the code in terms of approximate solutions to
linear approximations. This means that you should create an outside loop that
does the following steps.

1. Generate a matrix that has random (pseudo random) numbers.

2. Modify the matrix to be a diagonally dominant matrix.

3. Create a right hand side for a known solution.

4. Solve the system of equations using each of the methods on the same matrix.
   That is, using the matrix above, compute the approximation using Jacobi,
   Gauss-Seidel, and LU-factorization.

5. Output the number of operations used and the error in the solutions.

The output should be a table of values with columns for each of the solution
methods.
