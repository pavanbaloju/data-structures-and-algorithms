#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;


bool checkIfExist(vector<int> &arr)
{
    int count = arr.size();
    for (int i = 0; i < count; i++)
    {
        for (int j = i + 1; j < count; j++)
        {
            if (arr[i] == 2 * arr[j] || 2 * arr[i] == arr[j])
            {
                return true;
            }
        }
    }
    return false;
}


bool checkIfExistHashSet(vector<int> &arr)
{
    unordered_set<int> seen;
    for (int num : arr)
    {
        if (seen.count(num * 2) || (num % 2 == 0 && seen.count(num / 2)))
        {
            return true;
        }
        seen.insert(num);
    }
    return false;
}

// Custom binary search function to avoid using STL directly
bool binarySearch(const vector<int>& arr, int start, int end, int target) {
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (arr[mid] == target) {
            return true;
        } else if (arr[mid] < target) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return false;
}

bool checkIfExistBinarySearch(vector<int>& arr) {
    sort(arr.begin(), arr.end()); // Sort the array
    int n = arr.size();
    // Iterate through the array and use binary search to find the required condition
    for (int i = 0; i < n; i++) {
        if (binarySearch(arr, 0, n - 1, 2 * arr[i])) {
            // Ensure i != j by checking the indices
            if (2 * arr[i] != arr[i] || count(arr.begin(), arr.end(), arr[i]) > 1) {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    vector<int> nums = {10, 2, 5, 3};

    // Using the brute force approach
    cout << "Using brute force approach: ";
    cout << checkIfExist(nums) << endl;

    // Using the HashSet approach
    cout << "Using HashSet approach: ";
    cout << checkIfExistHashSet(nums) << endl;

    return 0;
}
