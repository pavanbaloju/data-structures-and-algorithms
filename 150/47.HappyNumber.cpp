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
    // to check if loop exists
    unordered_set<int> visited;
    while (num > 1 && !visited.count(num))
    {
        visited.insert(num);
        num = sumOfDigitSquares(num);
    }

    return num == 1;
}
bool isHappy2pointer(int n)
{
    int slow = n, fast = n;
    do
    {
        slow = sumOfDigitSquares(slow);
        fast = sumOfDigitSquares(sumOfDigitSquares(fast));
    } while (slow != fast);
    return slow == 1;
}

int main()
{
    cout << isHappy(19) << endl;
    cout << isHappy2pointer(4) << endl;
    // cout << sumOfDigitSquares(123);
}