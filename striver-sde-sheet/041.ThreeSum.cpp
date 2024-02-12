#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

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

// Function to find all unique triplets in the array that sum up to zero.
// Intuition:
// To find unique triplets with a sum of zero, we sort the array and use two pointers technique.
// We fix one element as the target and find the other two elements using two pointers (left and right).
// Approach:
// Sort the input array to apply two pointers technique efficiently.
// Iterate through the array.
// For each element at index i, set two pointers (left and right) to the next and last elements, respectively.
// Calculate the target value as the negation of the current element (nums[i]).
// Use two pointers technique to find pairs with a sum equal to the target.
// Skip duplicate elements to avoid duplicate triplets.
// Time complexity: O(n^2), where n is the size of the input array.
//   - Sorting the array takes O(n log n) time.
//   - The nested loops for two pointers technique take O(n^2) time in total.
// Space complexity: O(n), where n is the size of the input array (for storing the result).
vector<vector<int>> threeSum(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());

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

int main()
{
    // Example usage
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> res = threeSum(nums); // Find all unique triplets
    print(res);                               // Output the result
    return 0;
}
