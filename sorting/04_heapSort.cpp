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
vector<int> sortArray(vector<int> &nums)
{
    heapify(nums);

    for (int heapSize = nums.size() - 1; heapSize >= 0; heapSize--)
    {
       swap(nums[0], nums[heapSize]);
       maxHeapify(nums, heapSize, 0);
    }
    return nums;
}

int main()
{
    vector<int> nums = {9, 8, 7, 6, 5, 4};
    sortArray(nums);
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
}