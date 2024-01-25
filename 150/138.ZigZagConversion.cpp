#include <iostream>
#include <vector>
using namespace std;

string convert(string str, int n)
{
    if (n == 1)
        return str;

    int len = str.length();
    vector<string> rows(n);

    int row = 0;
    bool down;

    for (int i = 0; i < len; ++i)
    {
        rows[row].push_back(str[i]);
        if (row == n - 1)
            down = false;
        else if (row == 0)
            down = true;

        (down) ? (row++) : (row--);
    }

    string ans;

    for (string row : rows)
        ans += row;
    return ans;
}

int main()
{
    cout << convert("PAYPALISHIRING", 4) << endl;
}