#include <iostream>
#include <vector>
using namespace std;

bool sorter(vector<int> v1, vector<int> v2)
{
    return (v1[0] / v1[1]) > (v2[0] / v2[1]);
}

int profit(vector<vector<int>> items, int W)
{
    int profit = 0;
    sort(items.begin(), items.end(), sorter);

    for (int i = 0; i < items.size(); i++)
    {
        if (items[i][1] <= W)
        {
            W -= items[i][1];
            profit += items[i][0];
        }
        else
        {
            profit += items[i][0] * ((double)W / (double)items[i][1]);
            break;
        }
    }
    return profit;
}

int main()
{
    vector<vector<int>> items = {{60, 10}, {100, 20}, {120, 30}};
    cout << profit(items, 50) << endl;
    return 0;
}