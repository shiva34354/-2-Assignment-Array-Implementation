#include <iostream>
#include <vector>
#include <tuple>

class SparseMatrix {
private:
    int rows, cols;
    std::vector<std::tuple<int, int, int>> elements; // Store (row, col, value)

public:
    SparseMatrix(int r, int c) : rows(r), cols(c) {}

    void insert(int r, int c, int value) {
        if (r >= rows || c >= cols || r < 0 || c < 0) {
            std::cout << "Error: Index out of bounds.\n";
            return;
        }
        if (value != 0) {
            elements.push_back(std::make_tuple(r, c, value));
        }
    }

    void display() {
        std::cout << "Row\tCol\tValue\n";
        for (const auto& element : elements) {
            std::cout << std::get<0>(element) << "\t" 
                      << std::get<1>(element) << "\t" 
                      << std::get<2>(element) << "\n";
        }
    }
};

int main() {
    SparseMatrix matrix(4, 5); // Creating a 4x5 sparse matrix
    matrix.insert(0, 1, 5);
    matrix.insert(1, 3, 10);
    matrix.insert(3, 2, 15);

    matrix.display();
    return 0;
}
