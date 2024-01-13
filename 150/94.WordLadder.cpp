#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <unordered_set>
using namespace std;

int ladderLength(string beginWord, string endWord, vector<string> &wordList)
{
    int ans = INT_MAX;
    map<string, bool> visited;
    queue<pair<string, int>> q;

    q.push({beginWord, 1});
    visited[beginWord] = true;

    unordered_set<string> st(wordList.begin(), wordList.end());
    while (!q.empty())
    {
        auto [word, dist] = q.front();
        q.pop();

        if (word == endWord)
            return dist;

        for (int i = 0; i < word.size(); i++)
        {
            char original = word[i];
            for (char ch = 'a'; ch <= 'z'; ch++)
            {
                word[i] = ch;
                if (st.find(word) != st.end())
                {
                    st.erase(word);
                    q.push({word, dist + 1});
                }
            }
            word[i] = original;
        }
    }
    return 0;
}

int main()
{
    vector<string> wordList{"hot", "dot", "dog", "lot", "log", "cog"};
    string start = "hit", end = "cog";
    cout << ladderLength(start, end, wordList);
    return 0;
}