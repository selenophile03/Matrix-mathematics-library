# 🧮 Custom Matrix Math Library

A lightweight, high-performance, and type-generic 2D Matrix mathematics library written in modern C++ (C++17). This project serves as a foundational component for graphics engines, physics simulations, or machine learning frameworks.

## 🚀 Key Features

*   **Type Generic (Templates):** Supports integers, floats, doubles, or any custom numeric type.
*   **Modern C++ Practices:** Utilizes standard vectors (`std::vector`), avoiding memory leaks and raw pointer management.
*   **Operator Overloading:** Intuitive math syntax allowing matrices to be added (`+`) and multiplied (`*`) natively.
*   **Initializer List Support:** Clean structural allocation syntax matching modern C++ coding patterns.
*   **Cross-Platform Build System:** Fully managed and compiled via CMake for Windows, macOS, and Linux.

---

## 🛠️ Architecture & Files

```text
📁 CustomMathLibrary/
├── CMakeLists.txt      # Cross-platform build automation script
├── Matrix.hpp          # Class template declarations
├── Matrix.cpp          # Mathematical implementation rules
└── main.cpp            # Test driver program demonstrating operations
```

---

## 💻 Sample Code

```cpp
#include "Matrix.hpp"

int main() {
    // Easily initialize multi-dimensional double matrices
    Matrix<double> A = {
        {1.0, 2.0},
        {3.0, 4.0}
    };

    Matrix<double> B = {
        {5.0, 6.0},
        {7.0, 8.0}
    };

    // Perform native matrix math operations via overloaded operators
    Matrix<double> sum = A + B;       
    Matrix<double> product = A * B;   
    Matrix<double> transA = A.transpose(); 

    // Render structured results directly to console
    product.display();
}
```

---

## ⚙️ Compilation & Build Instructions

Ensure you have a modern C++ compiler (`g++` or `clang`) and `CMake` installed on your machine.

### 1. Build the Binary Executable
Navigate to your project directory inside your terminal and execute the following commands:

```bash
# Create and enter an isolated build directory
mkdir build && cd build

# Generate native configuration build files
cmake ..

# Compile the target source files
cmake --build .
```

### 2. Run the Program
*   **Linux / macOS:**
    ```bash
    ./MatrixLibrary
    ```
*   **Windows:**
    ```cmd
    Debug\MatrixLibrary.exe
    ```

---

## 📊 Core Roadmap & Future Optimizations
* [ ] **Add Scalar Operations:** Support scalar addition and multiplication transformations (e.g., `Matrix * 2`).
* [ ] **Linear Systems Tools:** Implement Determinant and Matrix Inversion calculating routines using Gaussian Elimination.
* [ ] **Automated Testing:** Integrate the GoogleTest framework to establish continuous delivery code pipelines.
* [ ] **SIMD Optimization:** Introduce compiler-level vectorized intrinsics to parallelise matrix calculations.
