#include <iostream>
#include <vector>
using namespace std;

// Function to find the next permutation of a given sequence of numbers.
void nextPermutation(vector<int> &nums)
{
    int ind = -1; // Initialize index to track the position to swap.
    int n = nums.size(); // Size of the input vector.

    // Find the largest index 'ind' such that nums[ind] < nums[ind + 1].
    // This step aims to identify the rightmost element in the sequence where a potential increase
    // can be made to generate the next lexicographically greater permutation.
    // If such an index 'ind' is not found, it implies that the entire sequence is in non-decreasing
    // order, meaning there's no greater permutation possible. In this case, we simply reverse the sequence
    // to obtain the next smallest permutation.
    for (int i = n - 2; i >= 0; i--)
    {
        if (nums[i] < nums[i + 1])
        {
            ind = i;
            break;
        }
    }

    // If 'ind' is still -1, it means the entire sequence is in descending order.
    // So, reverse the sequence to get the next smallest permutation.
    if (ind == -1)
    {
        reverse(nums.begin(), nums.end());
        return;
    }

    // Find the smallest element to the right of 'ind' that is greater than nums[ind].
    for (int i = n - 1; i >= 0; i--)
    {
        if (nums[i] > nums[ind])
        {
            // Swap nums[i] and nums[ind].
            swap(nums[i], nums[ind]);
            break;
        }
    }

    // Reverse the subsequence from 'ind + 1' to the end to get the next permutation.
    reverse(nums.begin() + ind + 1, nums.end());
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
    vector<int> nums{1, 2, 3}; // Input vector
    print(nums); // Print the original sequence
    nextPermutation(nums); // Find the next permutation
    print(nums); // Print the next permutation
    return 0;
}
