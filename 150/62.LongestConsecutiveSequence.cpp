#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// TLE
int longestConsecutive(vector<int> &nums)
{
    if (nums.size() == 0)
        return 0;
    int mini = INT_MAX, maxi = INT_MIN;
    for (int n : nums)
    {
        mini = min(mini, n);
        maxi = max(maxi, n);
    }

    vector<bool> check(maxi - mini + 1);
    for (int n : nums)
    {
        check[n - mini] = true;
    }

    int longest = 0;
    int curr = 0;
    bool flag = 1;
    for (int i = 0; i < check.size(); i++)
    {
        if (check[i])
        {
            flag = true;
            curr++;
        }
        else
        {
            longest = max(longest, curr);
            curr = 0;
            flag = false;
        }
    }
    longest = max(longest, curr);
    return longest;
}

// sort
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
    for (int i = 1; i < n; i++)
    {
        if (nums[i] != nums[i - 1])
        {
            if (nums[i] == nums[i - 1] + 1)
            {
                curr++;
            }
            else
            {
                longest = max(longest, curr);
                curr = 1;
            }
        }
    }
    return max(longest, curr);
}

// set
int longestConsecutiveSet(vector<int> &nums)
{
    unordered_set<int> set;
    for (int num : nums)
    {
        set.insert(num);
    }
    int longest = 0;
    for (int num : set)
    {
        // if it is the start of the sequence
        if (set.find(num - 1) == set.end())
        {
            int currentNumber = num;
            int curr = 1;
            while (set.find(currentNumber + 1) != set.end())
            {
                currentNumber++;
                curr++;
            }
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