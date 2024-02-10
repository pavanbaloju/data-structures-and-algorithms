#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Function to count the number of subarrays with XOR sum equal to 'k' using brute-force approach.
// Intuition:
// This function aims to count the number of subarrays with XOR sum equal to 'k'. It utilizes a brute-force approach
// involving two nested loops to consider all possible subarrays and calculate their XOR sums.
// Approach:
// 1. Initialize a variable `count` to store the count of subarrays with XOR sum equal to 'k'.
// 2. Outer loop iterates through each element as a potential start of the subarray.
// 3. Inner loop calculates the XOR sum of subarrays starting from the current index.
// 4. If the XOR sum of any subarray becomes 'k', increment the `count`.
// 5. Return the `count`.
// Time complexity: O(n^2) - Two nested loops iterate through the input array.
// Space complexity: O(1) - Only a few variables are used, independent of the input size.

int countSubarraySumXORBrute(vector<int> &nums, int k)
{
    int count = 0; // Initialize count of subarrays with XOR sum equal to 'k'
    int n = nums.size(); // Get the size of the input array

    for (int i = 0; i < n; i++) // Outer loop to iterate through each element
    {
        int sum = 0; // Initialize XOR sum for the current subarray

        for (int j = i; j < n; j++) // Inner loop to iterate through elements starting from the current index
        {
            sum ^= nums[j]; // XOR the current element to the sum

            if (sum == k) // If the XOR sum becomes 'k', increment the count
            {
                count++; // Increment count for subarrays with XOR sum equal to 'k'
            }
        }
    }

    return count; // Return the count of subarrays with XOR sum equal to 'k'
}

// Function to count the number of subarrays with XOR sum equal to 'k' using optimized approach.
// Intuition:
// This function aims to count the number of subarrays with XOR sum equal to 'k'. It utilizes an optimized approach
// involving prefix XOR sums and a hash map to efficiently calculate the count.
// Approach:
// 1. Initialize a variable `count` to store the count of subarrays with XOR sum equal to 'k'.
// 2. Initialize a variable `prefixXR` to track the prefix XOR sum of elements encountered so far.
// 3. Initialize an unordered map `sumAndCount` to store prefix XOR sum frequencies encountered.
// 4. Insert the initial prefix XOR sum of 0 with frequency 1 into the map.
// 5. Iterate through the array:
//    a. Update the `prefixXR` by XORing the current element.
//    b. If the XOR of the current prefix sum and 'k' exists in the map, increment `count` by the frequency of that XOR.
//    c. Increment the frequency of the current prefix XOR sum in the map.
// 6. Return the `count`.
// Time complexity: O(n) - Single pass through the input array.
// Space complexity: O(n) - Additional space used to store prefix XOR sums and their frequencies in the map.

int countSubarraySumXOROpt(vector<int> &nums, int k)
{
    int count = 0; // Initialize count of subarrays with XOR sum equal to 'k'
    int prefixXR = 0; // Initialize prefix XOR sum
    int n = nums.size(); // Get the size of the input array
    unordered_map<int, int> sumAndCount; // Create a hash map to store prefix XOR sum frequencies
    sumAndCount[0] = 1; // Initialize the map with prefix XOR sum 0 and frequency 1

    for (int i = 0; i < n; i++) // Iterate through the array
    {
        prefixXR ^= nums[i]; // Update prefix XOR sum with the XOR of the current element
        count += sumAndCount[prefixXR ^ k]; // Increment count with frequency of (prefixXR ^ k) if exists in map
        sumAndCount[prefixXR] += 1; // Increment frequency of current prefix XOR sum in the map
    }

    return count; // Return the count of subarrays with XOR sum equal to 'k'
}

int main()
{
    vector<int> nums{4, 2, 2, 6, 4}; // Example input array
    cout << "Brute Force: " << countSubarraySumXORBrute(nums, 6) << endl; // Output result using brute-force approach
    cout << "Optimized: " << countSubarraySumXOROpt(nums, 6) << endl; // Output result using optimized approach
    return 0;
}
