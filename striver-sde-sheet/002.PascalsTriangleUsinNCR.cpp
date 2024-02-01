#include <iostream>
#include <vector>
using namespace std;

int nCr(int N, int R)
{
    long long res = 1;

    for (int r = 0; r < R; r++)
    {
        res = res * (N - r);
        res = res / (r + 1);
    }
    return res;
}

int pascalTriangle(int r, int c)
{
    return nCr(r - 1, c - 1);
}

vector<int> generateRow(int N)
{
    // if 0 indexed uncomment
    // N++;
    vector<int> row{1};

    int ans = 1;
    for (int r = 1; r < N; r++)
    {
        ans = ans * (N - r);
        ans = ans / r;
        row.push_back(ans);
    }

    return row;
}

vector<vector<int>> pascalTriangle(int n)
{
    vector<vector<int>> ans;

    for (int row = 1; row <= n; row++)
        ans.push_back(generateRow(row));

    return ans;
}

void print(vector<int> &nums)
{
    for (int x : nums)
        cout << x << " ";
    cout << endl;
}

int main()
{
    int r = 5; // row number
    int c = 3; // col number
    int element = pascalTriangle(r, c);
    cout << "The element at position (r,c) is: " << element << endl
         << endl;

    vector<int> row = generateRow(5);
    print(row);
    cout << endl;

    vector<vector<int>> pt = pascalTriangle(5);
    for (auto row : pt)
        print(row);

    return 0;
}
