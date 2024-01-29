#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class MedianFinder
{
    int n;
    double median;

    priority_queue<int> small;
    priority_queue<int, vector<int>, greater<int>> large;

public:
    MedianFinder()
    {
        n = 0;
    }

    void addNum(int num)
    {

        if (!small.empty() && small.top() > num)
        {
            small.push(num);

            if (small.size() > large.size() + 1)
            {
                large.push(small.top());
                small.pop();
            }
        }
        else
        {
            large.push(num);

            if (large.size() > small.size() + 1)
            {
                small.push(large.top());
                large.pop();
            }
        }
        n++;
    }

    double findMedian()
    {
        if (n & 1)
        {
            return small.size() > large.size() ? small.top() : large.top();
        }
        else
        {
            return (small.top() + large.top()) / 2.0;
        }
    }
};

int main()
{
    MedianFinder *obj = new MedianFinder();
    obj->addNum(4);
    obj->addNum(3);
    cout << obj->findMedian() << endl;
    obj->addNum(8);
    cout << obj->findMedian() << endl;
}