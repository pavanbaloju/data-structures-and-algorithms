#include <iostream>
#include <vector>
using namespace std;

void print(vector<int> arr)
{
    for (int x : arr)
        cout << x << " ";
    cout << endl;
}
vector<int> findDisappearedNumbers(vector<int> &nums)
{
    int count = nums.size();
    for (int i = 0; i < count; i++)
    {
        int value = abs(nums[i]);
        int index = value - 1;
        if (nums[index] > 0)
        {
            nums[index] = nums[index] * -1;
        }
    }
    vector<int> res;
    for (int i = 0; i < count; i++)
    {
        if (nums[i] > 0)
        {
            res.push_back(i+1);
        }
    }
    
    return res;
}

int main()
{
    vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};
    vector<int> res = findDisappearedNumbers(nums);
    print(res);
    return 0;
}
