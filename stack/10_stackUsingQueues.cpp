#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

class MyStack
{
private:
    queue<int> stack;

public:
    MyStack()
    {
        stack = queue<int>();
    }

    void push(int x)
    {
        stack.push(x);
        for (int i = 0; i < stack.size() - 1; ++i)
        {
            stack.push(stack.front());
            stack.pop();
        }
    }

    int pop()
    {
        int x = stack.front();
        stack.pop();
        return x;
    }

    int top()
    {
        return stack.front();
    }

    bool empty()
    {
        return stack.empty();
    }
};

int main()
{
    MyStack myStack = MyStack();
    myStack.push(1);
    myStack.push(2);
    cout << myStack.top();   // return 2
    cout << myStack.pop();   // return 2
    cout << myStack.empty(); // return False
    return 0;
}