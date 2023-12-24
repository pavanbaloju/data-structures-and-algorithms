#include <iostream>
#include <unordered_map>
#include <vector>
#include <cmath>
using namespace std;

int romanToInt(string s)
{
    int n = s.size() - 1;
    int num = 0;
    int curr = 0, last;
    unordered_map<char, int> m = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}};
    for (int i = n; i >= 0; i--)
    {
        last = curr;
        curr = m[s[i]];
        num += curr >= last ? curr : -curr;
    }
    return num;
}


int main()
{
    cout << romanToInt("III") << endl;
    cout << romanToInt("LVIII") << endl;
    cout << romanToInt("MCMXCIV") << endl;
    return 0;
}