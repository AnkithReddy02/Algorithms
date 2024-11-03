#include<bits/stdc++.h>
using namespace std;

/*
Problem: Find the number of intervals each interval_i is intersecting with. 0 <= i <= n - 1
Constraints: 1 <= n <= 1e5

Solution: LineSweep + Binary Search
*/

vector<int> solve(vector<vector<int>>& intervals) {
    // Sort the intervals;
    sort(intervals.begin(), intervals.end());
    
    
    vector<int> prefixSum(intervals.size() + 1, 0);
    // Ordering is left for now. It can be integrated later on.
    vector<int> result;
    
    for(int i = 0; i < intervals.size(); ++i) {
        
        int ans = 0;
        
        // Line Sweep
        if(i) {
            prefixSum[i] += prefixSum[i-1];
        }
        
        // Backward Intersection.
        ans += prefixSum[i];
        
        // ** Forward Intersection.
        vector<int> search = {intervals[i][1] + 1, 0};
        
        // lower_bound to compute the intersecting ranges.
        auto it = lower_bound(intervals.begin() + i + 1, intervals.end(), search);
        
        int numIntersectedForward = it - (intervals.begin() + i);
        
        it--;
        
        int startIndex = i + 1;
        int endIndex = it - intervals.begin();
        
        ans += numIntersectedForward;
        
        // Line Sweep
        if(startIndex < endIndex) {
            prefixSum[startIndex]++;
            prefixSum[endIndex + 1]--;
        }
        
        result.push_back(ans);
    }
    
    return result;
}

int main() {
    vector<vector<int>> intervals = {{1, 2}, {1, 5}, {1, 6}, {2, 3}, {2, 4}, {3, 6}};
    
    vector<int> result = solve(intervals);
    
    for(int x : result) {
        cout << x << ' ';
    }
    
    cout << endl;
}