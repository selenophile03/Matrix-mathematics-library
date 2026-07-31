#include "Matrix.hpp"

// Constructor: Initializes empty matrix with dimensions
template <typename T>
Matrix<T>::Matrix(size_t r, size_t c) : rows(r), cols(c), data(r, std::vector<T>(c)) {}

// Constructor: Initializes matrix with a default value
template <typename T>
Matrix<T>::Matrix(size_t r, size_t c, const T& initialValue) 
    : rows(r), cols(c), data(r, std::vector<T>(c, initialValue)) {}

// Constructor: Allows clean initialization like Matrix m = {{1,2}, {3,4}}
template <typename T>
Matrix<T>::Matrix(std::initializer_list<std::initializer_list<T>> list) {
    rows = list.size();
    cols = list.begin()->size();
    for (const auto& rowList : list) {
        data.push_back(std::vector<T>(rowList));
    }
}

// Matrix Addition Overloading
template <typename T>
Matrix<T> Matrix<T>::operator+(const Matrix<T>& other) const {
    if (rows != other.rows || cols != other.cols) {
        throw std::invalid_argument("Matrix dimensions must match for addition!");
    }

    Matrix<T> result(rows, cols);
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            result.data[i][j] = this->data[i][j] + other.data[i][j];
        }
    }
    return result;
}

// Matrix Multiplication Overloading
template <typename T>
Matrix<T> Matrix<T>::operator*(const Matrix<T>& other) const {
    if (cols != other.rows) {
        throw std::invalid_argument("Matrix inner dimensions must match for multiplication!");
    }

    Matrix<T> result(rows, other.cols, 0);
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < other.cols; ++j) {
            for (size_t k = 0; k < cols; ++k) {
                result.data[i][j] += this->data[i][k] * other.data[k][j];
            }
        }
    }
    return result;
}

// Transpose implementation
template <typename T>
Matrix<T> Matrix<T>::transpose() const {
    Matrix<T> result(cols, rows);
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            result.data[j][i] = this->data[i][j];
        }
    }
    return result;
}

// Display helper
template <typename T>
void Matrix<T>::display() const {
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            std::cout << data[i][j] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}
