#include <iostream>
#include <vector>
using namespace std;

// Function to calculate combination (nCr) using Pascal's triangle logic.
int nCr(int N, int R)
{
    long long res = 1;

    // Calculate nCr using the formula nCr = (N * (N - 1) * ... * (N - R + 1)) / (1 * 2 * ... * R)
    for (int r = 0; r < R; r++)
    {
        res = res * (N - r);
        res = res / (r + 1);
    }
    return res;
}

// Function to get the element at a specific position (r, c) in Pascal's Triangle.
int pascalTriangle(int r, int c)
{
    return nCr(r - 1, c - 1); // Call nCr to get the element at position (r, c).
}

// Function to generate a single row of Pascal's Triangle.
vector<int> generateRow(int N)
{
    vector<int> row{1}; // Initialize the row with 1 as the first element.

    // Generate the remaining elements of the row using combination logic.
    int ans = 1;
    for (int r = 1; r < N; r++)
    {
        ans = ans * (N - r);
        ans = ans / r;
        row.push_back(ans);
    }

    return row;
}

// Function to generate Pascal's Triangle up to the nth row.
vector<vector<int>> pascalTriangle(int n)
{
    vector<vector<int>> ans; // Initialize the vector to store Pascal's Triangle.

    // Generate each row of Pascal's Triangle and add it to the answer.
    for (int row = 1; row <= n; row++)
        ans.push_back(generateRow(row));

    return ans;
}

// Function to print a vector.
void print(vector<int> &nums)
{
    for (int x : nums)
        cout << x << " "; // Print each element separated by space.
    cout << endl;
}

// Main function
int main()
{
    int r = 5; // Row number
    int c = 3; // Column number

    // Calculate and print the element at position (r, c) in Pascal's Triangle.
    int element = pascalTriangle(r, c);
    cout << "The element at position (r, c) is: " << element << endl << endl;

    // Generate and print a specific row of Pascal's Triangle.
    vector<int> row = generateRow(5);
    print(row);
    cout << endl;

    // Generate and print Pascal's Triangle up to the 5th row.
    vector<vector<int>> pt = pascalTriangle(5);
    for (auto row : pt)
        print(row);

    return 0;
}
