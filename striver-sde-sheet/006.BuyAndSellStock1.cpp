#include <iostream>
#include <vector>
using namespace std;

int maxProfitBrute(vector<int> &arr)
{
    int maxPro = 0;
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] > arr[i])
            {
                maxPro = max(arr[j] - arr[i], maxPro);
            }
        }
    }

    return maxPro;
}

// Function to calculate the maximum profit that can be obtained by buying and selling stocks.
// Intuition:
// The idea is to find the maximum difference between two elements in the array,
// where the larger element appears after the smaller element.
//
// Approach:
// - We iterate through the array and maintain two variables:
//   'minPrice' to keep track of the minimum price encountered so far, and
//   'maxProfit' to keep track of the maximum profit that can be obtained.
// - For each element in the array:
//   - We calculate the current profit by subtracting the current element from 'minPrice'.
//   - We update 'minPrice' to be the minimum of the current element and 'minPrice'.
//   - We update 'maxProfit' to be the maximum of the current profit and 'maxProfit'.
// - Finally, we return 'maxProfit' as the result.
//
// Parameters:
// - nums: A vector containing the prices of the stocks on consecutive days.
//
// Time Complexity: O(n)
// - The algorithm iterates through the array once.
// - Each iteration performs constant time operations.
//
// Space Complexity: O(1)
// - The algorithm uses only a constant amount of extra space, regardless of the size of the input array.
int maxProfit(vector<int> nums)
{
    int minPrice = INT_MAX, maxProfit = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        int currProfit = nums[i] - minPrice;
        minPrice = min(nums[i], minPrice);
        maxProfit = max(maxProfit, currProfit);
    }

    return maxProfit;
}

int main()
{
    vector<int> nums = {7, 1, 5, 3, 6, 4};

    // Calculate maximum profit using brute force approach
    cout << maxProfitBrute(nums) << endl;

    // Calculate maximum profit using optimized approach
    cout << maxProfit(nums) << endl;

    return 0;
}
