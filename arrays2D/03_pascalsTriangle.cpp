#include <iostream>
#include <vector>
using namespace std;

// Problem Statement:
// Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.

// Function to generate Pascal's triangle up to the specified number of rows.
// Intuition:
// - Each row of Pascal's triangle consists of binomial coefficients (n choose k), where n is the row number and k is the position in the row.
// - The binomial coefficient can be calculated using the formula: C(n, k) = C(n-1, k-1) + C(n-1, k).
// Approach:
// - Initialize a 2D vector 'pt' to store Pascal's triangle.
// - Iterate from row 0 to numRows-1:
//     - Initialize each row with size equal to the row number + 1.
//     - Fill the boundary elements with 1.
//     - For the inner elements, use the binomial coefficient formula to calculate the value.
// Time complexity: O(numRows^2), where numRows is the number of rows to generate.
//   - We generate each element of Pascal's triangle once.
// Space complexity: O(numRows^2), where numRows is the number of rows to generate.
//   - Additional space is required to store Pascal's triangle.
vector<vector<int>> generate(int numRows) {
    vector<vector<int>> pt(numRows); // Initialize Pascal's triangle vector with numRows rows.

    // Generate each row of Pascal's triangle.
    for (int row = 0; row < numRows; row++) {
        pt[row].resize(row + 1, 1); // Resize the current row to the appropriate size and fill with 1.

        // Calculate the inner elements of the row using the binomial coefficient formula.
        for (int col = 1; col < row; col++) {
            pt[row][col] = pt[row - 1][col - 1] + pt[row - 1][col]; // Calculate binomial coefficient.
        }
    }
    return pt; // Return Pascal's triangle.
}

int main() {
    int numRows = 5; // Number of rows to generate for Pascal's triangle.
    vector<vector<int>> pt = generate(numRows); // Generate Pascal's triangle.
    
    // Output Pascal's triangle.
    for (int i = 0; i < pt.size(); i++) {
        for (int j = 0; j < pt[i].size(); j++) {
            cout << pt[i][j] << " "; // Output each element of Pascal's triangle.
        }
        cout << endl; // Move to the next row.
    }
    return 0;
}
