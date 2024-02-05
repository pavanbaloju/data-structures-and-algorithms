#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// Solution 1: Brute force approach
// Intuition:
// Iterate through each pair of elements in the array and check if one is twice the other.
// If such a pair is found, return true.
// If no such pair is found after iterating through all pairs, return false.
// Approach:
// - Use nested loops to iterate through all pairs of elements.
// - For each pair, check if one element is twice the other.
// - If found, return true.
// - If not found after checking all pairs, return false.
// Time complexity: O(n^2) where n is the size of the array.
// Space complexity: O(1) as no extra space is used.
bool checkIfExist(vector<int> &arr)
{
    int count = arr.size();
    for (int i = 0; i < count; i++)
    {
        for (int j = i + 1; j < count; j++)
        {
            if (arr[i] == 2 * arr[j] || 2 * arr[i] == arr[j])
            {
                return true;
            }
        }
    }
    return false;
}

// Solution 2: HashSet approach
// Intuition:
// Use a HashSet to store all elements of the array.
// For each element x, check if either 2*x or x/2 exists in the HashSet.
// If found, return true.
// If no such pair is found after iterating through all elements, return false.
// Approach:
// - Use a HashSet to store all elements of the array.
// - Iterate through each element of the array.
// - For each element x, check if either 2*x or x/2 exists in the HashSet.
// - If found, return true.
// - If no such pair is found after iterating through all elements, return false.
// Time complexity: O(n) where n is the size of the array.
// Space complexity: O(n) as we use extra space to store elements in the HashSet.
bool checkIfExistHashSet(vector<int> &arr)
{
    unordered_set<int> seen;
    for (int num : arr)
    {
        if (seen.count(num * 2) || (num % 2 == 0 && seen.count(num / 2)))
        {
            return true;
        }
        seen.insert(num);
    }
    return false;
}

int main()
{
    vector<int> nums = {10, 2, 5, 3};

    // Using the brute force approach
    cout << "Using brute force approach: ";
    cout << checkIfExist(nums) << endl;

    // Using the HashSet approach
    cout << "Using HashSet approach: ";
    cout << checkIfExistHashSet(nums) << endl;

    return 0;
}
