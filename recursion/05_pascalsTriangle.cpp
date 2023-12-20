#include <iostream>
#include <vector>
using namespace std;

// Brute
//  int pascalsij(int i, int j)
//  {
//      if (j == 0 || i == j)
//      {
//          return 1;
//      }

//     return pascalsij(i - 1, j - 1) + pascalsij(i - 1, j);
// }

// vector<int> getRow(int row)
// {
//     vector<int> res;
//     for (int j = 0; j <= row; j++)
//     {
//         res.push_back(pascalsij(row, j));
//     }
//     return res;
// }

// O(row+1) space
vector<int> getRow(int k)
{
    if (k == 0)
        return {1};

    vector<int> prevRow = getRow(k - 1);
    vector<int> row;
    row.push_back(1);
    for (int i = 1; i < k; ++i)
    {
        row.push_back(prevRow[i - 1] + prevRow[i]);
    }
    row.push_back(1);
    return row;
}

int main()
{
    vector<int> row = getRow(3);
    for (int x : row)
    {
        cout << x << " ";
    }
}