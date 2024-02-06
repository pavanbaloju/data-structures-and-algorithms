#include <iostream>
#include <vector>
using namespace std;

// Function to find the pivot index in an array.
// A pivot index in an array is an index such that 
// the sum of all elements to the left of it is equal to the sum of all elements to the right of it. 
// If there is no such index, the function returns -1.
// Intuition:
// The strategy used here is the prefix sum approach
// We calculate the total sum of all elements in the array.
// Then, we iterate through the array, keeping track of the left sum.
// At each iteration, if the total sum minus the current element equals twice the left sum,
// it means we have found the pivot index.
// If no such index is found, we return -1.
// Time complexity: O(n), where n is the size of the input array.
// Space complexity: O(1), no extra space used besides variables.
int pivotIndex(vector<int> &nums)
{
    int totalSum = 0, leftSum = 0, count = nums.size();

    // Calculate the total sum of all elements in the array.
    for (int i = 0; i < count; i++)
    {
        totalSum += nums[i];
    }

    // Iterate through the array to find the pivot index.
    for (int i = 0; i < count; i++)
    {
        if (totalSum - nums[i] == 2 * leftSum)
        {
            return i;
        }
        else
        {
            leftSum += nums[i];
        }
    }
    return -1; // Return -1 if no pivot index is found.
}

int main()
{
    vector<int> nums = {1, 7, 3, 6, 5, 6};
    int p = pivotIndex(nums);
    cout << p;
    return 0;
}
