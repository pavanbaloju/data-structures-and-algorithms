#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
{
    vector<int> res;
    unordered_set<int> set;
    for (int num : nums1)
    {
        set.insert(num);
    }
    for (int num : nums2)
    {
        if (set.count(num))
        {
            res.push_back(num);
            set.erase(num);
        }
    }
    return res;
}
vector<int> intersection2(vector<int> &nums1, vector<int> &nums2)
{
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());

    vector<int> res;
    unordered_set<int> set;
    int l,r;
    for (int i = 0,j=0; i < nums1.size() && j<nums2.size();)
    {
        if (nums1[i] == nums2[j])
        {
            set.insert(nums1[i]);
            i++;
            j++;
        }
        else {
            if (nums1[i] > nums2[j])
            {
                j++;
            }
            else{
                i++;
            }  
        }
    }
    for (int num:set)
    {
        res.push_back(num);
    }
    
    
    return res;
}
int main()
{
    vector<int> nums1 = {4, 9, 5};
    vector<int> nums2 = {9, 4, 9, 8, 4};
    vector<int> v = intersection(nums1, nums2);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }

    return 0;
}