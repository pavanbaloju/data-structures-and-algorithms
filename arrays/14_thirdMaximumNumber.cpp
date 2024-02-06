#include <iostream>
#include <vector>
#include <limits.h> // Required for numeric_limits
using namespace std;

// Function to find the third maximum element in an array.
// Intuition:
// We initialize three variables to store the first, second, and third maximum elements.
// We iterate through the array and update these variables accordingly.
// After the iteration, if the third maximum is still equal to its initial value,
// it means that there is no distinct third maximum, so we return the first maximum.
// Time complexity: O(n), where n is the size of the input array.
// Space complexity: O(1), no extra space used besides variables.
int thirdMax(vector<int> &nums)
{
    long long first = LLONG_MIN;  // Initialize first maximum to the smallest possible value
    long long second = LLONG_MIN; // Initialize second maximum to the smallest possible value
    long long third = LLONG_MIN;  // Initialize third maximum to the smallest possible value
    int count = nums.size();      // Number of elements in the array

    // Iterate through the array to find the first, second, and third maximum elements
    for (int i = 0; i < count; i++)
    {
        if (nums[i] == first || nums[i] == second || nums[i] == third)
        {
            continue; // Skip if the element is already one of the maximums
        }
        else if (nums[i] > first)
        {
            // Update first, second, and third maximums accordingly
            third = second;
            second = first;
            first = nums[i];
        }
        else if (nums[i] > second)
        {
            // Update second and third maximums accordingly
            third = second;
            second = nums[i];
        }
        else if (nums[i] > third)
        {
            // Update third maximum accordingly
            third = nums[i];
        }
    }

    // Check if there is no distinct third maximum
    if (third == LLONG_MIN)
    {
        return first; // Return the first maximum
    }
    else
    {
        return third; // Return the distinct third maximum
    }
}

int main()
{
    // Test the function with an example array
    vector<int> nums = {2, 2, 3, 1};
    cout << thirdMax(nums) << endl; // Output the result
    return 0;
}
