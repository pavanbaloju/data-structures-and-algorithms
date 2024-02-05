#include <iostream>
#include <vector>
using namespace std;

// Function to remove duplicates from a sorted array
// Intuition:
// Since the array is sorted, duplicates will be adjacent to each other.
// We can use a pointer to keep track of the next position to store a non-duplicate element.
// As we traverse the array, if the current element is not equal to the previous one,
// we store it in the next position.
// Approach:
// 1. Initialize a pointer 'j' to 1, representing the next position to store a non-duplicate element.
// 2. Iterate through the array from the second element.
// 3. If the current element is different from the previous one,
//    store it in the position indicated by 'j' and increment 'j'.
// 4. Finally, return the value of 'j', which represents the size of the array without duplicates.
// Time Complexity: O(n), where n is the size of the input array.
// Space Complexity: O(1), as we are modifying the input array in-place.

int removeDuplicates(vector<int> &nums)
{
    int j = 1; // Pointer for the next position to store a non-duplicate element
    int count = nums.size();
    for (int i = 1; i < count; i++)
    {
        // If the current element is different from the previous one,
        // store it in the position indicated by 'j' and increment 'j'.
        if (nums[i] != nums[i - 1])
        {
            nums[j] = nums[i];
            j++;
        }
    }
    return j; // Return the size of the array without duplicates
}

int main()
{
    // Test case
    vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int k = removeDuplicates(nums);
    // Output the array after removing duplicates
    for (int i = 0; i < k; i++)
    {
        cout << nums[i] << " ";
    }
    return 0;
}
