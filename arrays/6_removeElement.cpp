#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int removeElement(vector<int> &nums, int val)
{
    int k = nums.size();
    int j = k - 1;
    int i = 0;
    while (i <= j)
    {
        if (nums[i] == val)
        {
            swap(nums[i], nums[j]);
            j--;
            k--;
        }
        else{
            i++;
        }
    }
    return k;
}
int removeElement2(vector<int> &nums, int val)
{
    int k = nums.size();
    int j = 0;
    int i = 0;
    while (i < k)
    {
        if (nums[i] != val)
        {
            nums[j] = nums[i];
            j++;
        }
        i++;
    }
    return j;
}

int main()
{

    vector<int> nums = {0, 1, 2, 2, 3, 0, 4, 2};
    int k = removeElement2(nums, 2);
    for (int i = 0; i < k; i++)
    {
        cout << nums[i] << " ";
    }
    return 0;
}