#include <iostream>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
    for (int i = 0, j = nums.size() - 1; i < j;)
    {
        int sum = nums[i] + nums[j];
        if ( sum < target)
        {
            i++;
        }
        else if (sum > target)
        {
            j--;
        }
        else
        {
            return {i+1, j+1};
        }
    }
    return {};
}

int main()
{
    vector<int> arr = {2, 7, 11, 15};
    vector<int> v = twoSum(arr, 9);
    cout << v[0] << " " << v[1] << arr[v[0]-1] + arr[v[1]-1];
}