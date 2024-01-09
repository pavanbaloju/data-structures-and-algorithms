// exactly same as max sum non adjacent
#include <iostream>
#include <vector>
using namespace std;

int rob(vector<int> &nums)
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

int main()
{
    vector<int> nums{1, 2, 3, 1};
    cout << rob(nums) << endl;
    return 0;
}
