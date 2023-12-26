#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int largestRectangleArea(vector<int> &hist)
{
    stack<int> s;
    int n = hist.size();
    int maxArea = 0;
    int currArea;
    int i = 0;
    while (i < n)
    {
        if (s.empty() || hist[s.top()] <= hist[i])
        {
            s.push(i++);
        }
        // reached end or top > current
        while (!s.empty() && (i == n || hist[s.top()] > hist[i]))
        {
            int tp = s.top();
            s.pop();
            currArea = hist[tp] * (s.empty() ? i : i - s.top() - 1);
            maxArea = max(currArea, maxArea);
        }
    }
    return maxArea;
}

int main()
{
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    cout << largestRectangleArea(heights);
    return 0;
}