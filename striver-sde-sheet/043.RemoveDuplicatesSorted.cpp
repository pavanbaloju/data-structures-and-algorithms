#include <iostream>
#include <vector>
using namespace std;

// Problem Statement:
// Given a sorted array, remove the duplicates in-place such that each unique element appears only once.
// Return the new length of the array after removing duplicates.

// Method: Remove Duplicates in Sorted Array
// Approach:
// - Use two pointers: one to iterate through the array and the other to keep track of the next unique element position.
// - Iterate through the array and compare each element with the previous one.
// - If the current element is different from the previous one, copy it to the next unique element position.
// - Increment the next unique element position pointer.
// - Repeat this process until all duplicates are removed.
// - The length of the array after removing duplicates is the position of the next unique element pointer.
// Time Complexity: O(n), where n is the length of the input array.
// Space Complexity: O(1), as the operation is performed in-place without using any extra space.

int removeDuplicates(vector<int> &nums)
{
    int j = 1; // Pointer for next unique element position

    // Iterate through the array starting from the second element
    for (int i = 1; i < nums.size(); i++)
    {
        // If the current element is different from the previous one, copy it to the next unique element position
        if (nums[i] != nums[i - 1])
        {
            nums[j++] = nums[i]; // Copy the current element to the next unique element position and increment the pointer
        }
    }

    return j; // Return the position of the next unique element pointer as the new length of the array
}

int main()
{
    // Input sorted array with duplicates
    vector<int> nums1 = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};

    // Call the removeDuplicates function to remove duplicates in-place
    int newLength = removeDuplicates(nums1);

    // Output the new length of the array
    cout << "New length after removing duplicates: " << newLength << endl;

    // Output the modified array after removing duplicates
    cout << "Modified array: ";
    for (int i = 0; i < newLength; i++)
    {
        cout << nums1[i] << " ";
    }
    cout << endl;

    return 0;
}
