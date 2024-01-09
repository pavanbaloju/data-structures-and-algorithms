#include <iostream>
#include <vector>
using namespace std;

int robHelper(vector<int> &nums)
{
    int n = nums.size();
    int prev = nums[0], prev2 = 0;
    for (int i = 1; i < n; i++)
    {
        int pick = nums[i], curr = 0;
        if (i > 1)
            pick += prev2;
        int nonPick = prev;

        curr = max(pick, nonPick);
        prev2 = prev;
        prev = curr;
    }
    return prev;
}

int rob(vector<int> &nums)
{
    vector<int> nums1;
    vector<int> nums2;
    int n = nums.size();
    if (n == 1)
        return nums[0];

    for (int i = 0; i < n; i++)
    {
        if (i != 0)
            nums1.push_back(nums[i]);
        if (i != n - 1)
            nums2.push_back(nums[i]);
    }

    return max(robHelper(nums1), robHelper(nums2));
}

int main()
{
    vector<int> nums{2, 3, 2};
    cout << rob(nums) << endl;
    return 0;
}
