#include <iostream>
#include <set>
#include <vector>
#include <list>
using namespace std;

#include <iostream>
#include <set>
#include <vector>
#include <list>
using namespace std;

class MyHashMap
{
    vector<int> _v;

public:
    MyHashMap() : _v(1000001, -1)
    {
    }

    void put(int key, int value)
    {
        _v[key] = value;
    }

    int get(int key)
    {
        return _v[key];
    }

    void remove(int key)
    {
        _v[key] = -1;
    }
};

int main()
{
    MyHashMap myHashMap;
    myHashMap.put(1, 1); // The map is now [[1,1]]
    myHashMap.put(2, 2); // The map is now [[1,1], [2,2]]
    myHashMap.get(1);    // return 1, The map is now [[1,1], [2,2]]
    myHashMap.get(3);    // return -1 (i.e., not found), The map is now [[1,1], [2,2]]
    myHashMap.put(2, 1); // The map is now [[1,1], [2,1]] (i.e., update the existing value)
    myHashMap.get(2);    // return 1, The map is now [[1,1], [2,1]]
    myHashMap.remove(2); // remove the mapping for 2, The map is now [[1,1]]
    myHashMap.get(2);    // return -1 (i.e., not found), The map is now [[1,1]]

    return 0;
}