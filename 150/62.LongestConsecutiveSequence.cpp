#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

// Function to find the length of the longest consecutive elements sequence in the array.
// Intuition:
// This function aims to find the longest consecutive sequence of elements in the array.
// Approach:
// 1. Sort the array (optional, not used in the last approach).
// 2. Initialize variables to track the current sequence length and the longest sequence length.
// 3. Iterate through the array:
//    a. If the current element is one greater than the previous element, increment the current sequence length.
//    b. If the current element is different from the previous element, reset the current sequence length to 1.
//    c. Update the longest sequence length as necessary.
// 4. Return the longest sequence length.
// Time complexity: O(n log n) for the sorting approach, O(n) for the other approaches, where n is the size of the input array.
// Space complexity: O(n) for the set-based approach, O(1) for the sorting and direct iteration approaches.
int longestConsecutive(vector<int> &nums)
{
    int n = nums.size();
    if (n == 0)
        return 0;

    sort(nums.begin(), nums.end());
    int lastSmaller = INT_MIN;
    int count = 0;
    int longest = 1;

    // Loop through the sorted array to find the longest consecutive sequence.
    for (int i = 0; i < n; i++)
    {
        // If the current element is one greater than the previous element,
        // increment the current sequence length.
        if (nums[i] - 1 == lastSmaller)
        {
            count += 1;
            lastSmaller = nums[i];
        }
        // If the current element is different from the previous element,
        // reset the current sequence length to 1.
        else if (nums[i] != lastSmaller)
        {
            count = 1;
            lastSmaller = nums[i];
        }
        // Update the longest sequence length as necessary.
        longest = max(longest, count);
    }
    return longest;
}

// Function to find the length of the longest consecutive elements sequence in the array using sorting.
// Intuition:
// This function follows a similar approach to the previous one, but without sorting the array.
// Approach:
// 1. Sort the array (optional, not used in this approach).
// 2. Initialize variables to track the current sequence length and the longest sequence length.
// 3. Iterate through the array:
//    a. If the current element is one greater than the previous element, increment the current sequence length.
//    b. If the current element is different from the previous element, update the longest sequence length and reset the current sequence length to 1.
// 4. Return the longest sequence length.
// Time complexity: O(n log n) for the sorting approach, where n is the size of the input array.
// Space complexity: O(1), no extra space used besides variables.
int longestConsecutiveSorting(vector<int> &nums)
{
    int n = nums.size();
    if (n == 0)
    {
        return 0;
    }
    sort(nums.begin(), nums.end());
    int curr = 1;
    int longest = 0;
    // Loop through the sorted array to find the longest consecutive sequence.
    for (int i = 1; i < n; i++)
    {
        // If the current element is consecutive to the previous element,
        // increment the current sequence length.
        if (nums[i] != nums[i - 1])
        {
            if (nums[i] == nums[i - 1] + 1)
            {
                curr++;
            }
            // If the current element is not consecutive, update the longest sequence length
            // and reset the current sequence length to 1.
            else
            {
                longest = max(longest, curr);
                curr = 1;
            }
        }
    }
    return max(longest, curr);
}

// Function to find the length of the longest consecutive elements sequence in the array using a set.
// Intuition:
// This function utilizes a set to efficiently determine if an element is the start of a sequence.
// Approach:
// 1. Insert all elements of the array into a set.
// 2. For each element in the set:
//    a. If the element is the start of a sequence (i.e., the previous element is not present in the set), start counting the sequence length.
//    b. Increment the current sequence length while the next element is present in the set.
//    c. Update the longest sequence length as necessary.
// 3. Return the longest sequence length.
// Time complexity: O(n), where n is the size of the input array.
// Space complexity: O(n), additional space used to store elements in the set.
int longestConsecutiveSet(vector<int> &nums)
{
    unordered_set<int> set;
    for (int num : nums)
    {
        set.insert(num);
    }
    int longest = 0;
    // Loop through the set to find the longest consecutive sequence.
    for (int num : set)
    {
        // If it is the start of the sequence (previous element not present in the set),
        // start counting the sequence length.
        if (set.find(num - 1) == set.end())
        {
            int currentNumber = num;
            int curr = 1;
            // Increment the current sequence length while the next element is present in the set.
            while (set.find(currentNumber + 1) != set.end())
            {
                currentNumber++;
                curr++;
            }
            // Update the longest sequence length as necessary.
            longest = max(longest, curr);
        }
    }
    return longest;
}

int main()
{
    vector<int> nums = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    cout << longestConsecutive(nums) << endl;
    cout << longestConsecutiveSorting(nums) << endl;
    cout << longestConsecutiveSet(nums) << endl;
    return 0;
}
