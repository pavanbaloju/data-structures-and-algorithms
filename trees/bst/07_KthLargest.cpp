#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class KthLargest
{
    priority_queue<int, vector<int>, greater<int>> pq;
    int size = 0;

public:
    KthLargest(int k, vector<int> &nums)
    {
        size = k;
        for (int num : nums)
            pq.push(num);

        while (pq.size() > size)
        {
            pq.pop();
        }
    }

    int add(int val)
    {
        pq.push(val);
        if (pq.size() > size)
            pq.pop();
        return pq.top();
    }
};
int main()
{
    vector<int> nums = {4, 5, 8, 2};
    KthLargest kl = KthLargest(3, nums);
    cout << kl.add(3) << endl;  // return 4
    cout << kl.add(5) << endl;  // return 5
    cout << kl.add(10) << endl; // return 5
    cout << kl.add(9) << endl;  // return 8
    cout << kl.add(4) << endl;  // return 8
    return 0;
}