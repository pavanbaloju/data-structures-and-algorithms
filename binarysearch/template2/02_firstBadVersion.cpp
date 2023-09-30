#include <iostream>
#include <vector>
using namespace std;

bool isBadVersion(int n)
{
    return n>=3;
}

int firstBadVersion(int n)
{
    int start = 0, end = n;
    while (start < end)
    {
        int mid = start + (end - start) / 2;
        if (isBadVersion(mid))
        {
            end = mid;
        }
        else
        {
            start = mid + 1;
        }
    }

    return start;
}

int main()
{
    cout << firstBadVersion(5);
}