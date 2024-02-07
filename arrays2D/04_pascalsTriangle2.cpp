#include <iostream>
#include <vector>
using namespace std;

// Problem Statement:
// Given an index rowIndex, return the nth (0-indexed) row of the Pascal's triangle.

// Function to generate the specified row of Pascal's triangle.
// Intuition:
// - Each row of Pascal's triangle consists of binomial coefficients (n choose k), where n is the row number and k is the position in the row.
// - The binomial coefficient can be calculated using the formula: C(n, k) = C(n-1, k-1) + C(n-1, k).
// - To generate the nth row, we can start with a row of all 1s and iteratively update the values based on the binomial coefficient formula.
// Approach:
// - Initialize a vector 'row' with rowIndex + 1 elements, all initialized to 1.
// - Iterate from the second row to the rowIndex:
//     - Update the elements of the current row using the binomial coefficient formula.
//     - Start updating from the end of the row to avoid overwriting values needed for the calculation.
// Time complexity: O(rowIndex^2), where rowIndex is the index of the row to generate.
//   - We update each element of the row using the binomial coefficient formula.
// Space complexity: O(rowIndex), where rowIndex is the index of the row to generate.
//   - Additional space is required to store the elements of the generated row.
vector<int> getRow(int n) {
    vector<int> row(n + 1, 1); // Initialize row with rowIndex + 1 elements, all set to 1.

    // Generate the specified row of Pascal's triangle.
    for (int r = 1; r < n; r++) {
        // Update the elements of the current row using the binomial coefficient formula.
        // Start updating from the end of the row to avoid overwriting values needed for the calculation.
        for (int col = r; col > 0; col--) {
            row[col] += row[col - 1]; // Calculate binomial coefficient and update the current element.
        }
    }
    return row; // Return the generated row.
}

int main() {
    int rowIndex = 5; // Index of the row to generate.
    vector<int> row = getRow(rowIndex); // Generate the specified row of Pascal's triangle.
    
    // Output the generated row.
    for (int x : row) {
        cout << x << " "; // Output each element of the generated row.
    }
    return 0;
}
