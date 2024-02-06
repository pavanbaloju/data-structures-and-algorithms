#include <iostream>
#include <vector>
using namespace std;

// Function to sort an array such that even numbers appear before odd numbers.
// Intuition:
// We use a two-pointer approach where one pointer (left) starts from the beginning of the array
// and another pointer (right) starts from the end of the array. We iterate until the left pointer
// crosses the right pointer. At each step, we check if the left element is odd and the right
// element is even. If so, we swap them. Otherwise, we move the left pointer forward if the left
// element is even, and move the right pointer backward if the right element is odd.
// Time complexity: O(n), where n is the size of the input array.
// Space complexity: O(1), no extra space used besides variables.
vector<int> sortArrayByParity(vector<int> &nums)
{
    // Initialize two pointers at the start and end of the array
    int left = 0, right = nums.size() - 1;

    // Iterate until the two pointers meet
    while (left < right)
    {
        // If the left element is odd and the right element is even, swap them
        if (nums[left] % 2 == 1 && nums[right] % 2 == 0)
        {
            swap(nums[left], nums[right]);
            left++; // Move left pointer forward
            right--; // Move right pointer backward
        }
        else
        {
            // If the left element is even, move left pointer forward
            if (nums[left] % 2 == 0)
            {
                left++;
            }
            // If the right element is odd, move right pointer backward
            if (nums[right] % 2 == 1)
            {
                right--;
            }
        }
    }
    // Return the sorted array
    return nums;
}

int main()
{
    // Test the function with an example array.
    vector<int> arr = {5, 2, 3, 1, 2, 4};
    sortArrayByParity(arr);

    // Output the sorted array.
    for (int a : arr)
        cout << a << " ";
    return 0;
}
