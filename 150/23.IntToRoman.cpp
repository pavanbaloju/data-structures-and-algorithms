#include <iostream>
#include <unordered_map>
#include <vector>
#include <cmath>
using namespace std;

string intToRoman(int num)
{
    vector<pair<string, int>> m = {
        {"I", 1},
        {"IV", 4},
        {"V", 5},
        {"IX", 9},
        {"X", 10},
        {"XL", 40},
        {"L", 50},
        {"XC", 90},
        {"C", 100},
        {"CD", 400},
        {"D", 500},
        {"CM", 900},
        {"M", 1000}};

    string res = "";
    for (int i = m.size() - 1; i >= 0; i--)
    {
        pair<string, int> p = m[i];
        int count = floor(num / p.second);
        if (count)
        {
            while (count--)
            {
                res += p.first;
            }
            num = num % p.second;
        }
    }
    return res;
}

int main()
{
    cout << intToRoman(3) << endl;
    cout << intToRoman(58) << endl;
    cout << intToRoman(1994) << endl;
    return 0;
}