#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

bool hasConcatenation(int ws, string s, unordered_map<string, int> mp)
{
    int ss = s.size();
    for (int si = 0; si + ws <= ss; si += ws)
    {
        string word = s.substr(si, ws);
        if (mp.find(word) == mp.end())
            return false;
        else
            mp[word]--;
    }

    for (auto p : mp)
        if (p.second > 0)
            return false;

    return true;
}

vector<int> findSubstring(string s, vector<string> &words)
{
    int wordsLen = words.size();
    int ws = words[0].size();
    int ss = s.size();
    int window = ws * wordsLen;

    unordered_map<string, int> mp;
    for (string word : words)
        mp[word]++;

    vector<int> ans;

    for (int si = 0; si + window <= ss; si++)
    {
        if (hasConcatenation(ws, s.substr(si, window), mp))
            ans.push_back(si);
    }

    return ans;
}

int main()
{
    vector<string> words = {"foo", "bar"};
    string s = "barfoothefoobarman";
    vector<int> ans = findSubstring(s, words);

    for (int ind : ans)
        cout << ind << " ";
    return 0;
}