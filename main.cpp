#include "Matrix.cpp"
#include <bits/stdc++.h>
using namespace std;

// Main Function

int main(int argc,char* argv[])
{
    // There has to exist 3 args
    // arg1 = inputFile
    // arg2 = tolerance
    // arg3 = outputFile
    if (argc!= 4)
    {
        cout << "Wrong number of inputs" << endl;
        return 1;
    }
    stringstream strs(argv[2]);
    // Reading tolerance value from arg2
    double tol = 0;
    strs >> tol;
    if (tol <= 0)
    {
        cout << "Invalid tolerance" << endl;
        return 1;
    }
    // Opening Matrix file from arg1
    ifstream MatrixAfile;
    // Opeining output file from arg3
    ofstream outFile;
    MatrixAfile.open(argv[1]);
    if(!MatrixAfile.is_open())
    {
        cout << "File could not be opened" << endl;
        return 1;
    }
    outFile.open(argv[3]);
    if(!outFile.is_open())
    {
        cout << "File could not be created" << endl;
        return 1;
    }
    // Reading matrix A form the file opened
    string line;
    Matrix A;
    while (getline(MatrixAfile, line))
    {
        // Reading one line at a time
        stringstream ss(line);
        double x;
        Column<double> temp;
        // Reading one double at a time
        while(ss >> x)
        {
            // Constructing temporary Column object
           temp.push_back(x);
        }
        // Adding a column to A Matrix
        A.push_back(temp);
    }
    // Closing file
    MatrixAfile.close();

    // Finding and writinge eigenvalues and corresponding eigenvectors
    double e1,e2;
    Matrix v;
    // Applying Power Iteration for A
    A.PowerIteration(e1,v,tol);
    // Printing first eigencouple to file and to the console
    cout << "Eigen value #1 = " << e1 << endl;
    outFile << "Eigen value #1 = " << e1 << endl;
    v.print();
    v.print_file(outFile);
    Matrix v2;

    // Deflation Part

    // Constructing Housholder Transformation matrix
    Matrix H = A.houseHolder(v);
    // selecting B matrix in (H * A * H^-1)
    Matrix B = ((H * A) * H).selectBlock(1,1,A.size(),A.sizey());
    // Applying power iteration for B
    B.PowerIteration(e2,v2,tol);
    // Selecting b Transpose matrix to find eigenvector
    Matrix b = B.selectBlock(0,1,1,B.sizey());
    // Finding eigenvector by v2 = H^-1 * [alpha;y2] where alpha = b Transpose (actually b in here) / (eigenvalue 2 - eigenvalue 1)
    A.return_eigs(v2,e2,e1,H,b);

    // Printing second eigencouple to the file and to the console
    cout << "Eigen value #2 = " << e2 << endl;
    outFile << "Eigen value #2 = " << e2 << endl;
    v2.print();
    v2.print_file(outFile);
    //closing file
    outFile.close();
    return 0;
}