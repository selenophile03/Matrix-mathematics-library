#include "Matrix.hpp"
#include <iostream>

int main() {
    try {
        std::cout << "--- Custom Matrix Math Library --- \n\n";

        // Create matrices using standard initializers
        Matrix<double> A = {
            {1.0, 2.0},
            {3.0, 4.0}
        };

        Matrix<double> B = {
            {5.0, 6.0},
            {7.0, 8.0}
        };

        std::cout << "Matrix A:\n";
        A.display();

        std::cout << "Matrix B:\n";
        B.display();

        // Testing Operator Overloading (+)
        std::cout << "Result of A + B:\n";
        Matrix<double> sum = A + B;
        sum.display();

        // Testing Operator Overloading (*)
        std::cout << "Result of A * B:\n";
        Matrix<double> product = A * B;
        product.display();

        // Testing Transposition
        std::cout << "Transpose of Matrix A:\n";
        Matrix<double> transA = A.transpose();
        transA.display();

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
