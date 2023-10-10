#include <iostream>
#include <vector>

using namespace std;

//class called matrix that creates a matrix
class Matrix{
private:
    //initializing rows and cols
    int rows;
    int cols;

    //Multidimensional Vector to store matrix
    vector< vector <int> > matrix;

public:
    //constructor: initializing rows cols and matrix
    Matrix(int rows, int cols) : rows(rows), cols(cols), matrix(rows, vector<int>(cols, 0)) {}

    //allows user to create their own matrix of their desired size
    // thhis code will output the row index col index and allows a user to input the value they choose;
    void setMatrix(int row, int col, int value) {
        //checking whether the provided row and col indicies are within the valid range
        if( row >= 0 && row < rows && col >= 0 && col < cols){
            matrix[row][col] = value;
        } else {
            cout << "invalid row or column index." << endl;
        }
    }

    int getMatrix(int row, int col) const {
        if( row >= 0 && row < rows && col >= 0 && col < cols){
            return matrix[row][col];
        } else {
            cout << "invalid row or column index." << endl;
            return 0;
        }
    }

    //member function to print the contents of a matrix to the console
    void printMatrix() const {
        for( int i = 0; i < rows; i++ ) {
            for( int j = 0; j < cols; j++ ) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {

    int rows, cols;

    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> cols;

    Matrix matrix(rows, cols);

    for( int i = 0; i < rows; i++ ) {
        for( int j = 0; j < cols; j++ ) {
            int value; //this value lets the user store their own data in the specified index of the matrix
            cout << "Enter matrix [" << i << "][" << j << "]: ";
            cin >> value;
            matrix.setMatrix(i, j, value);
        }
    }
    //printing matrix
    matrix.printMatrix();

    //allows the user retrieve and print a specific element in the matrix
    int elementRow, elementCol;
    cout << "\nEnter the row and column that you would like to retrieve an element from." << endl;
    cout << "Enter the row: ";
    cin >> elementRow;
    cout << "Enter the column: ";
    cin >> elementCol;
    int element = matrix.getMatrix(elementRow, elementCol);
    cout << "Element at (" << elementRow << ", " << elementCol << "): " << element << endl;

    return 0;
}
