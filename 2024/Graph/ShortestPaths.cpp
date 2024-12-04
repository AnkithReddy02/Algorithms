#include<bits/stdc++.h>
using namespace std;

#define pii pair<int, int>

// Single Source --> ElogV --> logV is from PQ.
int djks(vector<vector<pair<int, int>>>& graph, int source) {
    
    int n = graph.size();
    
    int dist[n];
    
    fill(dist, dist + n, INT_MAX);
    
    dist[source] = 0;
    
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    
    pq.push({0, source});
    
    
    while(!pq.empty()) {
        auto f = pq.top();
        pq.pop();
        
        int u = f.second;
        int d = f.first;
        
        for(auto vp : graph[u]) {
            int v = vp.first;
            int vd = vp.second;
            if(dist[u] + vd < dist[v]) {
                dist[v] = dist[u] + vd;
                pq.push({dist[v], v});
            }
        }
    }
    
    for(int i = 0; i < n; i++) {
        cout << i << " : " << dist[i] << endl;
    }
    
    return 0;
}

// Single Source -- O(V * E)
int bellman(vector<vector<pair<int, int>>>& graph, int source) {
    int n = graph.size();
  
    
    int dist[n];
    
    fill(dist, dist + n, INT_MAX);
    
    dist[source] = 0;
    
    // Relax n-1 times since longest shortest path is atMax of n - 1 edges.
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < graph.size(); j++) {
            int u = j;
            
            for(auto vp : graph[j]) {
                int v = vp.first;
                int d = vp.second;
                
                if(dist[u] < dist[v] - d) {
                    dist[v] = dist[u] + d;
                }
            }
        }
    }
    
    for(int i = 0; i < n; i++) {
        cout << i << " : " << dist[i] << endl;
    }
    
    return 0;
}

// All-pairs shortest path.
// Single Source -- O(V * V * V)
int floyd(vector<vector<pair<int, int>>>& graph) {
    int n = graph.size();
  
    vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
    
    for(int i = 0; i < n; i++) {
        dist[i][i] = 0;
    }
    
    for(int i = 0; i < graph.size(); i++) {
        for(int j = 0; j < graph[i].size(); j++) {
            dist[i][graph[i][j].first] = graph[i][j].second;
        }
    }
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < n; k++) {
                // Prevent overflow.
                if(dist[j][k] - dist[j][i] > dist[i][k]) {
                    dist[j][k] = dist[j][i] + dist[i][k];
                }
            }
        }
    }
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << i << " --> " << j << " = " << dist[i][j] << endl;
        }
    }
    
    return 0;
}

int main() {
    
    int n = 5;
    vector<vector<pair<int, int>>> graph(n, vector<pair<int, int>>());
    graph[0].emplace_back(1, 10);
    graph[0].emplace_back(2, 3);
    graph[0].emplace_back(3, 20);
    graph[0].emplace_back(4, 5);
    graph[1].emplace_back(2, 2);
    graph[2].emplace_back(3, 6);
    graph[3].emplace_back(4, 1);

    floyd(graph);
}