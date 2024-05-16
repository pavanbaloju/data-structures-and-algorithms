#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// Approaches without modifying the array

// Solution using HashSet
// Intuition:
// We use a HashSet to store visited elements while traversing the array.
// If we encounter an element that's already in the set, it's a duplicate.
// Approach:
// - Iterate through the array.
// - For each element, check if it's in the HashSet.
// - If it's already in the set, return the duplicate element.
// - If not, add it to the set.
// Time complexity: O(n), where n is the size of the array.
// Space complexity: O(n) due to the HashSet.
int findDuplicateHashing(vector<int> &nums)
{
    unordered_set<int> visited;
    for (int &num : nums)
    {
        if (visited.count(num) == 1)
            return num;

        visited.insert(num);
    }
    return -1;
}

// Solution using Hashing In-Place
// Intuition:
// Similar to the previous approach, but here we utilize the array itself to mark visited elements.
// We negate the value at the index corresponding to each visited element.
// If we encounter a negative value while traversing, it indicates a duplicate.
// Approach:
// - Iterate through the array.
// - For each element, get its absolute value as index.
// - If the value at that index is negative, it's a duplicate. Return the index.
// - If not, negate the value at that index to mark it as visited.
// Time complexity: O(n), where n is the size of the array.
// Space complexity: O(1) as no extra space is used.
int findDuplicateHashInPlace(vector<int> nums)
{
    for (int &num : nums)
    {
        int index = abs(num);
        if (nums[index] < 0)
            return index;

        nums[index] = -nums[index];
    }
    return -1;
}

// Solution using Floyd's Tortoise and Hare Algorithm
// Intuition:
// We treat the array as a linked list with values as nodes and indices as pointers.
// By following the pointers based on array values, we detect a cycle, indicating a duplicate.
// Approach:
// - Initialize two pointers, slow and fast, to the first element.
// - Move slow one step at a time and fast two steps at a time until they meet.
// - Reset fast to the first element and move both pointers one step at a time until they meet.
// - The meeting point is the start of the cycle, which is the duplicate element.
// Time complexity: O(n), where n is the size of the array.
// Space complexity: O(1).
int findDuplicate(vector<int> &nums)
{
    int slow = nums[0];
    int fast = nums[0];
    do
    {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (slow != fast);

    fast = nums[0];
    while (slow != fast)
    {
        slow = nums[slow];
        fast = nums[fast];
    }
    return slow;
}

// Solution using Sorting
// Intuition:
// If the array is sorted, any duplicate elements will be adjacent to each other.
// So, we can sort the array and then check adjacent elements to find the duplicate.
// Approach:
// - Sort the array.
// - Iterate through the array and check if the current element is equal to the next element.
// - If it is, return the duplicate element.
// - If no duplicates are found after iterating through the array, return -1.
// Time complexity: O(n log n) due to sorting, where n is the size of the array.
// Space complexity: O(1) as no extra space is used.
int findDuplicateSorting(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size() - 1; ++i)
    {
        if (nums[i] == nums[i + 1])
            return nums[i];
    }
    return -1;
}

int main()
{
    vector<int> nums{1, 3, 4, 2, 2};

    // Using Floyd's Tortoise and Hare Algorithm
    cout << "Duplicate found using Floyd's Tortoise and Hare Algorithm: " << findDuplicate(nums) << endl;

    // Using HashSet approach
    cout << "Duplicate found using HashSet approach: " << findDuplicateHashing(nums) << endl;

    // Using Hashing In-Place approach
    cout << "Duplicate found using Hashing In-Place approach: " << findDuplicateHashInPlace(nums) << endl;

    // Using Sorting approach
    cout << "Duplicate found using Sorting approach: " << findDuplicateSorting(nums) << endl;

    return 0;
}
