#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minSwaps(string s)
{
    int count = 0; 
    int sum = 0;
    for (char ch : s)
    {
        if (ch == '[')
        {
            count++;
        }
        else
        {
            count--;
        }
        if (count < 0)
        {
            sum += 1;
            count = 1;
        }
    }
    return sum;
}


int main()
{
    string s = "[]][][";
    cout << minSwaps(s) << "\n";

    s = "[[][]]";
    cout << minSwaps(s) << "\n";
    return 0;
}
