#include <iostream>
#include <vector>
using namespace std;

// Function to check if the given array forms a valid mountain
// array according to the problem statement.
// Intuition:
// We traverse the array to find the peak of the mountain. Then, we check if
// there are increasing and decreasing sequences on both sides of the peak.
// Approach:
// 1. Check if the array has at least 3 elements. If not, it can't form a
//    valid mountain array, so return false.
// 2. Traverse from left to right until we find the peak of the mountain
//    (the point where the elements stop increasing).
// 3. If there is no increasing sequence before the peak or no decreasing
//    sequence after the peak, return false.
// 4. Otherwise, return true.
// Time complexity: O(n), where n is the number of elements in the array.
// Space complexity: O(1), no extra space used.
bool validMountainArray(vector<int> &arr)
{
    int count = arr.size();
    if (count < 3)
    {
        return false;
    }
    int i = 1;
    // Find the peak of the mountain
    for (; i < count; i++)
    {
        if (arr[i] <= arr[i - 1])
        {
            break;
        }
    }
    if (i == count || i == 1)
    {
        return false;
    }
    // Check if there is a decreasing sequence after the peak
    for (; i < count; i++)
    {
        if (arr[i] >= arr[i - 1])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    // Test the function
    vector<int> nums = {0, 3, 4, 5, 2, 1, 0};
    cout << validMountainArray(nums);
    return 0;
}
