#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int fourSumCount(vector<int> &A, vector<int> &B, vector<int> &C, vector<int> &D)
{
    unordered_map<int, int> map;
    for(auto a : A) {
            for(auto b : B) {
                ++map[a+b];
            }
        }
        int count = 0;
        for(auto c : C) {
            for(auto d : D) {
                auto it = map.find(0 - c - d);
                if(it != map.end()) {
                    count += it->second;
                }
            }
        }
    return count;
}
int main()
{
    vector<int> A = {1, 2};
    vector<int> B = {-2, -1};
    vector<int> C = {-1, -2};
    vector<int> D = {0, 2};
    cout<<fourSumCount(A, B, C, D);
    return 0;
}