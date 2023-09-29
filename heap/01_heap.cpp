#include <iostream>
#include <vector>
using namespace std;

class MaxHeap
{
private:
    vector<int> values;
    int size;

public:
    MaxHeap(int heapSize)
    {
        values = vector<int>(heapSize);
        size = 0;
    }

    void insert(int val)
    {
        size++;
        int index = size;
        values[index] = val;

        int parent = index / 2;
        while (index > 1 && values[index] > values[parent])
        {
            swap(values[index], values[parent]);
            index = parent;
            parent = index / 2;
        }
    }

    void del()
    {
        values[1] = values[size];
        size--;

        int index = 1;
        int left = index * 2;
        int right = index * 2 + 1;

        while (index <= size / 2)
        {
            if (left <= size && values[left] > values[index])
            {
                swap(values[left], values[index]);
                index = left;
            }
            else if (right <= size && values[right] > values[index])
            {
                swap(values[right], values[right]);
                index = right;
            }
            else
            {
                return;
            }
        }
    }

    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << values[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    MaxHeap h = MaxHeap(10);
    h.insert(1);
    h.insert(2);
    h.insert(3);
    h.insert(14);
    h.insert(4);
    h.print();
    h.del();
    h.print();
    h.del();
    h.print();
    return 0;
}