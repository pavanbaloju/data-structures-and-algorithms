#include <iostream>
#include <vector>
using namespace std;

// o(n3)
int maxSubarraycurrSum(vector<int> nums)
{
    int n = nums.size();
    int maxSum = INT_MIN; // maxSummum currSum
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            // subarray = arr[i.....j]
            int currSum = 0;

            // add all the elements of subarray:
            for (int k = i; k <= j; k++)
                currSum += nums[k];

            maxSum = max(maxSum, currSum);
        }
    }
    return maxSum;
}

// o(n2)
int maxSubarraycurrSumBetter(vector<int> nums)
{
    int n = nums.size();
    int maxSum = INT_MIN; // maxSummum currSum

    for (int i = 0; i < n; i++)
    {
        int currSum = 0;
        for (int j = i; j < n; j++)
        {
            currSum += nums[j];
            maxSum = max(maxSum, currSum);
        }
    }

    return maxSum;
}

int maxSubarraycurrSumOpt(vector<int> nums)
{
    int n = nums.size();
    int maxSum = INT_MIN;
    int currSum = 0;

    for (int i = 0; i < n; i++)
    {
        currSum += nums[i];
        maxSum = max(maxSum, currSum);
        currSum = max(0, currSum);
    }
    // if (maxSum < 0) maxSum = 0;
    return maxSum;
}

int maxSubarraycurrSumPrint(vector<int> nums)
{
    int n = nums.size();
    int maxSum = LONG_MIN; // maxSummum currSum
    int currSum = 0;

    int start = 0;
    int ansStart = -1, ansEnd = -1;
    for (int i = 0; i < n; i++)
    {

        if (currSum == 0)
            start = i; // starting index

        currSum += nums[i];

        if (currSum > maxSum)
        {
            maxSum = currSum;

            ansStart = start;
            ansEnd = i;
        }

        // If currSum < 0: discard the currSum calculated
        if (currSum < 0)
        {
            currSum = 0;
        }
    }

    // printing the subarray:
    cout << "The subarray is: [";
    for (int i = ansStart; i <= ansEnd; i++)
    {
        cout << nums[i] << " ";
    }
    cout << "] max:";

    // To consider the currSum of the empty subarray
    // uncomment the following check:

    // if (maxSum < 0) maxSum = 0;

    return maxSum;
}

int dnq(vector<int> &nums, int low, int high)
{
    if (low == high)
        return nums[low];

    int mid = (low + high) / 2, leftMax = INT_MIN, rightMax = INT_MIN;

    for (int i = mid, sum = 0; i >= low; --i)
        leftMax = max(leftMax, sum += nums[i]);

    for (int i = mid + 1, sum = 0; i <= high; ++i)
        rightMax = max(rightMax, sum += nums[i]);

    int left = dnq(nums, low, mid);
    int right = dnq(nums, mid + 1, high);
    int includesMid = leftMax + rightMax;

    return max(max(left, right), includesMid);
}

int maxSubArrayDandQ(vector<int> &nums)
{
    return dnq(nums, 0, nums.size() - 1);
}

int main()
{
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << maxSubarraycurrSum(nums) << endl;
    cout << maxSubarraycurrSumBetter(nums) << endl;
    cout << maxSubarraycurrSumOpt(nums) << endl;
    cout << maxSubArrayDandQ(nums) << endl;
    cout << maxSubarraycurrSumPrint(nums) << endl;
    return 0;
}