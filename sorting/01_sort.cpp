#include <iostream>
#include <vector>
using namespace std;

//selection sort
void selectionSort(vector<int> &nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        int minIdx = i;
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (nums[j] < nums[minIdx])
            {
                minIdx = j;
            }   
        }
        swap(nums[minIdx], nums[i]);
    }
    
}
// bubble sort
void bubbleSort(vector<int> &nums)
{
    bool swapped = true;
    while (swapped)
    {
        swapped = false;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] > nums[i + 1])
            {
                swap(nums[i], nums[i + 1]);
                swapped = true;
            }
        }
    }
}
void insertionSort(vector<int> &nums)
{
    for (int i = 1; i < nums.size(); i++)
    {
        int j = i;
        while (j > 0 && nums[j - 1] > nums[j])
        {
            swap(nums[j - 1], nums[j]);
            j--;
        }
    }
}
int main()
{
    vector<int> colors = {2, 0, 2, 1, 1, 0};
    selectionSort(colors);
    for(int x:colors) cout<<x<<" ";
    return 0;
}