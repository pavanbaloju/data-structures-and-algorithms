#include <iostream>
#include <vector>
using namespace std;

int arrayPairSum(vector<int> &nums)
{
    sort(nums.begin(), nums.end());

    int sum = 0;
    for (int i = 0; i < nums.size(); i += 2)
    {
        sum += nums[i];
    }
    return sum;
}
int main()
{
    vector<int> arr = {6, 2, 6, 5, 1, 2};
    cout << arrayPairSum(arr);
}