#include <iostream>
#include <vector>
using namespace std;

class MinStack
{
private:
    vector<pair<int, int>> stack;

public:
    MinStack()
    {
        stack.push_back({INT_MAX, INT_MAX});
    }

    void push(int val)
    {
        stack.push_back({val, min(val, stack.back().second)});
    }

    void pop()
    {
        stack.pop_back();
    }

    int top()
    {
        return stack.back().first;
    }

    int getMin()
    {
        return stack.back().second;
    }
};

int main()
{
    MinStack minStack = MinStack();
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    cout << minStack.getMin()<<endl; // return -3
    minStack.pop();
    cout << minStack.top()<<endl;    // return 0
    cout << minStack.getMin()<<endl; // return -2
    return 0;
}