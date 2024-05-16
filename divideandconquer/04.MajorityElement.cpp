#include <iostream>
#include <vector>

using namespace std;

// Problem Statement: Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊n/2⌋ times.

// Intuition: Use a divide-and-conquer approach to recursively find the majority element in each half of the array and combine the results.

// DSA Strategy/Pattern: Divide and Conquer

class Solution {
public:
    // Function to find the majority element
    int majorityElement(vector<int>& nums) {
        return majorityElementRec(nums, 0, nums.size() - 1);
    }

private:
    // Recursive function to find the majority element in the subarray nums[left:right]
    /*
    Approach:
    1. Base case: If the subarray contains only one element, return that element.
    2. Find the middle index to split the array into two halves.
    3. Recursively find the majority element in the left half.
    4. Recursively find the majority element in the right half.
    5. If both halves agree on the majority element, return it.
    6. Otherwise, count each candidate's occurrences in the entire subarray and return the element with the higher count.
    
    Time Complexity: O(n log n) due to the divide and conquer approach.
    Space Complexity: O(log n) due to the recursion stack.
    */
    int majorityElementRec(const vector<int>& nums, int left, int right) {
        // Base case: if the subarray contains only one element, return that element
        if (left == right) {
            return nums[left];
        }

        // Find the middle index to split the array into two halves
        int mid = left + (right - left) / 2;

        // Recursively find the majority element in the left half
        int leftMajority = majorityElementRec(nums, left, mid);

        // Recursively find the majority element in the right half
        int rightMajority = majorityElementRec(nums, mid + 1, right);

        // If both halves agree on the majority element, return it
        if (leftMajority == rightMajority) {
            return leftMajority;
        }

        // Otherwise, count each candidate's occurrences in the entire subarray
        int leftCount = countInRange(nums, leftMajority, left, right);
        int rightCount = countInRange(nums, rightMajority, left, right);

        // Return the element with the higher count
        return leftCount > rightCount ? leftMajority : rightMajority;
    }

    // Helper function to count the number of occurrences of a candidate element in the subarray nums[left:right]
    int countInRange(const vector<int>& nums, int num, int left, int right) {
        int count = 0;
        for (int i = left; i <= right; ++i) {
            if (nums[i] == num) {
                ++count;
            }
        }
        return count;
    }
};

int main() {
    Solution sol;

    // Example usage
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
    int result = sol.majorityElement(nums);

    // Print the result
    cout << "Majority element: " << result << endl;

    return 0;
}
