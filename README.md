#First two eigenvectors and eigenvalues
Cpp program for detecting eigenvectors and eigenvalues of a square matrix

This project is written in C++\
In this project 3 arguements are needed in order:\
A file contains n*n A matrix , toleration value and a file name or directory for output file.\
This Project is used for finding first and second dominant eigen value and their corresponding eigenvectors\
It prints to the output file and the console each eigen value and its corresponding eigenvector\
in that format:\
Eigen value #1 = 20.488\
0.348061 \
0.622149 \
0.554319 \
1 \
Eigen value #2 = 3.91405\
0.495752 \
0.24402 \
-0.731315 \
0.520344 \
for toleration 1e-6 and\
Matrix A = \
[3.14 1.59 2.65 3.58;\
 9.79 3.23 8.46 2.64;\
 3.38 3.27 9.50 2.88;\
 4.19 7.16 9.39 9.37]


./main.exe ./A.txt %tolerance% b.txt

This Project contains 2 Header (.h) 3 source code (.cpp) files\
Column.h is header file for Column Class\
Column.cpp is source code for Column Class\
Matrix.h is header file for Matrix Class\
Matrix.cpp is source code for Matrix Class\
and \
main.cpp is source code of main project\

Column class uses dynamic allocation to store the array\
Matrix is basicly a column array
