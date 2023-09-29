#include <iostream>
#include <vector>
using namespace std;

void maxHeapify(vector<int> &values, int heapSize, int index)
{
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int largest = index;
    if (left < heapSize && values[left] > values[largest])
    {
        largest = left;
    }
    if (right < heapSize && values[right] > values[largest])
    {
        largest = right;
    }
    if (largest != index)
    {
        swap(values[largest], values[index]);
        maxHeapify(values, heapSize, largest);
    }
}
void heapify(vector<int> &values)
{
    for (int i = values.size() / 2 - 1; i >= 0; i--)
    {
        maxHeapify(values, values.size(), i);
    }
}
int main()
{
    cout<<"heapifying "<<endl;
    vector<int> v = {1, 9, 5, 6, 2, 7, 4};
    heapify(v);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    return 0;
}