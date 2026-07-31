#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <vector>
#include <iostream>
#include <stdexcept>

template <typename T>
class Matrix {
private:
    size_t rows;
    size_t cols;
    std::vector<std::vector<T>> data;

public:
    // Constructors
    Matrix(size_t r, size_t c);
    Matrix(size_t r, size_t c, const T& initialValue);
    Matrix(std::initializer_list<std::initializer_list<T>> list);

    // Getters
    size_t getRows() const { return rows; }
    size_t getCols() const { return cols; }

    // Operator Overloading for Math Operations
    Matrix<T> operator+(const Matrix<T>& other) const;
    Matrix<T> operator*(const Matrix<T>& other) const;

    // Transpose function
    Matrix<T> transpose() const;

    // Print helper
    void display() const;
};

// Include implementation for templates directly in the header or at the bottom
#include "Matrix.cpp"

#endif
