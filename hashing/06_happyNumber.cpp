#include <iostream>
#include <unordered_set>
using namespace std;

int sumOfDigitSquares(int num)
{
    int sum = 0;
    while (num)
    {
        int digit = num % 10;
        sum += digit * digit;
        num /= 10;
    }
    return sum;
}
bool isHappy(int num)
{
    unordered_set<int> visited;
    while (num > 1 && !visited.count(num))
    {
        visited.insert(num);
        num = sumOfDigitSquares(num);
    }

    return num == 1;
}

int main()
{
    cout << isHappy(4);
    // cout << sumOfDigitSquares(123);
}