#include <iostream>
#include <vector>
using namespace std;

// reverse the words
// taking care of the extra spaces

//   the sky   is blue
// start from the end, move R1 left until there are no spaces
// once you find letters, move R2 left until there are no letters
// add letters from R2 to R1 to answer
// repeat

string reverseWords(string s)
{
    int right2 = s.size() - 1, right = s.size() - 1;
    string ans = "";
    while (right >= 0)
    {
        while (right >= 0 && s[right] == ' ')
            right--;

        if (right < 0)
            break;

        right2 = right;
        while (right2 >= 0 && s[right2] != ' ')
        {
            right2--;
        }
        for (int i = right2 + 1; i < right + 1; i++)
        {
            ans += s[i];
        }
        ans += ' ';
        right = right2;
    }
    ans.pop_back();
    return ans;
}

int main()
{
    string s = "   the sky   is blue ";
    cout << "|" << reverseWords(s) << "|";
    return 0;
}