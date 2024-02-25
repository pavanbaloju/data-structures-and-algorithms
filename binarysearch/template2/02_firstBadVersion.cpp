#include <iostream>
#include <vector>
using namespace std;

// Problem Statement:
// You are a product manager and currently leading a team to develop a new product. Unfortunately, 
// the latest version of your product fails the quality check. Since each version is developed based 
// on the previous version, all the versions after a bad version are also bad. Suppose you have 'n' 
// versions [1, 2, ..., n] and you want to find out the first bad one, which causes all the following 
// ones to be bad. You are given a function bool isBadVersion(int version) which returns whether the 
// given version is bad. Implement a function to find the first bad version. You should minimize the 
// number of calls to the API.

// Intuition:
// This problem can be solved using binary search. We need to find the first occurrence of a bad version, 
// which will indicate that all subsequent versions are also bad. 

// DSA Strategy:
// Binary Search

// Approach:
// 1. Implement the firstBadVersion function to find the first bad version using binary search.
// 2. Initialize 'start' as 0 and 'end' as 'n'.
// 3. While 'start' is less than 'end':
//    a. Calculate 'mid' as the average of 'start' and 'end'.
//    b. If 'isBadVersion(mid)' returns true, update 'end' to 'mid' (move towards left).
//    c. Otherwise, update 'start' to 'mid + 1' (move towards right).
// 4. After the loop, return 'start', which represents the first bad version.

// Time Complexity: O(log n), where 'n' is the number of versions.
// Space Complexity: O(1).

// Function to determine if a given version is bad or not
bool isBadVersion(int n)
{
    return n >= 3; // Example implementation of isBadVersion function
}

// Function to find the first bad version using binary search
int firstBadVersion(int n)
{
    int start = 0, end = n;
    while (start < end)
    {
        int mid = start + (end - start) / 2;
        if (isBadVersion(mid))
        {
            end = mid; // Move towards left
        }
        else
        {
            start = mid + 1; // Move towards right
        }
    }

    return start; // Return the first bad version
}

// Main function
int main()
{
    cout << firstBadVersion(5); // Test firstBadVersion function with an example
    return 0;
}
