#include <iostream>
#include <vector>
#include <map>
using namespace std;

// s3 = "aadbbcbcac"
// s1 = "aabcc", s2 = "dbbca", s3 = ""
// s1 = "aabc", s2 = "dbbca", s3 = "c"
// s1 = "aabc", s2 = "dbbc", s3 = "ac"
// s1 = "aabc", s2 = "dbbc", s3 = "ac"
// s1 = "aab", s2 = "dbbc", s3 = "cac" | s1 = "aabc", s2 = "dbb", s3 = "cac"
// s1 = "aa", s2 = "dbbc", s3 = "bcac" | s1 = "aabc", s2 = "db", s3 = "bcac"
// s1 = "aa", s2 = "dbb", s3 = "cbcac" | s1 = "aab", s2 = "db", s3 = "cbcac"
// s1 = "aa", s2 = "db", s3 = "bcbcac" | s1 = "aa", s2 = "db", s3 = "bcbcac" | s1 = "aab", s2 = "d", s3 = "bcbcac"
// [s1 = "aa", s2 = "d", s3 = "bbcbcac" | s1 = "aa", s2 = "d", s3 = "bbcbcac" | s1 = "aa", s2 = "d", s3 = "bbcbcac"]
// s1 = "aa", s2 = "", s3 = "dbbcbcac"
// s1 = "a", s2 = "", s3 = "adbbcbcac"
// s1 = "", s2 = "", s3 = "aadbbcbcac"

bool isInterleaveMemo(int xi, int yi, int zi, string &x, string &y, string &z, vector<vector<int>> &dp)
{
    if (xi < 0 && yi < 0)
        return true;

    if (dp[xi + 1][yi + 1] != -1)
        return dp[xi + 1][yi + 1];

    if (xi >= 0 && x[xi] == z[zi] && isInterleaveMemo(xi - 1, yi, zi - 1, x, y, z, dp))
        return true;

    if (yi >= 0 && y[yi] == z[zi] && isInterleaveMemo(xi, yi - 1, zi - 1, x, y, z, dp))
        return true;

    return dp[xi + 1][yi + 1] = false;
}

bool isInterleave(string x, string y, string z)
{
    int zs = z.size(), xs = x.size(), ys = y.size();
    if (zs != xs + ys)
        return false;

    if ((x == z && ys == 0) || (y == z && xs == 0))
        return true;

    vector<vector<int>> dp(xs + 1, vector<int>(ys + 1, -1));
    return isInterleaveMemo(xs - 1, ys - 1, zs - 1, x, y, z, dp);
}

bool isInterleaveTable(string x, string y, string z)
{
    int zs = z.size(), xs = x.size(), ys = y.size();
    if (zs != xs + ys)
        return false;

    if ((x == z && ys == 0) || (y == z && xs == 0))
        return true;

    vector<vector<bool>> dp(xs + 1, vector<bool>(ys + 1, false));
    dp[0][0] = true;

    for (int yi = 1; yi <= ys; yi++)
    {
        dp[0][yi] = dp[0][yi - 1] && y[yi - 1] == z[yi - 1];
    }
    for (int xi = 1; xi <= xs; xi++)
    {
        dp[xi][0] = dp[xi - 1][0] && x[xi - 1] == z[xi - 1];
    }

    for (int xi = 1; xi <= xs; xi++)
    {
        for (int yi = 1; yi <= ys; yi++)
        {
            bool isInterleave = false;
            isInterleave = isInterleave || (dp[xi - 1][yi] && x[xi - 1] == z[xi - 1 + yi - 1 + 1]);
            isInterleave = isInterleave || (dp[xi][yi - 1] && y[yi - 1] == z[xi - 1 + yi - 1 + 1]);

            dp[xi][yi] = isInterleave;
        }
    }
    return dp[xs][ys];
}

bool isInterleave(string x, string y, string z)
{
    int zs = z.size(), xs = x.size(), ys = y.size();
    if (zs != xs + ys)
        return false;

    if ((x == z && ys == 0) || (y == z && xs == 0))
        return true;

    vector<vector<int>> dp(xs + 1, vector<int>(ys + 1, -1));
    return isInterleaveMemo(xs - 1, ys - 1, zs - 1, x, y, z, dp);
}

int main()
{
    cout << isInterleave("aabcc", "dbbca", "aadbbcbcac") << endl;
    cout << isInterleaveTable("aabcc", "dbbca", "aadbbcbcac") << endl;
    return 0;
}
