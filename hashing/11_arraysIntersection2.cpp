#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
{
    vector<int> res;
    unordered_map<int, int> map;
    for (int num : nums1)
    {
        map[num]++;
    }
    for (int num : nums2)
    {
        if (map.count(num) && map[num] > 0)
        {
            map[num]--;
            res.push_back(num);
        }
    }
    return res;
}

vector<int> intersection2(vector<int> &nums1, vector<int> &nums2)
{
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());

    vector<int> res;
    int l,r;
    for (int i = 0,j=0; i < nums1.size() && j<nums2.size();)
    {
        if (nums1[i] == nums2[j])
        {
            res.push_back(nums1[i]);
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