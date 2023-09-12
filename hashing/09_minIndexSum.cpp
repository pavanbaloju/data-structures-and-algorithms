#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<string> findRestaurant(vector<string> &list1, vector<string> &list2)
{
    unordered_map<string, int> map;
    for (int i = 0; i < list1.size(); i++)
    {
        map[list1[i]] = i;
    }
    vector<string> minIndexSumStrings = vector<string>();
    int minIndexSum = INT_MAX;
    for (int i = 0; i < list2.size(); i++)
    {
        auto it = map.find(list2[i]);
        if (it != map.end())
        {
            int sum = map[list2[i]] + i;
            if (sum < minIndexSum)
            {
                minIndexSum = sum;
                minIndexSumStrings.clear();
                minIndexSumStrings.push_back(list2[i]);
            }
            else if (sum == minIndexSum)
            {
                minIndexSumStrings.push_back(list2[i]);
            }
        }
    }

    return minIndexSumStrings;
}

int main()
{
    vector<string> list1 = {"Shogun","Tapioca Express","Burger King","KFC"};
    vector<string> list2 = {"KFC","Shogun","Burger King"};
    vector<string> res = findRestaurant(list1, list2);
    for(string x: res) cout<<x<<endl;

    list1 = {"happy","sad","good"};
    list2 = {"sad","happy","good"};
    res = findRestaurant(list1, list2);
    for(string x: res) cout<<x<<endl;
    return 0;
}