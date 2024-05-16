#include <iostream>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int> &numbers, int target)
{
    int left = 0;
    int right = numbers.size() - 1;

    while (left < right)
    {
        int sum = numbers[left] + numbers[right];
        if (sum == target)
        {
            // Return 1-based indices
            return {left + 1, right + 1};
        }
        else if (sum < target)
        {
            left++;
        }
        else
        {
            right--;
        }
    }

    // In case no solution is found, though the problem states there is exactly one solution
    return {};
}

int main()
{
    vector<int> numbers = {2, 7, 11, 15};
    int target = 9;

    vector<int> result = twoSum(numbers, target);
    if (!result.empty())
    {
        cout << "Indices: [" << result[0] << ", " << result[1] << "]" << endl;
    }
    else
    {
        cout << "No solution found!" << endl;
    }

    return 0;
}
