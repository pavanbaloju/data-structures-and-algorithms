#include <iostream>
#include <vector>
using namespace std;

int candy(vector<int> &ratings)
{
    int n = ratings.size();
    vector<int> candies = vector<int>(n, 1);

    for (int i = 1; i < n; i++)
    {
        if (ratings[i] > ratings[i - 1])
            candies[i] = candies[i - 1] + 1;
    }
    for (int i = n - 2; i >= 0; i--)
    {
        if (ratings[i] > ratings[i + 1] && candies[i] <= candies[i+1])
            candies[i] = candies[i + 1] + 1;
    }
    int total = 0;
    for (int candy : candies)
        total += candy;
    
    return total;
}

int main()
{
    vector<int> nums = {1, 2, 2};
    cout << candy(nums) << endl;
    return 0;
}