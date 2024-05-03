#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

// Problem Statement:
// Given an array 'nums' of n integers and an integer 'target', are there elements a, b, c, and d in nums such that a + b + c + d = target?
// Find all unique quadruplets in the array which gives the sum of target.

// Intuition:
// We'll use three different approaches to solve the problem:
// 1. Brute Force: Nested loops to iterate through all possible combinations of four elements.
// 2. Hashing: Nested loops to iterate through all possible combinations of three elements and use a hash set to find the fourth element.
// 3. Two Pointers Technique: Sort the array and use two pointers to find the remaining two elements.

// DSA Strategy/Pattern:
// Brute Force, Hashing, Two Pointers

// Approach 1: Brute Force
// Nested loops to iterate through all possible combinations of four elements.
// Calculate the sum of each combination and check if it equals the target.
// Insert unique quadruplets into a set to avoid duplicates.
// Convert set to vector and return.

// Complexity:
// Time complexity: O(n^4) due to nested loops.
// Space complexity: O(n^4) for the set to store unique quadruplets.

// Function to find all unique quadruplets that sum up to the target using brute force approach
vector<vector<int>> fourSumBrute(vector<int> &nums, int target) {
    int n = nums.size();
    set<vector<int>> unique;

    // Nested loops to iterate through all possible combinations of four elements
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                for (int l = k + 1; l < n; l++) {
                    // If the sum of the four elements equals the target, insert into set
                    if (nums[i] + nums[j] + nums[k] + nums[l] == target) {
                        unique.insert({nums[i], nums[j], nums[k], nums[l]});
                    }
                }
            }
        }
    }

    // Convert set to vector and return
    vector<vector<int>> res(unique.begin(), unique.end());
    return res;
}

// Approach 2: Hashing
// Nested loops to iterate through all possible combinations of three elements.
// Use a hash set to store the sum of the first two elements and find the fourth element to make the sum equal to the target.
// Insert unique quadruplets into a set to avoid duplicates.
// Convert set to vector and return.

// Complexity:
// Time complexity: O(n^3) due to nested loops.
// Space complexity: O(n^3) for the set to store unique quadruplets.

// Function to find all unique quadruplets that sum up to the target using hashing approach
vector<vector<int>> fourSumHash(vector<int> &nums, int target) {
    int n = nums.size();
    set<vector<int>> unique;

    // Nested loops to iterate through all possible combinations of three elements
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            set<long long> hashset;

            // Iterate through remaining elements and check for fourth element using hashing
            for (int k = j + 1; k < n; k++) {
                long long sum = nums[i] + nums[j] + nums[k];
                long long fourth = target - sum;

                // If fourth element exists in hashset, add the quadruplet to set
                if (hashset.find(fourth) != hashset.end()) {
                    vector<int> temp = {nums[i], nums[j], nums[k], static_cast<int>(fourth)};
                    sort(temp.begin(), temp.end());
                    unique.insert(temp);
                }
                hashset.insert(nums[k]);
            }
        }
    }

    // Convert set to vector and return
    vector<vector<int>> res(unique.begin(), unique.end());
    return res;
}

// Approach 3: Two Pointers Technique
// Sort the input array to simplify the two pointers technique.
// Iterate through all elements as the first element of the quadruplet.
// Use two pointers to find the remaining two elements that sum up to the target.
// Skip duplicate elements to avoid duplicate quadruplets.
// Return the quadruplets as a vector.

// Complexity:
// Time complexity: O(n^3) due to sorting and two pointers technique.
// Space complexity: O(1) for the result vector.

// Function to find all unique quadruplets that sum up to the target using two pointers technique
vector<vector<int>> fourSum(vector<int> &nums, int target) {
    int n = nums.size();
    vector<vector<int>> res;

    // Sort the input array to simplify the two pointers technique
    sort(nums.begin(), nums.end());

    // Iterate through all elements as the first element of the quadruplet
    for (int i = 0; i < n; i++) {
        // Skip duplicate elements
        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        // Iterate through all elements as the second element of the quadruplet
        for (int j = i + 1; j < n; j++) {
            // Skip duplicate elements
            if (j > i + 1 && nums[j] == nums[j - 1])
                continue;

            // Use two pointers to find the remaining two elements
            int left = j + 1;
            int right = n - 1;
            long long newTarget = target - nums[i] - nums[j];

            while (left < right) {
                long long sum = nums[left] + nums[right];
                if (sum == newTarget) {
                    // If the sum equals the target, add the quadruplet to the result
                    res.push_back({nums[i], nums[j], nums[left], nums[right]});
                    left++;
                    right--;

                    // Skip duplicate elements
                    while (left < right && nums[left] == nums[left - 1]) {
                        left++;
                    }

                    // Skip duplicate elements
                    while (left < right && nums[right] == nums[right + 1]) {
                        right--;
                    }
                } else if (sum < newTarget) {
                    left++;
                } else {
                    right--;
                }
            }
        }
    }

    return res;
}

// Function to print a vector of vectors
void print(vector<vector<int>> nums) {
    for (vector<int> v : nums) {
        for (int x : v)
            cout << x << " ";
        cout << endl;
    }
    cout << endl;
}

int main() {
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    
    // Output the result of brute-force approach
    cout << "Brute-Force Approach:" << endl;
    print(fourSumBrute(nums, 0));
    
    // Output the result of hashing approach
    cout << "Hashing Approach:" << endl;
    print(fourSumHash(nums, 0));
    
    // Output the result of two pointers technique approach
    cout << "Two Pointers Technique:" << endl;
    print(fourSum(nums, 0));
    
    return 0;
}
