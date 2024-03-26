#include <iostream>
#include <vector>
#include <cassert>

void reverseMatrix(int** matrix, int rows) {
    int start = 0;
    int end = rows - 1;

    while (start < end) {
        int* temp = matrix[start];
        matrix[start] = matrix[end];
        matrix[end] = temp;
        ++start;
        --end;
    }
}

bool matricesEqual(int** matrix1, int** matrix2, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (matrix1[i][j] != matrix2[i][j]) {
                return false;
            }
        }
    }
    return true;
}

void printMatrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void deleteMatrix(int** matrix, int rows) {
    for (int i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void testReverseMatrix() {
    // Тест 1
    int** matrix1 = new int* [2];
    matrix1[0] = new int[2] {1, 2};
    matrix1[1] = new int[2] {3, 4};

    int** expected1 = new int* [2];
    expected1[0] = new int[2] {3, 4};
    expected1[1] = new int[2] {1, 2};

    std::cout << "Matrix 1\n";
    printMatrix(matrix1, 2, 2);
    std::cout << "Reversed matrix 1\n";
    printMatrix(expected1, 2, 2);
    reverseMatrix(matrix1, 2);
    assert(matricesEqual(matrix1, expected1, 2, 2));

    // Тест 2
    int** matrix2 = new int* [3];
    matrix2[0] = new int[3] {-1, -2, -3};
    matrix2[1] = new int[3] {-4, -5, -6};
    matrix2[2] = new int[3] {-7, -8, -9};

    int** expected2 = new int* [3];
    expected2[0] = new int[3] {-7, -8, -9};
    expected2[1] = new int[3] {-4, -5, -6};
    expected2[2] = new int[3] {-1, -2, -3};

    std::cout << "Matrix 2\n";
    printMatrix(matrix2, 3, 3);
    std::cout << "Reversed matrix 2\n";
    printMatrix(expected2, 3, 3);
    reverseMatrix(matrix2, 3);
    assert(matricesEqual(matrix2, expected2, 3, 3));

    // Тест 3
    int** matrix3 = new int* [3];
    matrix3[0] = new int[3] {1, 2, 3};
    matrix3[1] = new int[3] {4, 5, 6};
    matrix3[2] = new int[3] {7, 8, 9};

    int** expected3 = new int* [3];
    expected3[0] = new int[3] {7, 8, 9};
    expected3[1] = new int[3] {4, 5, 6};
    expected3[2] = new int[3] {1, 2, 3};

    std::cout << "Matrix 3\n";
    printMatrix(matrix3, 3, 3);
    std::cout << "Reversed matrix 3\n";
    printMatrix(expected3, 3, 3);
    reverseMatrix(matrix3, 3);
    assert(matricesEqual(matrix3, expected3, 3, 3));

    // Тест 4
    int** matrix4 = new int* [4];
    matrix4[0] = new int[4] {10, 20, 30, 40};
    matrix4[1] = new int[4] {50, 60, 70, 80};
    matrix4[2] = new int[4] {90, 100, 110, 120};
    matrix4[3] = new int[4] {130, 140, 150, 160};

    int** expected4 = new int* [4];
    expected4[0] = new int[4] {130, 140, 150, 160};
    expected4[1] = new int[4] {90, 100, 110, 120};
    expected4[2] = new int[4] {50, 60, 70, 80};
    expected4[3] = new int[4] {10, 20, 30, 40};

    std::cout << "Matrix 4\n";
    printMatrix(matrix4, 4, 4);
    std::cout << "Reversed matrix 4\n";
    printMatrix(expected4, 4, 4);
    reverseMatrix(matrix4, 4);
    assert(matricesEqual(matrix4, expected4, 4, 4));

    deleteMatrix(matrix1, 2);
    deleteMatrix(matrix2, 3);
    deleteMatrix(matrix3, 3);
    deleteMatrix(matrix4, 4);

    deleteMatrix(expected1, 2);
    deleteMatrix(expected2, 3);
    deleteMatrix(expected3, 3);
    deleteMatrix(expected4, 4);
}

void runTests() {
    testReverseMatrix();

    std::cout << "All tests passed successfully!" << std::endl;
}

int** inputMatrix(int& rows, int& cols) {
    std::cout << "Input amount of rows: ";
    std::cin >> rows;
    std::cout << "Input amount of columns: ";
    std::cin >> cols;

    int** matrix = new int* [rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new int[cols];
    }

    std::cout << "Input elements:" << std::endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cin >> matrix[i][j];
        }
    }

    return matrix;
}

int main() {
    runTests();

    int rows, cols;
    int** matrix = inputMatrix(rows, cols);

    std::cout << "Matrix:" << std::endl;
    printMatrix(matrix, rows, cols);

    reverseMatrix(matrix, rows);

    std::cout << "\nReversed matrix:" << std::endl;
    printMatrix(matrix, rows, cols);

    deleteMatrix(matrix, rows);

    return 0;
}

