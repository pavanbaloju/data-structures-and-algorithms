#include <iostream>
#include <vector>
using namespace std;

void print(vector<int> nums)
{
    for (int x : nums)
        cout << x << " ";
    cout << endl;
}

vector<int> twoSum(vector<int> &numbers, int target)
{
    int left = 0, right = numbers.size() - 1;

    while (left < right)
    {
        if (numbers[left] + numbers[right] == target)
        {
            return {left + 1, right + 1};
        }
        else if (numbers[left] + numbers[right] < target)
        {
            left++;
        }
        else
        {
            right--;
        }
    }
    return {};
}

int main()
{
    vector<int> nums = vector<int>({2, 7, 11, 15});
    vector<int> res = twoSum(nums, 9);
    print(res);
}