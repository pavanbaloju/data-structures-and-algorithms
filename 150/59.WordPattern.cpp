#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

bool wordPattern(string p, string s)
{
    int i = 0, j = 0, np = p.size(), ns = s.size();
    unordered_map<char, string> ptos;
    unordered_map<string, char> stop;
    while (i < ns && j < np)
    {
        string curr = "";
        while (i < ns && s[i] != ' ')
        {
            curr += s[i];
            i++;
        }
        i++;

        if (ptos.count(p[j]) && ptos[p[j]] != curr)
        {
            return false;
        }
        if (stop.count(curr) && stop[curr] != p[j])
        {
            return false;
        }
        ptos[p[j]] = curr;
        stop[curr] = p[j];
        j++;
    }
    if (i < ns || j < np)
        return false;

    return true;
}

int main()
{
    cout << wordPattern("abba", "dog cat cat dog") << endl;
    return 0;
}