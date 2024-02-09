#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

// Function to find the length of the largest subarray with sum equal to zero using brute-force approach.
// Intuition:
// This function aims to find the longest subarray with a sum of zero. It utilizes a brute-force approach
// involving two nested loops to consider all possible subarrays starting from each index.
// Approach:
// 1. Initialize a variable `maxLen` to store the maximum length of subarrays with sum equal to zero.
// 2. Outer loop iterates through each element as a potential start of the subarray.
// 3. Inner loop calculates the sum of subarrays starting from the current index.
// 4. If the sum of any subarray becomes zero, update `maxLen` with the maximum length.
// 5. Return the `maxLen`.
// Time complexity: O(n^2) - Two nested loops iterate through the input array.
// Space complexity: O(1) - Only a few variables are used, independent of the input size.

int largest(vector<int> &nums)
{
    int maxLen = 0; // Initialize max length of subarray with sum equal to zero

    for (int i = 0; i < nums.size(); i++) // Outer loop to iterate through each element
    {
        int sum = 0; // Initialize sum for the current subarray

        for (int j = i; j < nums.size(); j++) // Inner loop to iterate through elements starting from the current index
        {
            sum += nums[j]; // Add the current element to the sum

            if (sum == 0) // If the sum becomes zero, update the maximum length
            {
                maxLen = max(maxLen, j - i + 1); // Update maxLen with the maximum length of the current subarray
            }
        }
    }

    return maxLen; // Return the maximum length of subarrays with sum equal to zero
}

// Function to find the length of the largest subarray with sum zero using an optimized approach.
// Intuition:
// This function follows a similar approach to the brute force method but uses a hashmap for efficient lookup.
// Approach:
// 1. Maintain a running sum while iterating through the array.
// 2. Use a hashmap to store the earliest index at which a particular sum occurred.
// 3. Update the maximum length when encountering a sum that was seen before.
// 4. Return the maximum length.
// Time complexity: O(n), where n is the size of the input array.
// Space complexity: O(n), additional space used to store indices in the hashmap.
int largestOpt(vector<int> &nums)
{
    int n = nums.size();
    unordered_map<int, int> mpp; // Map to store the sum and its corresponding index
    int maxi = 0;                // Variable to track the maximum length
    int sum = 0;

    for (int i = 0; i < n; i++) // Loop through the input array
    {
        sum += nums[i]; // Add the current element to the running sum

        if (sum == 0) // If the sum is zero, update the maximum length
        {
            maxi = i + 1;
        }
        else // If the sum is not zero
        {
            if (mpp.find(sum) != mpp.end()) // If the current sum has been seen before
            {
                maxi = max(maxi, i - mpp[sum]); // Update the maximum length if needed
            }
            else // If encountering a new sum, store its index in the map
            {
                mpp[sum] = i;
            }
        }
    }

    return maxi; // Return the maximum length of the subarray with sum zero
}

int main()
{
    vector<int> nums = {9, -3, 3, -1, 6, -5}; // Example input array
    cout << largest(nums) << endl;            // Output the result of the brute force approach
    cout << largestOpt(nums) << endl;         // Output the result of the optimized approach

    return 0;
}
