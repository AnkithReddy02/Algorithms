#include <bits/stdc++.h>
using namespace std;
/*

Longest Increasing Subsequence with Sorted pairs.

(a, b) < (c, d)

if a < c and b < d;

Idea:

Sort the pairs
Since the first values are sorted, you need to find LIS on the second values.
Problem: duplicate of first values and respective ascending value of second values.
Solution: Order the second values of duplicate values in the descending order. 

*/
int find_LIS(const vector<int>& arr) {
    vector<int> lis;
    for (int val : arr) {
        auto pos = lower_bound(lis.begin(), lis.end(), val);
        if (pos == lis.end()) {
            lis.push_back(val);
        } else {
            *pos = val;
        }
    }
    return lis.size();
}

bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
    if(a.first == b.first) {
        return a.second > b.second;
    }
    return a.first < b.first;
}

int getLargestIndexLen(const vector<int>& feature1, const vector<int>& feature2) {
    vector<pair<int, int>> pairs;
    for(size_t i = 0; i < feature1.size(); ++i) {
        pairs.emplace_back(feature1[i], feature2[i]);
    }

    sort(pairs.begin(), pairs.end(), cmp);
    
    vector<int> sorted_feature2;
    for(const auto& p : pairs) {
        sorted_feature2.push_back(p.second);
    }
    
    return find_LIS(sorted_feature2);
}

int main() {
    vector<int> feature1 = {10, 20, 10, 30, 20};
    vector<int> feature2 = {3, 2, 4, 1, 5};
    
    int result = getLargestIndexLen(feature1, feature2);
    cout << result << endl;
    
    return 0;
}
