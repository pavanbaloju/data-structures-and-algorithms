#include <iostream>
#include <vector>
using namespace std;

int mySqrt(int x)
{
    if (x == 0 || x == 1)
    {
        return x;
    }

    int start = 1, end = x / 2;
    while (start <= end)
    {
        int mid = start + end / 2;
        if (mid == x / mid)
        {
            return mid;
        }
        else if (mid < x / mid)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return end;
}

int main()
{
    cout << mySqrt(8);
}
