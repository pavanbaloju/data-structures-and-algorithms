#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

class MyQueue
{
private:
    stack<int> pushQueue, popQueue;

public:
    MyQueue()
    {
        pushQueue = stack<int>();
        popQueue = stack<int>();
    }

    void push(int x)
    {
        pushQueue.push(x);
    }

    int pop()
    {
        if (popQueue.empty())
        {
            while (!pushQueue.empty())
            {
                popQueue.push(pushQueue.top());
                pushQueue.pop();
            }
        }
        int x = popQueue.top();
        popQueue.pop();
        return x;
    }

    int peek()
    {
        if (popQueue.empty())
        {
            while (!pushQueue.empty())
            {
                popQueue.push(pushQueue.top());
                pushQueue.pop();
            }
        }
        return popQueue.top();
    }

    bool empty()
    {
        return pushQueue.empty() && popQueue.empty();
    }
};

int main()
{
    MyQueue myQueue = MyQueue();
    myQueue.push(1);         // queue is: [1]
    myQueue.push(2);         // queue is: [1, 2] (leftmost is front of the queue)
    cout << myQueue.peek();  // return 1
    cout << myQueue.pop();   // return 1, queue is [2]
    cout << myQueue.empty(); // return false

    return 0;
}