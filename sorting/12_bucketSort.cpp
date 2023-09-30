#include <vector>
#include <iostream>
using namespace std;

// floor(noOfBuckets × array[i] / MAX)
void bucketSort(vector<int> &nums, int noOfBuckets)
{
    vector<vector<int>> buckets = vector<vector<int>>(noOfBuckets);
    int max = *max_element(nums.begin(), nums.end()) + 1;

    for (int num : nums)
    {
        int bucketIndex = noOfBuckets * num / max;
        buckets[bucketIndex].push_back(num);
    }

    for (vector<int> &bucket : buckets)
        sort(bucket.begin(), bucket.end());

    int idx = 0;
    for (vector<int> bucket : buckets)
    {
        for (int num : bucket)
        {
            nums[idx++] = num;
        }
    }
}

int main()
{
    vector<int> nums = {22, 50, 32, 28, 41, 12};
    bucketSort(nums, 5);
    for (int num : nums)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}