#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int findKthLargest(vector<int> &nums, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq(nums.begin(), nums.begin() + k);
    for (int i = k; i < nums.size(); i++)
    {
        if (nums[i] > pq.top())
        {
            pq.pop();
            pq.push(nums[i]);
        }
    }
    return pq.top();
}
int main()
{
    cout << "heapifying " << endl;
    vector<int> v = {1, 9, 5, 6, 2, 7, 4};
    cout << findKthLargest(v, 2);
    return 0;
}