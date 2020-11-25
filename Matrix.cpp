#include "Matrix.h"
using namespace std;
// Methods of Matrix Class
// Constructers

// Default Constructor
Matrix::Matrix()
{
    size_x = 0;
    size_y = 0;
}

// Matrix Constructor that constructs a matrix that has size number of columns
Matrix::Matrix(int size)
{
    arr.resize(size);
    for(int i = 0; i < size ; i++)
        arr[i].resize(1,0);
    size_x = size;
    size_y = 0;
}
// Matrix Constructor that constructs a (m*n) Matrix
Matrix::Matrix(int m, int n)
{
    arr.resize(m);
    size_x = m;
    size_y = n;
    for(int i = 0 ; i < m; i++)
    {
        arr[i].resize(n,0);
    }
}

// Matrix Constructor that constructs matrix from another matrix
Matrix::Matrix(Column<Column<double> > M)
{
    size_x = M.size();
    size_y = M[0].size();
    arr = M;
}

// Basic array methods

// A method that returns number of columns
int Matrix::sizey()
{
    return size_y;
}

// A method that returns number of rows
int Matrix::size()
{
    return size_x;
}

// Resizing Matrix to x*y matrix
void Matrix::resize(int x, int y)
{
    size_x = x;
    size_y = y;
    arr.resize(x);
    size_x = x;
    size_y = y;
    for(int i = 0 ; i < x; i++)
    {
        arr[i].resize(y,0);
    }

}

// A Method that adds another column which is given
void Matrix::push_back(Column<double> val)
{
    arr.push_back(val);
    size_x++;
    size_y = val.size();
}

