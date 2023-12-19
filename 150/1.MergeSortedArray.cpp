#include <iostream>
#include <vector>

using namespace std;

// nums1 should have space for both array nums
// have a temp array
// while there are elements in both arrays compare each element and move the pointer in the array with the smaller number and append it to temp
// if there are any remaining elements in any array, directly append them
// copy temp into nums1

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    vector<int> temp = vector<int>(m + n);

    int i, j, k = 0;
    for (i = 0, j = 0; i < m && j < n;)
    {
        if (nums1[i] <= nums2[j])
        {
            temp[k++] = nums1[i++];
        }
        else
        {
            temp[k++] = nums2[j++];
        }
    }
    while (i < m)
    {
        temp[k++] = nums1[i++];
    }
    while (j < n)
    {
        temp[k++] = nums2[j++];
    }
    nums1 = temp;
}

// start copying bigger elements at the end of nums1 inplace
void mergeOptimised(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int i = m - 1, j = n - 1, k = m + n - 1;
    while (j >= 0)
    {
        if (i >= 0 && nums1[i] > nums2[j])
        {
            nums1[k--] = nums1[i--];
        }
        else
        {
            nums1[k--] = nums2[j--];
        }
    }
}

int main()
{
    vector<int> nums1 = {1, 3, 5, 7, 9, 0, 0, 0, 0}, nums2 = {2, 4, 6, 8};
    mergeOptimised(nums1, 5, nums2, 4);
    for (int n : nums1)
    {
        cout << n << " ";
    }
    return 0;
}