#include <iostream>
#include <vector>
using namespace std;

int heightChecker(vector<int> &heights)
{
    vector<int> expected;
    expected = heights;
    sort(expected.begin(), expected.end());

    int c = 0;
    for (int i = 0; i < heights.size(); i++)
    {
        if (heights[i] != expected[i])
        {
            c++;
        }
    }
    return c;
}
int main()
{
    vector<int> arr = {1, 1, 4, 2, 1, 3};
    cout << heightChecker(arr);
    return 0;
}