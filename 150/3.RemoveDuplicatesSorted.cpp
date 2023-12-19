#include <iostream>
#include <vector>
using namespace std;

// pointer to iterate through array
// pointer for next unique element
//
int removeDup(vector<int> &nums)
{
    int j = 1;
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] != nums[i - 1])
        {
            nums[j++] = nums[i];
        }
    }
    return j;
}

int main()
{
    vector<int> nums1 = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    cout << removeDup(nums1) << endl;
    for (int n : nums1)
    {
        cout << n << " ";
    }
    return 0;
}