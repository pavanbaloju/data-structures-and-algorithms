#include <iostream>
#include <vector>
using namespace std;

vector<int> replaceElementsWithGreatest(vector<int> &arr)
{
    int count = arr.size();
    int greatest = arr[count - 1];
    int prevGreatest = -1;

    for (int i = count - 1; i >= 0; i--)
    {
        if (arr[i] > prevGreatest)
        {
            greatest = arr[i];
        }
        arr[i] = prevGreatest;
        prevGreatest = greatest;
    }

    return arr;
}

int main()
{
    vector<int> arr = {17, 18, 5, 4, 6, 1};
    replaceElementsWithGreatest(arr);
    for (int num : arr)
        cout << num << " ";
    return 0;
}