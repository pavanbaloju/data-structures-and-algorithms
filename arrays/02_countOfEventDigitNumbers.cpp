#include <iostream>
#include <vector>
using namespace std;

int countOfEventDigitNumbers(vector<int> &nums)
{
    int count = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (((int)log10(nums[i]) + 1) % 2 == 0)
        {
            count++;
        }
        
    }
    return count;
}

int main()
{
    vector<int> nums = {20, 25, 301, 4120, 6785, 57624};
    cout << countOfEventDigitNumbers(nums);
    return 0;
}