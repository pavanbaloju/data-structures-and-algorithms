#include <iostream>
#include <vector>
using namespace std;

bool validMountainArray(vector<int> &arr)
{
    int count = arr.size();
    if (count < 3)
    {
        return false;
    }
    int i = 1;
    for (; i < count; i++)
    {
        if (arr[i] <= arr[i - 1])
        {
            break;
        }
    }
    if (i == count || i == 1)
    {
        return false;
    }

    for (; i < count; i++)
    {
        if (arr[i] >= arr[i - 1])
        {
            return false;
        }
    }
    return true;
}

int main()
{

    vector<int> nums = {0, 3, 4, 5, 2, 1, 0};
    cout << validMountainArray(nums);
    return 0;
}