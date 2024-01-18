#include <iostream>
#include <vector>
using namespace std;

vector<int> plusOne(vector<int> &digits)
{
    int carry = 1, count = digits.size();
    for (int i = count - 1; i >= 0; i--)
    {
        int sum = digits[i] + carry;
        digits[i] = sum % 10;
        carry = sum / 10;
        if (carry == 0)
        {
            return digits;
        }
        
    }
    reverse(digits.begin(), digits.end());
    digits.push_back(carry);
    reverse(digits.begin(), digits.end());    
    return digits;
}

int main()
{
    vector<int> digits = {9,9};
    vector<int> res = plusOne(digits);
    for (int d : res)
    {
        cout << d;
    }
}