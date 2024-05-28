#include <iostream>
#include <vector>

using namespace std;

class Matrix {
private:
    vector<vector<double>> elements;
    int numRows, numCols;

public:
    Matrix(int rows, int cols) : numRows(rows), numCols(cols) {
        elements.resize(rows, vector<double>(cols));
    }

    void input() {
        cout << "Enter " << numRows * numCols << " values for a " << numRows << "x" << numCols << " matrix:\n";
        for (int i = 0; i < numRows; ++i) {
            for (int j = 0; j < numCols; ++j) {
                cin >> elements[i][j];
            }
        }
    }

    Matrix operator*(const Matrix& other) const {
        if (numCols != other.numRows) {
            throw invalid_argument("Matrix dimensions do not allow multiplication.");
        }

        Matrix result(numRows, other.numCols);

        for (int i = 0; i < numRows; ++i) {
            for (int j = 0; j < other.numCols; ++j) {
                result.elements[i][j] = 0;
                for (int k = 0; k < numCols; ++k) {
                    result.elements[i][j] += elements[i][k] * other.elements[k][j];
                }
            }
        }

        return result;
    }

    void print() const {
        cout << "Matrix (" << numRows << "x" << numCols << "):\n";
        for (const auto& row : elements) {
            for (const auto& value : row) {
                cout << value << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int rows, cols;

    cout << "Enter the number of rows and columns for the first matrix:\n";
    cin >> rows >> cols;

    Matrix matA(rows, cols);
    Matrix matB(cols, rows);
    Matrix matC(rows, rows);

    cout << "Input values for the first matrix (matA):\n";
    matA.input();

    cout << "Input values for the second matrix (matB):\n";
    matB.input();

    matC = matA * matB;

    cout << "First matrix (matA):\n";
    matA.print();

    cout << "Second matrix (matB):\n";
    matB.print();

    cout << "Resultant matrix (matC = matA * matB):\n";
    matC.print();

    return 0;
}
