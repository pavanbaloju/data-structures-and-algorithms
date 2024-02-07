#include <iostream>
#include <vector>
#include <map>
using namespace std;

// Function to find the majority element using a brute-force approach.
// Intuition:
// The function iterates through each element in the array and counts its occurrences.
// If any element appears more than n/2 times (where n is the size of the array), it is the majority element.
// Time complexity: O(n^2), where n is the size of the input array.
// Space complexity: O(1), no extra space used besides variables.
int majorityElementBrute(vector<int> nums)
{
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        int cnt = 0;
        // Iterate through the array to count occurrences of nums[i].
        for (int j = 0; j < n; j++)
        {
            if (nums[j] == nums[i])
            {
                cnt++;
            }
        }

        // If the count is greater than n/2, nums[i] is the majority element.
        if (cnt > (n / 2))
            return nums[i];
    }

    return -1;
}

// Function to find the majority element using a hash map.
// Intuition:
// The function uses a hash map to store the frequency of each element.
// If any element appears more than n/2 times (where n is the size of the array), it is the majority element.
// Time complexity: O(n), where n is the size of the input array.
// Space complexity: O(n), to store the frequencies of elements in the hash map.
int majorityElementHash(vector<int> &nums)
{
    map<int, int> m;
    // Iterate through the array to count occurrences of each element.
    for (int num : nums)
    {
        m[num]++;
        // If any element appears more than n/2 times, it is the majority element.
        if (m[num] > nums.size() / 2)
        {
            return num;
        }
    }
    return 0;
}

// Function to find the majority element using Moore's Voting Algorithm.
// Intuition:
// Correctness: The algorithm's correctness relies on the fact that if there is a majority element, 
// it will survive the process of pairing with other elements (incrementing and decrementing the count) 
// and remain as the final candidate. 
// This is because the majority element will always have a count greater than zero after processing all elements in the array.
// The function iterates through the array and maintains a candidate and its count.
// If the count reaches zero, a new candidate is selected.
// At the end, the last candidate is checked if it appears more than n/2 times (where n is the size of the array).
// Time complexity: O(n), where n is the size of the input array.
// Space complexity: O(1), no extra space used besides variables.
int majorityElement(vector<int> &nums)
{
    int count = 0; // Initialize the count of the current candidate.
    int candidate = -1; // Initialize the candidate for the majority element.

    // Iterate through the array to find the majority element candidate.
    for (int num : nums)
    {
        // If the count is zero, update the candidate to the current number.
        if (count == 0)
        {
            candidate = num;
        }

        // Increment the count if the current number matches the candidate.
        if (candidate == num)
        {
            count++;
        }
        // Decrement the count if the current number does not match the candidate.
        else
        {
            count--;
        }
    }

    return candidate; // Return the majority element candidate.
}


// Main function to test the majority element functions.
int main()
{
    // Test cases to find the majority element using different approaches.
    vector<int> nums1 = {2, 2, 1, 1, 1, 2, 2};
    cout << majorityElementBrute(nums1) << endl;
    cout << majorityElementHash(nums1) << endl;
    cout << majorityElement(nums1) << endl;
    return 0;
}
