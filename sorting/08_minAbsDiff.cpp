#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> minimumAbsDifference(vector<int> &nums)
{
    int shift = *min_element(nums.begin(), nums.end());
    int k = *max_element(nums.begin(), nums.end()) - shift;
    vector<int> counts = vector<int>(k + 1);

    for (int num : nums)
    {
        counts[num - shift] = 1;
    }

    int startIndex = 0;
    for (int i = 0; i < k + 1; i++)
    {
        int c = counts[i];
        counts[i] = startIndex;
        startIndex += c;
    }

    vector<int> arr = vector<int>(nums.size());
    for (int num : nums)
    {
        arr[counts[num - shift]] = num;
        counts[num - shift]++;
    }
    int minAbsDiff = INT_MAX;
    for (int i = 0; i < arr.size() - 1; i++)
    {
        if (abs(arr[i] - arr[i + 1]) < minAbsDiff)
        {
            minAbsDiff = abs(arr[i] - arr[i + 1]);
        }
    }
    vector<vector<int>> res;
    for (int i = 0; i < arr.size() - 1; i++)
    {
        if (abs(arr[i] - arr[i + 1]) == minAbsDiff)
        {
            res.push_back({arr[i], arr[i + 1]});
        }
    }
    return res;
}

// better than countsort for large array
vector<vector<int>> minimumAbsDifference2(vector<int> &arr)
{
    sort(arr.begin(), arr.end());
    int minAbsDiff = INT_MAX;
    for (int i = 0; i < arr.size() - 1; i++)
    {
        if (abs(arr[i] - arr[i + 1]) < minAbsDiff)
        {
            minAbsDiff = abs(arr[i] - arr[i + 1]);
        }
    }
    vector<vector<int>> res;
    for (int i = 0; i < arr.size() - 1; i++)
    {
        if (abs(arr[i] - arr[i + 1]) == minAbsDiff)
        {
            res.push_back({arr[i], arr[i + 1]});
        }
    }
    return res;
}

int main()
{
    vector<int> nums = {3, 8, -10, 23, 19, -4, -14, 27};
    vector<vector<int>> res = minimumAbsDifference2(nums);
    for (auto v: res)
    {
        for(int num: v)
        {
            cout<<num<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}