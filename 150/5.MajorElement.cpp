#include <iostream>
#include <vector>
#include <map>
using namespace std;

int major(vector<int> &nums)
{
    map<int, int> m;
    for (int num : nums)
    {
        m[num]++;
        if (m[num] > nums.size() / 2)
        {
            return num;
        }
    }
    return 0;
}

// moore voting algorithm
int majorityElement(vector<int> &nums)
{
    int count = 0;
    int candidate = -1;
    for (int num : nums)
    {
        if (count == 0)
        {
            candidate = num;
        }
        if (candidate == num)
        {
            count++;
        }
        else
        {
            count--;
        }
    }
    return candidate;
}

int main()
{
    vector<int> nums1 = {2, 2, 1, 1, 1, 2, 2};
    cout << major(nums1) << endl;
    cout << majorityElement(nums1) << endl;
    return 0;
}