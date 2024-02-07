#include <iostream>
#include <vector>
#include <map>
using namespace std;

// Function to find the majority elements using brute force approach.
// Intuition:
// We use a map to count the occurrences of each element in the array.
// Then, we iterate through the map and check if any element appears more than n/3 times.
// Approach:
// 1. Create a map to count the occurrences of each element.
// 2. Iterate through the map and add elements that appear more than n/3 times to the result vector.
// 3. Return the result vector.
// Time complexity: O(n), where n is the size of the input array.
// Space complexity: O(n), as we use a map to store the counts.
vector<int> majorityElementIIBrute(vector<int> &nums)
{
    map<int, int> countMap;
    vector<int> result;
    int n = nums.size();

    // Count occurrences of each element in the array.
    for (int num : nums)
    {
        countMap[num]++;
    }

    // Check if any element appears more than n/3 times and add it to the result.
    for (auto it = countMap.begin(); it != countMap.end(); ++it)
    {
        if (it->second > n / 3)
        {
            result.push_back(it->first);
        }
    }

    return result;
}

// Function to find the majority elements using hash map approach.
// Intuition:
// We use a map to count the occurrences of each element in the array.
// Then, we iterate through the map and check if any element appears more than n/3 times.
// Approach:
// 1. Create a map to count the occurrences of each element.
// 2. Iterate through the map and add elements that appear more than n/3 times to the result vector.
// 3. Return the result vector.
// Time complexity: O(n), where n is the size of the input array.
// Space complexity: O(n), as we use a map to store the counts.
vector<int> majorityElementIIHash(vector<int> &nums)
{
    map<int, int> countMap;
    vector<int> result;
    int n = nums.size();

    // Count occurrences of each element in the array.
    for (int num : nums)
    {
        countMap[num]++;
    }

    // Check if any element appears more than n/3 times and add it to the result.
    for (auto it = countMap.begin(); it != countMap.end(); ++it)
    {
        if (it->second > n / 3)
        {
            result.push_back(it->first);
        }
    }

    return result;
}

// Function to find the majority elements using Moore's Voting Algorithm.
// Intuition:
// The function iterates through the array and maintains a candidate and its count.
// If the count reaches zero, a new candidate is selected.
// At the end, the candidates are validated to check if they appear more than n/3 times.
// Approach:
// 1. Iterate through the array to find the majority element candidates.
// 2. Validate each candidate to check if it appears more than n/3 times and add it to the result vector.
// 3. Return the result vector.
// Time complexity: O(n), where n is the size of the input array.
// Space complexity: O(1), no extra space used besides variables.
vector<int> majorityElementII(vector<int> &nums)
{
    int count1 = 0, count2 = 0;
    int candidate1 = -1, candidate2 = -1;
    int n = nums.size();

    // Find the candidates using Moore's Voting Algorithm.
    for (int num : nums)
    {
        if (num == candidate1)
        {
            count1++;
        }
        else if (num == candidate2)
        {
            count2++;
        }
        else if (count1 == 0)
        {
            candidate1 = num;
            count1 = 1;
        }
        else if (count2 == 0)
        {
            candidate2 = num;
            count2 = 1;
        }
        else
        {
            count1--;
            count2--;
        }
    }

    // Validate candidates to check if they appear more than n/3 times.
    count1 = 0;
    count2 = 0;
    for (int num : nums)
    {
        if (num == candidate1)
        {
            count1++;
        }
        else if (num == candidate2)
        {
            count2++;
        }
    }

    vector<int> result;
    if (count1 > n / 3)
    {
        result.push_back(candidate1);
    }
    if (count2 > n / 3)
    {
        result.push_back(candidate2);
    }

    return result;
}

// Main function to test the majority element functions.
int main()
{
    // Test case to find the majority elements using different approaches.
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};

    // Find majority elements using brute force approach.
    cout << "Brute Force: ";
    for (int num : majorityElementIIBrute(nums))
    {
        cout << num << " ";
    }
    cout << endl;

    // Find majority elements using hashing approach.
    cout << "Hashing: ";
    for (int num : majorityElementIIHash(nums))
    {
        cout << num << " ";
    }
    cout << endl;

    // Find majority elements using Moore's Voting Algorithm.
    cout << "Moore's Voting Algorithm: ";
    for (int num : majorityElementII(nums))
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}