#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Function to count the number of subarrays with a given sum using brute-force approach.
// Intuition:
// This function aims to count the number of subarrays with a given sum 'k'. It utilizes a brute-force approach
// involving two nested loops to consider all possible subarrays and calculate their sums.
// Approach:
// 1. Initialize a variable `count` to store the count of subarrays with sum equal to 'k'.
// 2. Outer loop iterates through each element as a potential start of the subarray.
// 3. Inner loop calculates the sum of subarrays starting from the current index.
// 4. If the sum of any subarray becomes 'k', increment the `count`.
// 5. Return the `count`.
// Time complexity: O(n^2) - Two nested loops iterate through the input array.
// Space complexity: O(1) - Only a few variables are used, independent of the input size.

int countSubarraySumBrute(vector<int> &nums, int k)
{
    int count = 0; // Initialize count of subarrays with sum equal to 'k'
    int n = nums.size(); // Get the size of the input array

    for (int i = 0; i < n; i++) // Outer loop to iterate through each element
    {
        int sum = 0; // Initialize sum for the current subarray

        for (int j = i; j < n; j++) // Inner loop to iterate through elements starting from the current index
        {
            sum += nums[j]; // Add the current element to the sum

            if (sum == k) // If the sum becomes 'k', increment the count
            {
                count++; // Increment count for subarrays with sum equal to 'k'
            }
        }
    }

    return count; // Return the count of subarrays with sum equal to 'k'
}

// Function to count the number of subarrays with a given sum using optimized approach.
// Intuition:
// This function aims to count the number of subarrays with a given sum 'k'. It utilizes an optimized approach
// involving prefix sums and a hash map to efficiently calculate the count.
// Approach:
// 1. Initialize a variable `count` to store the count of subarrays with sum equal to 'k'.
// 2. Initialize a variable `prefixSum` to track the prefix sum of elements encountered so far.
// 3. Initialize an unordered map `sumAndCount` to store prefix sum frequencies encountered.
// 4. Insert the initial prefix sum of 0 with frequency 1 into the map.
// 5. Iterate through the array:
//    a. Update the `prefixSum` by adding the current element.
//    b. If the difference between the current prefix sum and 'k' exists in the map, increment `count` by the frequency of that difference.
//    c. Increment the frequency of the current prefix sum in the map.
// 6. Return the `count`.
// Time complexity: O(n) - Single pass through the input array.
// Space complexity: O(n) - Additional space used to store prefix sums and their frequencies in the map.

int countSubarraySumOpt(vector<int> &nums, int k)
{
    int count = 0; // Initialize count of subarrays with sum equal to 'k'
    int prefixSum = 0; // Initialize prefix sum
    int n = nums.size(); // Get the size of the input array
    unordered_map<int, int> sumAndCount; // Create a hash map to store prefix sum frequencies
    sumAndCount[0] = 1; // Initialize the map with prefix sum 0 and frequency 1

    for (int i = 0; i < n; i++) // Iterate through the array
    {
        prefixSum += nums[i]; // Update prefix sum with the current element
        count += sumAndCount[prefixSum - k]; // Increment count with frequency of (prefixSum - k) if exists in map
        sumAndCount[prefixSum] += 1; // Increment frequency of current prefix sum in the map
    }

    return count; // Return the count of subarrays with sum equal to 'k'
}

int main()
{
    vector<int> nums{1, 1, 1}; // Example input array
    cout << countSubarraySumBrute(nums, 2) << endl; // Output result using brute-force approach
    cout << countSubarraySumOpt(nums, 2) << endl; // Output result using optimized approach
    return 0;
}
