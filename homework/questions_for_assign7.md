# Questions for Homework 7

**Question 1:** Write code to compute the largest eigenvalue (in magnitude)
of a square matrix of order, $n$. The code should take as input a matrix, $A$,
nonzero vector as an initial guess at the eigenvector for the largest
eigenvalue. Also, allow the user to pass in a tolerance for the error and a
maximum iteration counter for the algorithm. The code should return the
eigenvalue approximation that results.

**Question 2** Apply the code written in Question 1 to compute the largest
eigenvalue of the Leslie matrix for population modeing. Make sure that you account for the sparsity of the matrix form for algoritihm.

**Question 3** Write a code that will implement the inverse power method for
computing the smallest of a square matrix. Note that you should already have
some of the codes writtenand available for reuse. These include using the
linear system solver you have written that uses the LU-factorization of the 
matrix input to the algorithm. The inputs should be the same as for Question 
1 and the output should be the smallest (in magnitude) that the algoritihm 
produces.

**Question 4.** Write a code that will return the result of applying the 
shifted inverse power method that can be used to compute eigenvalues between 
the smallest and largest eigenvalues of a matrix. Show the method works by 
shifting the matrix to the midpoint between the smallest and largest 
eigenvalues of a given matrix.

**Question 5.** Write a code that partitions the interval defined by the 
smallest and largest eigenvalues of a matrix and then uses the power method 
to compute using the location of the values in the partitions.

**Question 6.** Suppose that we want to find the first two largest 
eigenvalues of a matrix. Outline an algorithm using the power method that 
would allow for this computation. You could think about a Bisection type 
approach with a shift to the left point.