#include <iostream>
#include <vector>
using namespace std;

// 1, 2, 3
// 4, 5, 6
// 7, 8, 9

vector<int> spiralOrder(vector<vector<int>>& m) 
    {
        vector<int>ans;
        int n = m.size(),k = m[0].size();

        int t = 0 , b = n-1 , l = 0 , r = k - 1;

        while(t<=b and l<=r)
        {
            for(int i=l;i<=r and t<=b;i++)
            {
                ans.push_back(m[t][i]);
            }
            t++;
            for(int i=t;i<=b and l<=r ;i++)
            {
                ans.push_back(m[i][r]);
            }
            r--;
            for(int i=r;i>=l and t<=b;i--)
            {
                ans.push_back(m[b][i]);
            }
            b--;
            for(int i=b;i>=t and l<=r;i--)
            {
                ans.push_back(m[i][l]);
            }
            l++;
        }
    return ans;
    }

int main()
{
    vector<vector<int>> matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    // vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<int> res = spiralOrder(matrix);
    for (int x : res)
        cout << x << " ";
    return 0;
}