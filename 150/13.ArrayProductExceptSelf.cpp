#include <iostream>
#include <vector>
using namespace std;

void print(vector<int> nums)
{
    for (int x : nums)
        cout << x << " ";
    cout << endl;
}
/*
Brute force
Calculate products for each index
by iterating through whole array for each index

Gives TLE
*/
vector<int> productExceptSelf(vector<int> &nums)
{
    vector<int> arrayProduct = vector<int>(nums.size(), 1);
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = 0; j < nums.size(); j++)
        {
            if (i == j)
            {
                continue;
            }
            arrayProduct[i] *= nums[j];
        }
    }
    return arrayProduct;
}

/*

Calculate left products
Calculate right products

*/
vector<int> productExceptSelfOpt(vector<int> &nums)
{
    int n = nums.size();
    vector<int> arrayProduct(n);
    vector<int> left(n);
    vector<int> right(n);
    left[0] = 1;
    for (int i = 1; i < n; i++)
    {
        left[i] = left[i - 1] * nums[i - 1];
    }
    right[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--)
    {
        right[i] = right[i + 1] * nums[i + 1];
    }
    for (int i = 0; i < n; i++)
    {
        arrayProduct[i] = left[i] * right[i];
    }
    return arrayProduct;
}

vector<int> productExceptSelfOpt2(vector<int> &nums)
{
    vector<int> arrayProduct = vector<int>(nums.size(), 1);
    arrayProduct[0] = 1;

    for (int i = 1; i < nums.size(); i++)
    {
        arrayProduct[i] = arrayProduct[i - 1] * nums[i - 1];
    }
    int right = 1;
    for (int i = nums.size() - 1; i >= 0; i--)
    {
        arrayProduct[i] *= right;
        right *= nums[i];
    }

    return arrayProduct;
}

int main()
{
    vector<int> nums = {2, 2, 3, 5};
    print(productExceptSelf(nums));
    print(productExceptSelfOpt(nums));
    print(productExceptSelfOpt2(nums));
    return 0;
}