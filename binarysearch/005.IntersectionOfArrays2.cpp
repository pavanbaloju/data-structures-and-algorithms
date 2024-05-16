#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

// Problem Statement:
// Given two arrays, write a function to compute their intersection.

// Approach 1: Using Hash Set
// 1. Problem Statement: To find the intersection of two arrays.
// 2. Intuition: Use a hash set to store elements of one array and iterate through the other array to find common elements.
// 3. DSA Strategy: Hashing
// 4. Approach: Use a hash set to store elements of one array. Iterate through the second array and check if each element exists in the set.
//    If it does, add it to the result and remove it from the set to avoid duplicates.
// 5. Time Complexity: O(m + n), where m and n are the sizes of the two arrays.
//    Inserting elements into the set takes O(m) time, and iterating through the second array takes O(n) time.
// 6. Space Complexity: O(m), where m is the size of the smaller array.
vector<int> intersection_hashSet(vector<int> &nums1, vector<int> &nums2)
{
    // Store the elements of nums1 in a hash set
    unordered_set<int> numSet(nums1.begin(), nums1.end());
    vector<int> result;
    // Iterate through nums2 and check if each element exists in the hash set
    for (int num : nums2)
    {
        if (numSet.count(num))
        {
            // If it exists, add it to the result and remove it from the set to avoid duplicates
            result.push_back(num);
            numSet.erase(num);
        }
    }
    return result;
}

// Approach 2: Sorting and Two Pointers
// 1. Problem Statement: To find the intersection of two arrays.
// 2. Intuition: Sort both arrays and use two pointers to iterate through them simultaneously to find common elements.
// 3. DSA Strategy: Sorting, Two Pointers
// 4. Approach: Sort both arrays. Use two pointers to iterate through both arrays simultaneously.
//    If the elements at the pointers are equal, add them to the result. Move the pointers based on the comparison of elements.
// 5. Time Complexity: O(m log m + n log n), where m and n are the sizes of the two arrays.
//    Sorting the arrays takes O(m log m + n log n) time, and iterating through both arrays takes O(m + n) time.
// 6. Space Complexity: O(1)
vector<int> intersection_sorting(vector<int> &nums1, vector<int> &nums2)
{
    // Sort both arrays
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    int i = 0, j = 0;
    vector<int> result;
    // Use two pointers to iterate through both arrays simultaneously
    while (i < nums1.size() && j < nums2.size())
    {
        // If the elements at the pointers are equal, add it to the result
        if (nums1[i] == nums2[j])
        {
            result.push_back(nums1[i]);
            i++;
            j++;
        }
        else if (nums1[i] < nums2[j])
        {
            // If the element in nums1 is smaller, move the pointer forward
            i++;
        }
        else
        {
            // If the element in nums2 is smaller, move the pointer forward
            j++;
        }
    }
    return result;
}

// Approach 3: Using Hash Map
// 1. Problem Statement: To find the intersection of two arrays.
// 2. Intuition: Count the frequency of each element in one array using a hash map, then iterate through the second array and check the frequency in the map.
// 3. DSA Strategy: Hashing
// 4. Approach: Count the frequency of each element in nums1 using a hash map. Iterate through nums2 and check if each element exists in the map.
//    If it exists, add it to the result and decrement its frequency in the map.
// 5. Time Complexity: O(m + n), where m and n are the sizes of the two arrays.
//    Counting the frequency of elements in nums1 takes O(m) time, and iterating through nums2 takes O(n) time.
// 6. Space Complexity: O(min(m, n)), where m and n are the sizes of the two arrays.
vector<int> intersection_hashMap(vector<int> &nums1, vector<int> &nums2)
{
    unordered_map<int, int> freqMap;
    vector<int> result;
    // Count the frequency of each element in nums1
    for (int num : nums1)
    {
        freqMap[num]++;
    }
    // Iterate through nums2 and check if each element exists in the map
    for (int num : nums2)
    {
        if (freqMap[num] > 0)
        {
            // If it exists, add it to the result and decrement its frequency in the map
            result.push_back(num);
            freqMap[num]--;
        }
    }
    return result;
}

int main()
{
    vector<int> nums1 = {1, 2, 2, 1};
    vector<int> nums2 = {2, 2};

    // Using Hash Set
    vector<int> result1 = intersection_hashSet(nums1, nums2);
    cout << "Intersection using Hash Set: ";
    for (int num : result1)
    {
        cout << num << " ";
    }
    cout << endl;

    // Using Sorting and Two Pointers
    vector<int> result2 = intersection_sorting(nums1, nums2);
    cout << "Intersection using Sorting: ";
    for (int num : result2)
    {
        cout << num << " ";
    }
    cout << endl;

    // Using Hash Map
    vector<int> result3 = intersection_hashMap(nums1, nums2);
    cout << "Intersection using Hash Map: ";
    for (int num : result3)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
