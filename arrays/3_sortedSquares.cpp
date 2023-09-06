#include <iostream>
#include <vector>
using namespace std;
vector<int> sortedSquares(vector<int> &A)
{
    vector<int> res(A.size());
    int l = 0, r = A.size() - 1;
    for (int k = A.size() - 1; k >= 0; k--)
    {
        if (abs(A[r]) > abs(A[l]))
        {
            res[k] = A[r] * A[r];
            r--;
        }
        else
        {
            res[k] = A[l] * A[l];
            l++;
        }
    }
    return res;
}

int main()
{
    vector<int> nums = {-7, -3, 2, 3, 11};
    vector<int> res = sortedSquares(nums);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }

    return 0;
}