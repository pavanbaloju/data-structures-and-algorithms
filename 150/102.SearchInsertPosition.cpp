#include <iostream>
#include <vector>
using namespace std;

int searchInsert(vector<int> &arr, int x)
{
    int n = arr.size();
    int low = 0, high = n - 1;
    int lowerBound = n;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] >= x)
        {
            lowerBound = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return lowerBound;
}

int main()
{
    vector<int> nums = {1, 3, 4, 6};
    int num = 5;

    cout << searchInsert(nums, num) << endl;
    return 0;
}