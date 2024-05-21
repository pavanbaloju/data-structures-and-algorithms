#include <iostream>
#include <vector>

using namespace std;

// Function to generate all subsets using bit manipulation
vector<vector<int>> subsets(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> allSubsets;

    // Loop through all possible subsets
    // There are 2^n subsets for a set of size n
    for (int i = 0; i < (1 << n); ++i)
    {
        vector<int> subset;

        // Iterate through each element in the set
        for (int j = 0; j < n; ++j)
        {
            // Check if the jth element is included in the ith subset
            if (i & (1 << j))
            {
                subset.push_back(nums[j]);
            }
        }

        // Add the current subset to the list of all subsets
        allSubsets.push_back(subset);
    }

    return allSubsets;
}

int main()
{
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result = subsets(nums);

    cout << "All subsets: " << endl;
    for (const auto &subset : result)
    {
        cout << "{ ";
        for (int num : subset)
        {
            cout << num << " ";
        }
        cout << "}" << endl;
    }

    return 0;
}
