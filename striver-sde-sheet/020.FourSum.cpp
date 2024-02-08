#include <iostream>
#include <vector>
#include <set>
using namespace std;

// Function to find all unique quadruplets in the array that sum up to the target.
// Intuition:
// This function uses a brute-force approach to find all unique quadruplets by iterating through all combinations of four elements.
// Approach:
// Iterate through each combination of four elements using nested loops.
// Check if the sum of the four elements equals the target.
// If so, add the quadruplet to a set to ensure uniqueness.
// Convert the set of quadruplets to a vector and return.
// Time complexity: O(n^4), where n is the size of the input array.
// Space complexity: O(n^4), the set may contain all unique quadruplets.
vector<vector<int>> fourSumBrute(vector<int> &nums, int target) {
    int n = nums.size();
    set<vector<int>> unique;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                for (int l = k + 1; l < n; l++) {
                    if (nums[i] + nums[j] + nums[k] + nums[l] == target) {
                        unique.insert({nums[i], nums[j], nums[k], nums[l]});
                    }
                }
            }
        }
    }
    vector<vector<int>> res(unique.begin(), unique.end());
    return res;
}

// Function to find all unique quadruplets in the array that sum up to the target using hashing.
// Intuition:
// This function uses a hashing approach to find all unique quadruplets by reducing the problem to finding two-sum pairs.
// Approach:
// Sort the input array.
// Iterate through all pairs of elements (i, j) using nested loops.
// Use a set to store the elements encountered in the inner loop.
// Calculate the target for the two-sum problem as the difference between the target and the sum of elements at indices i and j.
// Check if the target exists in the set. If so, add the quadruplet to a set to ensure uniqueness.
// Convert the set of quadruplets to a vector and return.
// Time complexity: O(n^3), where n is the size of the input array.
// Space complexity: O(n^2), the set may contain all unique pairs.
vector<vector<int>> fourSumHash(vector<int> &nums, int target) {
    int n = nums.size();
    set<vector<int>> unique;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            set<long long> hashset;
            for (int k = j + 1; k < n; k++) {
                long long sum = nums[i] + nums[j];
                sum += nums[k];
                long long fourth = target - sum;
                if (hashset.find(fourth) != hashset.end()) {
                    vector<int> temp = {nums[i], nums[j], nums[k], (int)(fourth)};
                    sort(temp.begin(), temp.end());
                    unique.insert(temp);
                }
                hashset.insert(nums[k]);
            }
        }
    }
    vector<vector<int>> res(unique.begin(), unique.end());
    return res;
}

// Function to find all unique quadruplets in the array that sum up to the target using two pointers technique.
// Intuition:
// This function uses a two pointers technique to find all unique quadruplets by reducing the problem to finding two-sum pairs.
// Approach:
// Sort the input array.
// Iterate through all pairs of elements (i, j) using nested loops.
// Use two pointers (left and right) to find two additional elements that sum up to the target.
// Skip duplicate elements to ensure uniqueness.
// Time complexity: O(n^3), where n is the size of the input array.
// Space complexity: O(1), no extra space used besides variables.
vector<vector<int>> fourSum(vector<int> &nums, int target) {
    int n = nums.size();
    vector<vector<int>> res;

    sort(nums.begin(), nums.end());
    for (int i = 0; i < n; i++) {
        // Skip duplicate elements
        if (i > 0 && nums[i] == nums[i - 1])
            continue;
        for (int j = i + 1; j < n; j++) {
            // Skip duplicate elements
            if (j > i + 1 && nums[j] == nums[j - 1])
                continue;

            int left = j + 1;
            int right = n - 1;
            long long newTarget = target - nums[i] - nums[j];

            while (left < right) {
                long long sum = nums[left] + nums[right];
                if (sum == newTarget) {
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
