#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> dailyTemperatures(vector<int> &temperatures)
{
    int n = temperatures.size();
    vector<int> res(n);
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && temperatures[st.top()] < temperatures[i])
        {
            res[st.top()] = i - st.top();
            st.pop();
        }
        st.push(i);
    }
    return res;
}
int main()
{
    vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> res = dailyTemperatures(temperatures);
    for (int x : res)
        cout << x << " ";
    return 0;
}