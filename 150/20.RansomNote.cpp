#include <iostream>
#include <vector>
using namespace std;

/*
ransomNote can be constructed from magazine if
For every char with count n in ransomNote, there should char in magazine with count >=n
*/

bool canConstruct(string ransomNote, string magazine)
{
    vector<int> counts = vector<int>(26, 0);
    for (char ch : magazine)
        counts[ch - 'a']++;

    for (char ch : ransomNote)
    {
        if (counts[ch - 'a'] == 0)
        {
            return false;
        }
        counts[ch - 'a']--;
    }
    return true;
}
int main()
{
    cout << canConstruct("aa", "aaab") << endl;
    return 0;
}