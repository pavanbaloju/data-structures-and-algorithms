#include <iostream>
#include <vector>
#include <map>
using namespace std;

void solve(int mut, int &ans, string &startGene, string &endGene, vector<string> &bank,  map<string, bool> &visited)
{
    if (startGene == endGene)
    {
        ans = mut;
        return;
    }
    visited[startGene] = true;
    for (int i = 0; i < 8; i++)
    {
        char ch = startGene[i];
        for (char c : {'A', 'G', 'C', 'T'})
        {
            startGene[i] = c;
            if (!visited[startGene] && find(bank.begin(), bank.end(), startGene) != bank.end())
            {
                solve(mut + 1, ans, startGene, endGene, bank, visited);
            }
        }
        startGene[i] = ch;
    }
}

int minMutation(string startGene, string endGene, vector<string> &bank)
{
    int ans = INT_MAX;
    map<string, bool> visited;
    solve(0, ans, startGene, endGene, bank, visited);
    return ans == INT_MAX ? -1 : ans;
}

int main()
{
    vector<string> bank{"AGTAAAAA", "GGTAAAAA", "GATAAAAA", "GACAAAAA"};
    string start = "AGCAAAAA", end = "GACAAAAA";
    cout << minMutation(start, end, bank);
    return 0;
}