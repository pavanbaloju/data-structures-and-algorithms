#include <iostream>
#include <vector>
using namespace std;

vector<int> sortArrayByParity(vector<int> &nums)
{
    int i = 0, j = nums.size() - 1;
    while (i < j)
    {
        if (nums[i] % 2 == 1 && nums[j] % 2 == 0)
        {
            swap(nums[i], nums[j]);
            i++;
            j--;
        }
        else
        {
            if (nums[i] % 2 == 0)
            {
                i++;
            }
            if (nums[j] % 2 == 1)
            {
                j--;
            }
        }
    }
    return nums;
}
int main()
{
    vector<int> arr = {5, 2, 3, 1, 2, 4};
    sortArrayByParity(arr);
    for (int a : arr)
        cout << a << " ";
    return 0;
}