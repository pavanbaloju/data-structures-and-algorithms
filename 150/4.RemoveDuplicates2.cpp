#include <iostream>
#include <vector>
using namespace std;

// pointer to check if element exists already at i-2 if i>2
int removeDuplicates(vector<int> &nums)
{
    int index = 0;
    for (int num : nums)
    {
        if (index < 2 || num > nums[index - 2])
        {
            nums[index++] = num;
        }
    }
    return index;
}

int main()
{
    vector<int> nums1 = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    cout << removeDuplicates(nums1) << endl;
    for (int n : nums1)
    {
        cout << n << " ";
    }
    return 0;
}