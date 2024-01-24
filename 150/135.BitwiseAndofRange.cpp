#include <iostream>
using namespace std;
typedef long long int ll;

int rangeBitwiseAndBrute(int left, int right)
{
    int res = left;
    for (int i = left + 1; i <= right; i++)
        res = res & i;

    return res;
}



int main()
{
    int x = 10, y = 15;
    cout << rangeBitwiseAnd(x, y);
    return 0;
}
