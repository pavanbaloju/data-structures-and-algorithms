#include <iostream>
#include <vector>
using namespace std;

// Function to rotate an array by 1 place k times (inefficient approach).
// Intuition:
// This approach rotates the array by one position k times. For each rotation,
// it moves each element of the array one position to the right.
// Time complexity: O(n*k), where n is the size of the array and k is the number of rotations.
// Space complexity: O(1), no extra space used besides variables.
void rotate2(vector<int> &nums, int k)
{
    int j = 0, n = nums.size();
    while (j++ < k)
    {
        int prev = nums[0];
        for (int i = 1; i <= n; i++)
        {
            swap(prev, nums[i % n]);
        }
    }
}

// Function to rotate an array by k places at once (efficient approach).
// Intuition:
// This approach rotates the array by k places at once using the cyclic rotation technique.
// It first calculates the effective rotation count (k % n) to avoid unnecessary rotations.
// Then, it iterates through the array, swapping elements according to the rotation logic.
// Time complexity: O(n), where n is the size of the array.
// Space complexity: O(1), no extra space used besides variables.
void rotate(vector<int> &nums, int k)
{
    int n = nums.size();
    if (k == 0 || n == 1 || n == k)
        return;
    int temp = nums[0];
    int start = 0;
    k %= n; // Effective rotation count
    for (int counter = 0, i = k; counter < n; i = (i + k) % n, counter++)
    {
        swap(temp, nums[i]);
        if (i == start)
        {
            start++;
            temp = nums[++i];
        }
    }
}

// Function to rotate an array by k places using reverse.
// Intuition:
// This approach first reverses the entire array. Then, it reverses the first k elements
// and the remaining elements separately. Finally, it reverts the entire array to get the rotated array.
// Time complexity: O(n), where n is the size of the array.
// Space complexity: O(1), no extra space used besides variables.
void rotate3(vector<int> &nums, int k)
{
    k %= nums.size(); // Effective rotation count
    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin() + k, nums.end());
}

int main()
{
    // Test the rotate2 function with an example array.
    vector<int> nums = {1, 2, 3, 4, 5, 6};
    rotate2(nums, 4);

    // Output the rotated array.
    for (int x : nums)
        cout << x << " ";
    return 0;
}
