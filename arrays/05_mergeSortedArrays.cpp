#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    vector<int> temp;
    int i = 0, j = 0;
    while (i < m && j < n)
    {
        if (nums1[i] <= nums2[j])
        {
            temp.push_back(nums1[i++]);
        }
        else
        {
            temp.push_back(nums2[j++]);
        }
    }
    while (i < m)
    {
        temp.push_back(nums1[i++]);
    }
    while (j < n)
    {
        temp.push_back(nums2[j++]);
    }

    for (int i = 0; i < m + n; i++)
    {
        nums1[i] = temp[i];
    }
}

void merge2(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int i = m - 1;
    int j = n - 1;
    int k = m + n - 1;

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
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {2, 5, 6};
    merge2(nums1, 3, nums2, 3);
    for (int num : nums1)
    {
        cout << num << " ";
    }
    return 0;
}