#include <iostream>
#include <vector>

using namespace std;

class Matrix {
    private:
        size_t row;
        size_t column;
        vector<vector<int>> data;

    public:
        Matrix() {}
        Matrix(size_t r, size_t col): row(r), column(col), data(r, std::vector<int>(col)) {}
        ~Matrix() {} 

        Matrix& initialize(int initial) {
            for(int i = 0; i < row; i++) {
                    for (int j = 0; j < column; j++) {
                        data[i][j] = initial;
                }
            }
            return *this;
        }

        Matrix operator+(Matrix other) {
            if (row != other.row || column != other.column) {
                throw invalid_argument("Invalid: cannot add two matrix.\n");
            }
            Matrix result(row, column);
            // row is data.size() col is data[i].size()
            for(int i = 0; i < row; i++) {
                for (int j = 0; j < column; j++) {
                    result.data[i][j] = data[i][j] + other.data[i][j];
                }
            }
            return result;
        }

        Matrix operator-(Matrix other) {
            if (row != other.row || column != other.column) {
                throw invalid_argument("Invalid: cannot difference two matrix.\n");
            }
            Matrix result(row, column);
            for(int i = 0; i < row; i++) {
                for (int j = 0; j < column; j++) {
                    result.data[i][j] = data[i][j] - other.data[i][j];
                }
            }
            return result;
        }

        Matrix& operator=(vector<vector<int>> vec) {
            if(vec.empty()) {
                this->initialize(0);
            }
            if(row == vec.size() && column == vec[0].size()) {
                for(int i = 0; i < row; i++) {
                    for (int j = 0; j < column; j++) {
                        data[i][j] = vec[i][j];
                    }
                }
            } else {
                throw invalid_argument("Size does not match!!!\n");
            }
            return *this;
        }

        // modifiable
        int& operator()(size_t r, size_t col) {
            if (r >= row || col >= column) {
                throw std::out_of_range("Index out of range");
            }
            return this->data[r][col];
        }

        Matrix operator*(Matrix other) {
            if (column != other.row) {
                throw std::invalid_argument("Cannot multiplication");
            } 
            Matrix result(row, other.column);
            for(int i = 0; i < row; i++) {
                for(int j = 0; j < other.column; j++) {
                    int sum = 0;
                    for (size_t k = 0; k < column; ++k) {
                        sum += data[i][k] * other.data[k][j];
                    }
                    result(i, j) = sum;
                }
            }
        }

        int& at(size_t r, size_t col) {
            if (r >= row || col >= column) {
                throw std::out_of_range("Index out of range");
            }
            return this->data[r][col];
        }

        friend ostream& operator<<(ostream& out, Matrix& mat) {
            for(int i = 0; i < mat.row; i++) {
                for(int j = 0; j < mat.column; j++) {
                    out << mat.data[i][j] << " ";
                }
                out << endl;
            }
            return out;
        }
};

int main() {
    size_t rows = 3;
    size_t cols = 4;

    Matrix mat1(rows, cols);
    Matrix mat2(4, 3);

    mat1.initialize(0);
    mat2.initialize(1);

    Matrix mat3(4, 3);
    mat3 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
        {10, 11, 12}
    };

    Matrix mat4 = mat2;

    Matrix mat5 = mat2 + mat4;

    cout << mat1 << endl << mat2 << endl << mat3 << endl << mat4 << endl;
    cout << mat5 << endl;

    cout << mat3.at(1,2) << endl;
    return 0;
}
