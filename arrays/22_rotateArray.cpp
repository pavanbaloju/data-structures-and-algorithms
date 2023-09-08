#include <iostream>
#include <vector>
using namespace std;

//rotate by 1 place k times
void rotate2(vector<int> &nums, int k)
{
    int j = 0, n = nums.size();
    while (j++ < k)
    {
        int temp = nums[0];
        for (int i = 1; i <= n; i++)
        {
            swap(temp, nums[i % n]);
        }
    }
}

//rotate by k places at once
void rotate(vector<int> &nums, int k)
{

    int n = nums.size();
    if (k == 0 || n == 1 || n == k)
        return;
    int temp = nums[0];
    int start = 0;
    k %= n; 
    for (int counter = 0, i = k; counter < n; i = (i + k) % n, counter++)
    {
        swap(temp, nums[i]);
        if (i == start)
        {
            start++;
            temp = nums[++i];
        }
    }
}

//using reverse
void rotate3(vector<int> &nums, int k)
{
    k%=nums.size();
    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin() + k, nums.end());
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 6};
    rotate2(nums, 4);
    for (int x : nums)
        cout << x << " ";
}