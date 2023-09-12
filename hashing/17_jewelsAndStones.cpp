#include <iostream>
#include <unordered_set>
using namespace std;

int numJewelsInStones(string jewels, string stones)
{
    unordered_set<char> jset;
    for (char j : jewels)
        jset.insert(j);

    int jcount = 0;
    for(char s: stones) {
        auto it = jset.find(s);
        if (it != jset.end())
        {
            jcount++;
        }
    }
    return jcount;
}

int main()
{
    cout << numJewelsInStones("aA", "aAAbbb");
    return 0;
}