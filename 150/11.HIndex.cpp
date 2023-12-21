#include <iostream>
#include <vector>
using namespace std;

/*
maximum value of x such that
nums.size() >= x
nums contains x number of y's such that y >= x
*/

// Brute
// For each i in [0, nums.size()]
// If nums.size() >= i
// Count no of y's where y>=i
// find that max of i

int hIndex(vector<int> nums)
{
    int hInd = 0;
    for (int i = 0; i <= nums.size(); i++)
    {
        int count = 0;
        for (int j = 0; j < nums.size(); j++)
        {
            if (nums[j] >= i)
            {
                count++;
            }
        }
        if (count >= i)
        {
            hInd = max(hInd, i);
        }
    }

    return hInd;
}

/*
Using upperbound
sort
for x in [0, nums.size()]
Find x if the upperbound is found at index i where size - i >= i
maximize x

TC: nlogn - solution
SC: 0(1);
*/

int hIndexOpt(vector<int> nums)
{
    sort(nums.begin(), nums.end());
    int hInd = 0;
    for (int i = 0; i <= nums.size(); i++)
    {
        auto it = upper_bound(nums.begin(), nums.end(), i - 1);
        if (it != nums.end() && nums.end() - it >= i)
        {
            hInd = max(hInd, i);
        }
        else
        {
            break;
        }
    }

    return hInd;
}

/*
counting sort O(n)
TC: O(n) - solution
SC: O(n);
*/
int hIndexOpt2(vector<int> nums)
{
    int n = nums.size();
    vector<int> buckets = vector<int>(n + 1);

    for (int c : nums)
    {
        if (c >= n)
        {
            buckets[n]++;
        }
        else
        {
            buckets[c]++;
        }
    }
    int count = 0;
    for(int i = n; i >= 0; i--) {
        count += buckets[i];
        if(count >= i) {
            return i;
        }
    }
    return 0;
}

int main()
{
    vector<int> nums = {3, 0, 6, 1, 5};
    cout << hIndex(nums) << endl;
    cout << hIndexOpt(nums) << endl;
    cout << hIndexOpt2(nums) << endl;

    return 0;
}