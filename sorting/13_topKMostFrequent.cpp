#include <vector>
#include <iostream>
#include <unordered_map>
#include <priority_queue>
#include <algorithm> // Required for std::min_element, std::max_element

using namespace std;

// Problem Statement:
// Given an array of integers, find the k most frequent elements.

// Intuition:
// To find the k most frequent elements, we can use Bucket Sort after calculating the frequency of each element in the array.

// DSA Strategy/Pattern:
// Sorting, Bucket Sort

// Approach:
// 1. Find the minimum and maximum elements in the array to determine the range of elements.
// 2. Create a frequency array to count the occurrences of each element.
// 3. Traverse the input array and update the frequency array accordingly.
// 4. Create buckets to store elements with the same frequency.
// 5. Traverse the frequency array and add elements to corresponding buckets.
// 6. Traverse the buckets in reverse order to get elements in descending order of frequency.
// 7. Return the first k elements from the sorted buckets.

// Time Complexity: O(n), where n is the number of elements in the input array.
//                  Finding the minimum and maximum elements requires O(n) time.
//                  Counting frequencies and distributing elements into buckets also require O(n) time.
//                  Traversing the buckets and selecting the top k elements require O(n) time.
// Space Complexity: O(n), where n is the number of elements in the input array.
//                    Additional space is required for the frequency array and buckets.

// Function to find the top k frequent elements in the given array
vector<int> topKFrequent(vector<int> &nums, int k)
{

    // Create a frequency array to count the occurrences of each element
    unordered_map<int, int> mp;
    for (int num : nums)
    {
        mp[num]++;
    }

    // Create buckets to store elements with the same frequency
    vector<vector<int>> buckets(nums.size() + 1, vector<int>());
    for (auto &it : mp)
    {
        int val = it.first;
        int freq = it.second;

        buckets[freq].push_back(val); // Add element to bucket
    }

    vector<int> res;
    // Traverse the buckets in reverse order to get elements in descending order of frequency
    for (int i = buckets.size() - 1; i >= 0; i--)
    {
        // Traverse elements in each bucket
        for (int num : buckets[i])
        {
            res.push_back(num); // Add the element to the result array
            if (res.size() == k)
            {               // Check if k elements are added to the result
                return res; // Return the result if k elements are found
            }
        }
    }

    return res; // Return the result array
}

typedef pair<int, int> pii;
vector<int> topKFrequent2(vector<int> &nums, int k)
{
    // Create a map to store the frequency of each number
    unordered_map<int, int> mp;
    for (int num : nums)
    {
        mp[num]++; // Increment the frequency of the current number
    }

    // Create a min heap to store the top k frequent elements
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    // Iterate through the map and add elements to the min heap
    for (auto &it : mp)
    {
        int val = it.first; // Get the number
        int freq = it.second; // Get its frequency
        pq.push({freq, val}); // Add the pair (frequency, number) to the min heap

        // If the size of the min heap exceeds k, remove the element with the smallest frequency
        if (pq.size() > k)
        {
            pq.pop();
        }
    }

    // Create a vector to store the top k frequent elements
    vector<int> topK;
    // Extract elements from the min heap and add them to the result vector
    while (!pq.empty())
    {
        topK.push_back(pq.top().second); // Add the number to the result vector
        pq.pop(); // Remove the element from the min heap
    }

    return topK; // Return the vector containing the top k frequent elements
}


int main()
{
    // Example usage
    vector<int> nums = {1, 1, 2, 2, 2, 2, 3}; // Input array
    int k = 2;                                // Number of top frequent elements to find
    vector<int> res = topKFrequent(nums, k);  // Find top k frequent elements
    // Output the result
    for (int num : res)
    {
        cout << num << " "; // Print each element in the result array
    }
    cout << endl; // Move to the next line
    return 0;
}
