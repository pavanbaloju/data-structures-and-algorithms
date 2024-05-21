#include <iostream>
#include <vector>

using namespace std;

void calculateXorSubsetSum(const vector<int> &nums, int index, int currentXor, int &totalXorSum)
{
    if (index == nums.size())
    {
        totalXorSum += currentXor;
        return;
    }

    // Include the current element
    calculateXorSubsetSum(nums, index + 1, currentXor ^ nums[index], totalXorSum);

    // Exclude the current element
    calculateXorSubsetSum(nums, index + 1, currentXor, totalXorSum);
}

int subsetXORSum(vector<int> &nums)
{
    int totalXorSum = 0;
    calculateXorSubsetSum(nums, 0, 0, totalXorSum);
    return totalXorSum;
}

int main()
{
    vector<int> nums = {2, 5, 6};
    cout << "The sum of all XOR totals for every subset is: " << subsetXORSum(nums) << endl;
    return 0;
}
