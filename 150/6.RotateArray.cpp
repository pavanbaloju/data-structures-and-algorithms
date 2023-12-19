#include <iostream>
#include <vector>
using namespace std;

void rotate(vector<int> &nums, int k)
{
    int N = nums.size();
    int i = 1;
    k %= N;
    while (i <= k)
    {
        int temp = nums[N - 1];
        for (int i = N - 1; i > 0; i--)
        {
            nums[i] = nums[i - 1];
        }
        nums[0] = temp;
        i++;
    }
}
void rotateOpt(vector<int> &nums, int k)
{
    int n = nums.size();
    for (int i = 0, j = n - k - 1; i <= j;)
    {
        swap(nums[i++], nums[j--]);
    }
    for (int i = n - k, j = n - 1; i <= j; )
    {
        swap(nums[i++], nums[j--]);
    }
    for (int i = 0, j = n - 1; i <= j;)
    {
        swap(nums[i++], nums[j--]);
    }
}
int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    rotateOpt(nums, 3);
    for (int n : nums)
    {
        cout << n << " ";
    }
    cout<<endl;
    return 0;
}