#include <iostream>
#include <vector>
using namespace std;

class MyCircularQueue
{
private:
    int len, capacity, front;
    vector<int> queue;

public:
    MyCircularQueue(int k)
    {
        queue.resize(k);
        len = 0;
        capacity = k;
        front = 0;
    }

    bool enQueue(int value)
    {
        if (isFull())
            return false;
        queue[(front + len) % capacity] = value;
        len += 1;
        return true;
    }

    bool deQueue()
    {
        if (isEmpty())
            return false;
        front = (front + 1) % capacity;
        len -= 1;
        return true;
    }

    int Front()
    {
        if (isEmpty())
            return -1;
        return queue[front];
    }

    int Rear()
    {
        if (isEmpty())
            return -1;
        return queue[(front + len - 1) % capacity];
    }

    bool isEmpty()
    {
        return len == 0;
    }

    bool isFull()
    {
        return len == capacity;
    }
};

int main()
{
    MyCircularQueue myCircularQueue = MyCircularQueue(3);
    myCircularQueue.enQueue(1);     // return True
    myCircularQueue.enQueue(2);     // return True
    myCircularQueue.enQueue(3);     // return True
    myCircularQueue.enQueue(4);     // return False
    cout << myCircularQueue.Rear(); // return 3
    myCircularQueue.isFull();       // return True
    myCircularQueue.deQueue();      // return True
    myCircularQueue.enQueue(4);     // return True
    cout << myCircularQueue.Rear();
}
