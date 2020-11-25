#include "Column.cpp"


// Matrix Class Decleration
class Matrix
{
    public:
        // Constructor for Matrix Class
        Matrix();
        Matrix(int size);
        Matrix(int m, int n);
        Matrix(Column<Column<double> > M);
        
        // Size methods for Matrix Class
        int sizey();
        int size();

        // Redecleration and Column addition methods for Matrix Class
        void resize(int x, int y);
        void push_back(Column<double> val);

        // Printing Methods for Matrix Class
        void print();
        void print_file(ofstream& of);

        // Operator Overloading for Matrix Class
        Column<double>& operator() (int row);
        double& operator() (int row, int col);
        Matrix operator* ( Matrix M2);
        Matrix operator* ( double s);
        Matrix operator+ ( Matrix M2);
        Matrix operator- ( Matrix M2);

        // Basic Matrix Methods for Matrix Class
        Matrix Transpose();
        Matrix selectBlock(int fromrow,int fromcol, int endrow,int endcol);
        double infinity_norm();
        double first_norm();
        double self_dotprod();
        double second_norm_for_vec();

        // Creating Specific Matrix Methods
        void makeUnitVec();
        void randomMatrix(int row,int column);
        void identity(int size);
        void elementary(int size,int n);
        
        // Methods used for finding eigenvalues and eigenvectors
        void PowerIteration(double& e,Matrix& v,double tol);
        Matrix houseHolder(Matrix x1);
        void return_eigs(Matrix& v2, double e2, double e1, Matrix& HH, Matrix& b);

    private:
        // Private Variables of Matrix Class
        Column<Column<double> > arr;
        int size_x;
        int size_y;
};
