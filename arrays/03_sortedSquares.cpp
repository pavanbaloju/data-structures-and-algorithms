#include <iostream>
#include <vector>
using namespace std;
// Function to return an array of squares of sorted elements from another array.
// Interview Revision Notes:
// This problem can be solved by using two pointers starting from the ends of the array.
// We compare the absolute values of elements at both pointers and fill the result array from the end.
// Time Complexity: O(n), where n is the size of the input array.
// Space Complexity: O(n), additional space is used for the result array.
vector<int> sortedSquares(vector<int> &A)
{
    vector<int> res(A.size()); // Initialize result array.

    int l = 0, r = A.size() - 1; // Pointers to the start and end of the input array.

    // Iterate through the input array from end to start.
    for (int k = A.size() - 1; k >= 0; k--)
    {
        // Compare absolute values of elements at pointers.
        if (abs(A[r]) > abs(A[l]))
        {
            res[k] = A[r] * A[r]; // Square the element at the right pointer and store it in the result array.
            r--; // Move the right pointer to the left.
        }
        else
        {
            res[k] = A[l] * A[l]; // Square the element at the left pointer and store it in the result array.
            l++; // Move the left pointer to the right.
        }
    }

    return res; // Return the result array.
}


int main()
{
    vector<int> nums = {-7, -3, 2, 3, 11};
    vector<int> res = sortedSquares(nums);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }

    return 0;
}