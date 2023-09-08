#include <iostream>
#include <vector>
using namespace std;

// basic
void duplicateZeros(vector<int> &arr)
{
    int count = arr.size();
    for (int i = count - 1; i >= 0; i--)
    {
        if (arr[i] == 0)
        {
            for (int j = count - 2; j >= i; j--)
            {
                arr[j + 1] = arr[j];
            }
        }
    }
}

void duplicateZeros2(vector<int> &arr)
{
    vector<int> temp;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == 0)
        {
            temp.push_back(0);
            temp.push_back(0);
        }
        else
            temp.push_back(arr[i]);
    }
    for (int i = 0; i < arr.size(); i++)
    {
        arr[i] = temp[i];
    }
}

int main()
{
    vector<int> nums = {1, 0, 2, 3, 0, 4, 5, 0};
    duplicateZeros2(nums);
    for (int num : nums)
    {
        cout << num << " ";
    }
    return 0;
}