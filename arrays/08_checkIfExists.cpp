#include <iostream>
#include <vector>
using namespace std;

bool checkIfExist(vector<int> &arr)
{

    int count = arr.size();
    for (int i = 0; i < count; i++)
    {
        for (int j = i+1; j < count; j++)
        {
            if(arr[i] == 2*arr[j] || 2*arr[i]== arr[j])
            {
                return true;
            }
            
        }
        
    }
    return false;
}

int main()
{

    vector<int> nums = {10,2,5,3};
    cout<<checkIfExist(nums);
    return 0;
}