#include <iostream>
#include <vector>
#include <algorithm> // Required for sort function
using namespace std;

// Function to count the number of students who have heights not in the correct order.
// Intuition:
// We create a copy of the input array and sort it in non-decreasing order.
// Then, we iterate through both arrays simultaneously and count the number of positions
// where the heights don't match.
// Time complexity: O(n log n) for sorting, where n is the number of elements in the input array.
// Space complexity: O(n) for the copy of the input array.
int heightChecker(vector<int> &heights)
{
    // Create a copy of the input array and sort it
    vector<int> expected = heights;
    sort(expected.begin(), expected.end());

    int count = 0;
    // Compare the heights in the original and sorted arrays
    for (int i = 0; i < heights.size(); i++)
    {
        if (heights[i] != expected[i])
        {
            count++;
        }
    }
    return count;
}

int main()
{
    // Test the function with an example array
    vector<int> arr = {1, 1, 4, 2, 1, 3};
    cout << heightChecker(arr) << endl; // Output the result
    return 0;
}
