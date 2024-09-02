#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
vector<int> shortestpath(vector<vector<pii>>& adj, int source) {
    // Min. Priority Queue.
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    
    // Shortest Distance array.
    vector<int> dist(adj.size(), INT_MAX);
    
    // set source dist. to 0.
    dist[source] = 0;
    
    // Push source to min. priority_queue 
    // <Weight, Source>
    pq.push({0, 0});
    
    while(!pq.empty()) {
        auto [u_w, u] = pq.top();
        pq.pop();
        
        // Avoid duplicates to process again.
        if(dist[u] < u_w) {
            continue;
        }
        
        // Explore neighbors!
        for(auto [v, w] : adj[u]) {
            if(dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
    
    return dist;
}

int32_t main() {
    vector<vector<pii>> adj(5, vector<pii>());
    
    adj[0].push_back({1, 5});
    adj[1].push_back({0, 5});
    
    adj[0].push_back({2, 2});
    adj[2].push_back({0, 2});
    
    adj[2].push_back({3, 1});
    adj[3].push_back({2, 1});
    
    adj[0].push_back({3, 6});
    adj[3].push_back({0, 6});
    
    adj[2].push_back({4, 5});
    adj[4].push_back({2, 5});
    
    int source = 0;
    vector<int> dist = shortestpath(adj, source);
    
    for(int x : dist) {
        cout << x << ' ';
    }
    
    cout << endl;
   
}