// A Method that prints matrix to Console
void Matrix::print()
{
    for (int i = 0; i < size_x ; i++)
    {
        for(int j = 0; j < size_y; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

// A Method that prints matrix to output file using ofstream
void Matrix::print_file(ofstream& of)
{
    for (int i = 0; i < size_x ; i++)
    {
        for(int j = 0; j < size_y; j++)
            {
                of << arr[i][j] << " ";
            }
        of << endl;
    }
}

// Operator overload for Matrix Class

// () operator Overloaded to get the row
Column<double>& Matrix::operator() (int row)
{
    return arr[row];
}

// () operator Overloaded to get the adress which is at arr[row][col]
double& Matrix::operator() (int row, int col)
{
    return arr[row][col];
}

// * operator Overloaded for Matrix Multiplication
Matrix Matrix::operator* ( Matrix M2)
{
    int s1 = M2.sizey();
    Matrix temp(size_x,s1);
    double sum=0;
    for(int i = 0; i < size_x; i++)
    {
        for(int j = 0 ; j < s1; j++)
        {
            sum = 0;
            for(int k = 0 ; k < size_y; k++)
            {
                sum += arr[i][k] * M2(k,j) ;
            }
            temp(i,j) = sum;
        }
    }
    return temp;
}

// * Operator Overloaded for scalar multiplication with a scalar number
Matrix Matrix::operator* (double s)
{
    Matrix temp(size_x,size_y);
    for(int i = 0; i < size_x; i++)
    {
        for(int j = 0 ; j < size_y; j++)
        {
            temp(i,j) = s * arr[i][j];
        }
    }
    return temp;
}

// + Operator Overloaded for adding two Matrix
Matrix Matrix::operator+ (Matrix M1)
{
    Matrix temp(size_x, size_y);
    for(int i = 0; i < size_x; i++)
    {
        for(int j = 0 ; j < M1.size_y; j++)
        {
            temp(i,j) = M1(i,j) + arr[i][j];
        }
    }
    return temp;
}

// - Operator Overloaded for subtracting one matrix from another
Matrix Matrix::operator- (Matrix M1)
{
    Matrix temp(size_x,size_y);
    for(int i = 0; i < size_x; i++)
    {
        for(int j = 0 ; j < size_y; j++)
        {
            temp(i,j) = arr[i][j] - M1(i,j);
        }
    }
    return temp;
}

// Matrix methods for Matrix Class

// A method that returns its transpose
Matrix Matrix::Transpose()
{
    Matrix temp(size_y,size_x);
    for( int i = 0; i < size_y; i++)
    {
        for (int j = 0 ; j < size_x; j++)
        {
            temp(i,j) = arr[j][i];
        }
    }
    return temp;
}

// A method that returns infinity_norm
double Matrix::infinity_norm()
{
    double max = 0;
    double sum = 0;
    for(int i = 0; i < size_x ;i++)
    {
        sum = 0;
        for(int j = 0; j < size_y; j++)
        {
            sum += abs(arr[i][j]);
        }
        if (sum > max)
        {
            max = sum;
        }
    }
    return max;
}

// A method that returns first_norm
double Matrix::first_norm()
{
    double max = 0;
    double sum = 0;
    for(int i = 0; i < size_y; i++)
    {
        sum = 0;
        for(int j = 0; j < this->size(); i++)
        {
            sum += abs(arr[j][i]);
        }
        if (sum > max)
        {
            max = sum;
        }
    }
    return max;
}

double Matrix::self_dotprod()
{
    double temp = 0;
    for(int i = 0 ; i < this->size() ; i++)
    {
        temp += arr[i][0] * arr[i][0];
    }
    return temp;
}

// A method that returns second norm of that vertical vector
double Matrix::second_norm_for_vec()
{
    return sqrt((*this).self_dotprod());
}

// A method that normalize that vertical vector
void Matrix::makeUnitVec()
{
    double norm = this->second_norm_for_vec();
    for(int i = 0 ; i < this->size(); i++)
    {
        arr[i][0] /=  norm;
    }
}

// A method that returns A block from that Matrix
Matrix Matrix::selectBlock(int fromrow,int fromcol, int endrow,int endcol)
{
    Matrix temp(endrow - fromrow, endcol - fromcol);
    for(int i = fromrow; i < endrow; i++)
    {
        for(int j = fromcol; j < endcol; j++)
        {
            temp(i - fromrow,j - fromcol) = (*this)(i,j);
        }
    }
    return temp;
}

// Matrix Creation Methods of Matrix Class

// A method that generates randomized matrix with row*column size
void Matrix::randomMatrix(int row,int column)
{
    this->resize(row,column);
    for(int i = 0; i < row ; i++)
    {
        for(int j = 0; j < column; j++)
        {
            arr[i][j] = (rand() + 1 ) %100;
            if (arr[i][j] == 0)
                arr[i][j] = 1;
        }
    }
}

// A method that generates size*size Identity matrix 
void Matrix::identity(int size)
{
    this->resize(size,size);
    for(int i = 0; i < size; i++)
    {
        arr[i][i] = 1;
    }
}

// A method that generates elementary size*1 vector e_n 
void Matrix::elementary(int size,int n)
    {
    this->resize(size,1);
    arr[n - 1][0] = 1;
    }

// Methods to find eigenvalues and eigenvectors of Matrix Class

// A method that applies Normalized Power Iteration method to generate dominant eigenvalue and eigenvector
// It writes eigenvalue to e and eigenvector to v adresses
void Matrix::PowerIteration(double& e,Matrix& v,double tol)
{
    double temp = 0;
    double tmp2 = 1;
    // randomized size_x sized vector created and normalized for Normalized Power Iteration 
    v.randomMatrix(size_x,1);
    v.makeUnitVec();
    // Checking abs(||y_k|| - ||y_k-1||)  absolute difference is less then tolerance number that is taken using command line arguements
    while(!(abs(tmp2 - temp) < tol))
    {
        // setting prev ||y_k|| to new ||y_k||
        tmp2 = temp;
        // Matrix Multiplication y_k+1 = A*x_k
        v = (*this) * v;
        // setting new ||y_k+1||
        temp = v.infinity_norm();
        // getting x_k+1 vector by dividing y_k+1 by ||y_k+1||
        v = v * (1/temp);
    }
    // writing eigenvalue to e
    e = temp;
}

// A Method that returns housholder transformation H Matrix
// We use that for getting second eigenvalue and eigenvector
Matrix Matrix::houseHolder(Matrix x1)
{

    Matrix HH(x1.size(),x1.size());
    Matrix I;
    // Getting Identity Matrix
    I.identity(x1.size());
    // getting x1.size()*1 Vector 
    Matrix v(x1.size(),1);
    double alpha = x1.second_norm_for_vec();
    Matrix e1;
    // generating elementary matrix e1
    e1.elementary(x1.size(),1);

    // v = x1 +- alpha * e1
    // and than Houshonder transformation matrix HH
    // HH = I - 2 * (v * vtrans)/(vtrans * v)
    // vtrans * v = v.self_dotprod()
    if(x1(0,0) >= 0)
    {
        v = x1 + (e1 * alpha);
        HH = I - (v * v.Transpose()) * (2/(v.self_dotprod()));
    }
    else
    {
        v = x1 - (e1 * alpha);
        HH = I - (v * v.Transpose()) * (2/(v.self_dotprod()));
    }
    return HH;
}
// H * A * H^-1  = | eigenvalue1   bTranspose |
//                 |      0            B      |
// a Method that generates second eigenvector using eigenvalue1-2, eigenvector of matrix B is y2,
// Householder matrix HH and btranspose (which is Vector b)
// alpha = bTranspose * y2 / (eigenvalue2 - eigenvalue1)
//                        | alpha |
// eigenvector2 = H^-1 *  |  y2   |
// v2 is initially y2 but at the and of the function it is eigenvector2
// e2 is eigenvalue2, e1 is eigenvalue1 
// HH is matrix H which is householder transformation matrix
// b is bTranspose vector
void Matrix::return_eigs(Matrix& v2, double e2, double e1, Matrix& HH, Matrix& b)
{
    double alpha = ((b * v2)(0,0)) / (e2 - e1);
    Matrix t(size(),1);
    
    t(0,0) = alpha;

    for(int i = 0; i < size() - 1; i++)
    {
        t(i + 1,0) = v2(i,0);
    }
    v2 = HH * t;
}
