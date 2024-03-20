#include <iostream>
#include <vector>
#include <cassert>

void reverseMatrix(std::vector<std::vector<int>>& matrix) {
    int start = 0;
    int end = matrix.size() - 1;

    while (start < end) {
        std::vector<int> temp = matrix[start];
        matrix[start] = matrix[end];
        matrix[end] = temp;
        ++start;
        --end;
    }
}

bool matricesEqual(const std::vector<std::vector<int>>& matrix1, const std::vector<std::vector<int>>& matrix2) {
    if (matrix1.size() != matrix2.size()) {
        return false;
    }

    for (size_t i = 0; i < matrix1.size(); ++i) {
        if (matrix1[i] != matrix2[i]) {
            return false;
        }
    }

    return true;
}

void printMatrix(const std::vector<std::vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int elem : row) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }
}

void testReverseMatrix() {
    // Тест 1
    std::vector<std::vector<int>> matrix1 = {
        {1, 2},
        {3, 4}
    };

    std::vector<std::vector<int>> expected1 = {
        {3, 4},
        {1, 2}
    };

    printMatrix(matrix1);
    reverseMatrix(matrix1);
    assert(matricesEqual(matrix1, expected1));

    // Тест 2
    std::vector<std::vector<int>> matrix2 = {
        {-1, -2, -3},
        {-4, -5, -6},
        {-7, -8, -9}
    };

    std::vector<std::vector<int>> expected2 = {
        {-7, -8, -9},
        {-4, -5, -6},
        {-1, -2, -3}
    };

    reverseMatrix(matrix2);
    assert(matricesEqual(matrix2, expected2));

    std::vector<std::vector<int>> matrix3 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    std::vector<std::vector<int>> expected3 = {
        {7, 8, 9},
        {4, 5, 6},
        {1, 2, 3}
    };

    reverseMatrix(matrix3);
    assert(matricesEqual(matrix3, expected3));

    // Тест 3
    std::vector<std::vector<int>> matrix4 = {
        {10, 20, 30, 40},
        {50, 60, 70, 80},
        {90, 100, 110, 120},
        {130, 140, 150, 160}
    };

    std::vector<std::vector<int>> expected4 = {
        {130, 140, 150, 160},
        {90, 100, 110, 120},
        {50, 60, 70, 80},
        {10, 20, 30, 40}
    };

    reverseMatrix(matrix4);
    assert(matricesEqual(matrix4, expected4));

}


void runTests() {
    testReverseMatrix();

    std::cout << "All tests passed successfully!" << std::endl;
}

int main() {
    runTests();

    return 0;
}

