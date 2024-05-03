#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Problem Statement:
// Given an array 'nums' of n integers, find all unique triplets in the array which gives the sum of zero.

// Intuition:
// We'll use the two pointers technique to solve this problem.
// Sort the input array to simplify the two pointers technique.
// Iterate through the array and use two pointers to find the remaining two elements that sum up to the negative of the current element.
// Skip duplicate elements to avoid duplicate triplets.

// DSA Strategy/Pattern:
// Two Pointers

// Function to find all unique triplets in the array that sum up to zero using the two pointers technique
vector<vector<int>> threeSum(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> res;
    sort(nums.begin(), nums.end()); // Sort the input array to simplify the two pointers technique

    // Iterate through the array
    for (int i = 0; i < n; ++i)
    {
        // Skip duplicate elements to avoid duplicate triplets
        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        // Set two pointers (left and right) for two pointers technique
        int left = i + 1;
        int right = n - 1;
        int target = -nums[i]; // Calculate the target value

        // Two pointers technique
        while (left < right)
        {
            if (nums[left] + nums[right] == target)
            {
                res.push_back({nums[i], nums[left], nums[right]}); // Found a triplet

                // Skip duplicate elements to avoid duplicate triplets
                while (left < right && nums[left] == nums[left + 1])
                    left++;
                while (left < right && nums[right] == nums[right - 1])
                    right--;

                left++;
                right--;
            }
            else if (nums[left] + nums[right] < target)
            {
                left++; // Move the left pointer
            }
            else
            {
                right--; // Move the right pointer
            }
        }
    }
    return res;
}

// Function to print a vector of vectors
void print(vector<vector<int>> nums)
{
    for (vector<int> v : nums)
    {
        for (int x : v)
            cout << x << " ";
        cout << endl;
    }
    cout << endl;
}

int main()
{
    // Example usage
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> res = threeSum(nums); // Find all unique triplets
    print(res);                               // Output the result
    return 0;
}
