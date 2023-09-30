#include <iostream>
#include <vector>
using namespace std;

int guess(int n)
{
    if (n == 57)
        return 0;
    if (n > 57)
        return -1;
    return 1;
}

int guessNumber(int n)
{
    int start = 1, end = n;
    while (true)
    {
        int mid = start + (end - start) / 2;
        int res = guess(mid);
        if (res == 0)
        {
            return mid;
        }
        else if (res == 1)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
}

int main()
{
    cout << guessNumber(100);
}
