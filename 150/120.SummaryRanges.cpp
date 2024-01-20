#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

vector<string> summaryRanges(vector<int> &nums)
{
    int n = nums.size();
    if (n == 0)
        return {};

    int left = 0;
    vector<string> res = vector<string>();
    while (left < n)
    {
        int right = left;
        while (right + 1 < n && nums[right + 1] == nums[right] + 1)
        {
            right++;
        }
        stringstream ss;
        if (left == right)
        {
            ss << nums[left];
        }
        else
        {
            ss << nums[left] << "->" << nums[right];
        }
        res.push_back(ss.str());
        left = right + 1;
    }
    return res;
}

int main()
{
    vector<int> nums = {0, 2, 3, 4, 6, 8, 9};
    vector<string> ranges = summaryRanges(nums);
    for (string s : ranges)
        cout << s << endl;
    return 0;
}