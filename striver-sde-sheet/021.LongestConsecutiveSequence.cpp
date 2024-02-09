#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

// Function to perform linear search in the array.
// Intuition:
// This function is used to search for an element in the array.
// Approach:
// Iterate through the array and check if the element matches the target number.
// Return true if found, false otherwise.
// Time complexity: O(n), where n is the size of the array.
// Space complexity: O(1), no extra space used besides variables.
bool linearSearch(vector<int>&a, int num) {
    int n = a.size(); // size of array
    for (int i = 0; i < n; i++) {
        if (a[i] == num)
            return true;
    }
    return false;
}

// Function to find the length of the longest consecutive elements sequence in the array using a brute force approach.
// Intuition:
// This function aims to find the longest consecutive sequence of elements in the array.
// Approach:
// 1. For each element in the array, check if there exists a consecutive sequence starting from that element.
// 2. Use linear search to find consecutive elements.
// 3. Update the longest sequence length as necessary.
// 4. Return the longest sequence length.
// Time complexity: O(n^2), where n is the size of the input array.
// Space complexity: O(1), no extra space used besides variables.
int longestConsecutiveBrute(vector<int>&a) {
    int n = a.size(); // size of array
    int longest = 1;
    // pick an element and search for its consecutive numbers:
    for (int i = 0; i < n; i++) {
        int x = a[i];
        int cnt = 1;
        // search for consecutive numbers using linear search:
        while (linearSearch(a, x + 1) == true) {
            x += 1;
            cnt += 1;
        }
        longest = max(longest, cnt);
    }
    return longest;
}

// Function to find the length of the longest consecutive elements sequence in the array using sorting.
// Intuition:
// This function follows a similar approach to the brute force method, but without explicitly searching for consecutive elements.
// Approach:
// 1. Sort the array to group consecutive elements together.
// 2. Iterate through the sorted array and count consecutive elements.
// 3. Return the longest sequence length.
// Time complexity: O(n log n) for the sorting operation, where n is the size of the input array.
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
    cout << longestConsecutiveBrute(nums) << endl;
    cout << longestConsecutiveSorting(nums) << endl;
    cout << longestConsecutiveSet(nums) << endl;
    return 0;
}
