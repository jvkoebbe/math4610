# Math 4610 Fundamentals of Computational Mathematics

## Welcome

This site provides links to materials used in teaching a one semester course in
the Department of Mathematics and Statistics at Utah State University (USU). The
course, Math 4610 Fundamentals of Numerical Analysis, is intended for students
in computational mathematics, computer science, engineering, and some majors in
business (e.g, example economics majors). The course is intended to give
students in computational areas a starting point for implementation of
algorithms, development of reusable computer codes, and information on how to
get started with parallel computing platforms (e.g, multicore programming,
graphics processing units, threads in Java, and other topics.

## Development of Math 4610

This course is being developed by [Joe Koebbe](https://github.com/jvkoebbe/) at
[Utah State University](http://www.usu.edu) in the [Department of Mathematics
and Statistics](http://www.math.usu.edu/). The course is intended for students
in the [College of Science](https://www.usu.edu/science), the
[College of Engineering](https://engineering.usu.edu), and any other students
who have completed a basic course in linear algebra (e.g, Math 2270 Linear
Algebra) AND ordinary differential equations (e.g, Math 2280 Ordinary
Differential Equations). Students who have completed the combined course Math
2250 are also well qualified to be in this course. Primarily, the course
presents computational methods for the approximate solution of a number of
mathematical problems. The amount of analysis needed is minimal (e.g, Taylor
series and knowledge of results from Linear Algebra). The goal is to introduce
students into the world of computer coding and simulation. Later courses (e.g,
Math 5610 and Math 6610) are used to treat analysis of the methods at a more
advanced level.

## Quick Links to Content for the Course

The following link gives access to the content of Math 4610 including an example
syllabus, a table of contents to the topics used in the lectures in the course,
and other class materials.

[Quick Links](./quicklinks/README.md)

## Course Syllabus

[Course Syllabus](./syllabus/pdf/embed_syllabus.md): This link provides access
to a pdf file that contains a current example of the syllabus for the course as
taught at Utah State University. This should give the reader some idea of how
the materials are covered at USU.

## Introduction to the Course

This course presents content related to basic scientific computing problems.
Students are asked to (1) implement algorithms from a basic numerical methods
course (e.g, Newton's method for finding roots), (2) use techniques from
calculus, linear algebra, and differential equations to do basic analysis of
errors (e.g, Taylor series expansion and computation of eigenvalues and
eigenvectors), and (3) build shared libraries based on the code written (e.g,
archives on Linux or DLLs on Windows), (4) document the work done in a software
manual, and (5) implement efficient versions of algorithms using parallel
programming techniques (e.g, [OpenMP](https://openmp.org) and
[OpenACC](https://openacc.org)).

Each of the items just listed is viewed as an important part of being a
computational mathematics/scientific computing expert. There are also real
reasons why it is important that students are well prepared in each of these
skill sets. It is ultimately important that any student in this course is able
to implement simple algorithms in a native coding language (say C) or
interpreted language (say, Java). There are some in these areas that would say
that implementation of algorithms using a computational platform like Matlab is
a better way to teach algorithm implementation. However, if a student is hired
into a software development company or a position within a large company to
write software, Matlab is usually too expensive to use. In an academic setting
Matlab is usually a great way to prototype ideas. The built in functionality and
graphical interfaces are great for testing ideas in many areas of mathematics
and science. However, incorporating Matlab and any other of these platforms
requires a larger financial commitment. More importantly, computational
mathematicians are constantly faced with problems where it is important to be
able to debug and write new code that modifies an existing piece of software.
For example, it might be important to rewrite code to work on multiple cores on
a desktop. This may mean digging into existing code and rewriting the code. This
is a skill set that all computational mathematics professionals must have. Using
simple algorithms as a means to present these ideas is the best approach.

The basic mathematical techniques from calculus and for that matter, any other
area of mathematics, is important in determining the range of problems to which
an approximate solution technique can be applied. Knowing the limitations of
various methods applied to classes of problems is invaluable. For example, it
might be necessary to apply an iterative method (e.g, Jacobi iteration or the
conjugate gradient method) to a linear system of equations versus a direct
method (e.g, LU-factorization) to a given linear system of equations. It is
important to know which methods will perform the best in terms of accuracy of
the approximation that is produced and the amount of computational effort needed
by these methods.

The third point to consider involves an important skill set in terms of how many
codes and packages are implemented. This is a minor point in the course, but
helps students understand how reusable code can be created in the implementation
of basic algorithms. For example, if one code for the solution of nonlinear
scalar equations can be used, a computational mathematician should be able to
write code that can be used to solve a variety of these types of problems.
Embedding a new version of an algorithm in each new application code written is
incredibly inefficient. In most high level languages from C and Fortran and
including Python and Java there are tools for creating these packages and
libraries. Calling routines from a shared library slows down the execution of
any code. However, most compilers these days, are smart enough to in-line codes
through some compiler options. In fortran, most compilers allow the user to put
in something like a -Bstatic flag to create a static image of the executable
code. The tradeoff in this case is the size of the binary image of the
application versus the speed of execution. Static images are typically larger
than images that link to shared libraries. In-lining a code reduces the
execution time due to the reduction of references to shared libraries.
Ultimately, a computational mathematician should know how to take advantage of
this balance.

Documentation of work is fundamental to any scientific endeavor. So, students
at USU are asked to created a software manual for the code they write. The
intent of this project is to get students to effectively communicate their work
from the course. The software manual has been placed on Github using markdown
language. From the point of view of a skill set, using Github as a platform to
create a software manual also gives coding nerds experience with a social media
application that can be used to contact other computer programmers who are
interested in the same types of problems.

When a computational mathematician is hired into a software development job, it
is likely the case that a format for the documentation of software already
exists. So, adapting to the documentation format will be required. In terms of
grading for a course like the one described in this repository, it is important
to create a standard way of documenting the software written. A software manual
is provided to students. The format is given later in this introduction. Using
Github and markdown language makes this assignment a lot easier to complete.
Students are asked to start the software manual in the first week of the class
so that students get used to the work it takes.

The last skill set listed above is using the full capabilities of modern
computing hardware. Almost all computers now come with multiple cores (multiple
CPUs) and Graphics Computing Units (GPUs) that provide a wealth of additional
computational horsepower. In recent years, limitations of a single CPU have
stopped the every advancing performance of computers. To aid in the performance
of hardware, computer vendors have started producing more performance through
the addition of multiple cores and GPUs for enhancing graphical displays. These
resources can be used by computational mathematicians to improve the
computational efficiency of the software they develop. In the past few years
language extensions, such as OpenMP and OpenACC, have been developed to take
advantage of these hardware resources. The content in this course touches on
these two language extensions in the implementation of algorithms for the
approximate solution of mathematical problems. The reader should note that there
are a number of gotchas in using these extensions. These occur on both the
hardware and software ends of the implementation. For example, most GPUs that
ship with desktops are geared for graphical displays. This means that errors
can occur in computations that are not corrected. This is fine for graphical
displays, but can cause problems in scientific computing. However, one can
purchase standalone GPUs that have error correcting memory that can be used in
scientific computing. More will be covered as these topics arise in presentation
of content in the course.

## Table of Contents

[Course Contents](./lectures/toc/md/topic_toc.md): This link will take you to a
Markdown (.md) file that contains a the table of contents for the course. For a
one semester course, there may be more content than can be covered. The content
can be used to give instructors/readers plenty to do.

## Software Manual Description and Template

One project students have been asked to do in Math 4610 is to create a software
manual for the codes that are written by the semester. The software manual
project requires students include well written, concise descriptions of the
algorithms and codes developed throughout the course. Students can use github
to easily create the software manual with a template (see the link below) to
create a consistent looking description. Students are encouraged to organize the
software manual so that codes written to solve a similar or the same problem
should be located together (e.g, the Bisection method and Newton's method for
finding roots of a nonlinear function of a single variable). Students are asked
to build all routines including routines to compute errors, do basic linear
algebra operations, and other basic routines that are needed in support of the
main algorithms presented in the course.

The following link will take you to a software manual template in in a Markdown
file for use by students in Math 4610.

[Software Manual Template](softwareManual/softwareManualTemplate.md)

You can download the file above for your own use using the save as feature on
any web browser out there.

<hr>

Previous |
[Top of Page](./README.md) |
[Next](./quicklinks/README.md)

<hr>
