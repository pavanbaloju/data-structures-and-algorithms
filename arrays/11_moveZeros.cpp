#include<iostream>
#include<vector>
using namespace std;

void moveZeroes(vector<int>& nums) {

    int i=0, j=0, count = nums.size();
    while (i<count)
    {
        if (nums[i]!=0)
        {
            nums[j] = nums[i];
            j++;
        }
        i++;
    }
    while (j<count)
    {
       nums[j++] = 0;
    }
      
}

int main() 
{
    vector<int> arr = {0,1,0,3,12};
    moveZeroes(arr);
    for(int a:arr) cout<<a<<" ";
    return 0;
}