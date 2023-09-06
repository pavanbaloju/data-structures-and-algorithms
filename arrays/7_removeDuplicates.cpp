#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int> &nums)
{
    int j = 1;
    int count = nums.size();
    for (int i = 1; i < count; i++)
    {
        if (nums[i] != nums[i - 1])
        {
            nums[j] = nums[i];
            j++;
        }
    }
    return j;
}

int main()
{

    vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int k = removeDuplicates(nums);
    for (int i = 0; i < k; i++)
    {
        cout << nums[i] << " ";
    }
    return 0;
}