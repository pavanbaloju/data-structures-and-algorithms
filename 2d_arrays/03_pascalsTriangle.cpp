#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> generate(int numRows)
{
    vector<vector<int>> pt(numRows, vector<int> (numRows, 0));
    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            pt[i].resize(i+1, 1);
            if (j == 0 || j == i)
            {
                pt[i][j] = 1;
            }
            else 
            {
                pt[i][j] = pt[i-1][j-1] + pt[i-1][j];
            } 
        }  
    }
    return pt;
}
int main()
{
    vector<vector<int>> pt = generate(5);
    for (int i = 0; i < pt.size(); i++)
    {
        for (int j = 0; j < pt[i].size(); j++)
        {
            cout << pt[i][j] << " ";
        }
        cout << endl;
    }
}