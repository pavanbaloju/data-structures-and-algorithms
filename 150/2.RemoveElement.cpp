#include <iostream>
#include <vector>
using namespace std;

// TODO
// remove all occurances of val
// count number of elements not equal to val and return it

// Algo
//  pointer i for location of nums != val
// pointer j to iterate
int remove(vector<int> &nums, int val)
{
    int i = 0;
    int j = 0;
    while (j < nums.size())
    {
        if (nums[j] != val)
        {
            swap(nums[i++], nums[j]);
        }
        j++;
    }
    return i;
}

int main()
{
    vector<int> nums1 = {3, 2, 2, 3};
    int val = 3;
    cout << remove(nums1, val) << endl;
    for (int n : nums1)
    {
        cout << n << " ";
    }
    return 0;
}