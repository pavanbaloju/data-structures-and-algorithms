#include <iostream>
#include <set>
#include <vector>
#include <list>
using namespace std;

class MyHashSet {
    int numBuckets;
    vector<list<int>> buckets;
    
    int hash_function(int key){
        return key % numBuckets;
    }
public:
    /** Initialize your data structure here. */
    MyHashSet() {
        numBuckets = 15000;
        buckets = vector<list<int>>(numBuckets, list<int>{});
    }
    
    void add(int key) {
        int i = hash_function(key);
        if(find(buckets[i].begin(), buckets[i].end(), key) == buckets[i].end())
            buckets[i].push_back(key);
    }
    
    void remove(int key) {
        int i = hash_function(key);
        auto it = find(buckets[i].begin(), buckets[i].end(), key);
        if(it != buckets[i].end())
            buckets[i].erase(it);
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int i = hash_function(key);
        if(find(buckets[i].begin(), buckets[i].end(), key) == buckets[i].end())
            return false;
        return true;
    }
};

int main()
{
    MyHashSet myHashSet;
    myHashSet.add(1);      // set = [1]
    myHashSet.add(2);      // set = [1, 2]
    myHashSet.contains(1); // return True
    myHashSet.contains(3); // return False, (not found)
    myHashSet.add(2);      // set = [1, 2]
    myHashSet.contains(2); // return True
    myHashSet.remove(2);   // set = [1]
    myHashSet.contains(2); // return False, (already removed)

    return 0;
}