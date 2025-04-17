//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int findMinCycle(int V, vector<vector<int>>& edges) {
        // code here
         vector<vector<pair<int, int>>> adj(V);
        for (auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];
            adj[u].push_back({v, w});
        }

        int minCycle = INT_MAX;

        // Try removing each edge and run Dijkstra to find shortest u-v path
        for (auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];

            // Temporarily remove edge u-v
            auto it1 = find_if(adj[u].begin(), adj[u].end(), [&](pair<int, int> p){ return p.first == v && p.second == w; });
            auto it2 = find_if(adj[v].begin(), adj[v].end(), [&](pair<int, int> p){ return p.first == u && p.second == w; });
            if (it1 != adj[u].end()) adj[u].erase(it1);
            if (it2 != adj[v].end()) adj[v].erase(it2);

            // Dijkstra from u
            vector<int> dist(V, 1e9);
            dist[u] = 0;
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
            pq.push({0, u});
            
            while (!pq.empty()) {
                pair<int, int> temp = pq.top(); pq.pop();
                int d = temp.first;
                int node = temp.second;
                if (d > dist[node]) continue;
                for (auto &p : adj[node]) {
                    int nbr = p.first;
                    int wt = p.second;
                    if (dist[nbr] > d + wt) {
                        dist[nbr] = d + wt;
                        pq.push({dist[nbr], nbr});
                    }
                }
            }

            // If there is a path from u to v, it forms a cycle
            if (dist[v] != 1e9)
                minCycle = min(minCycle, dist[v] + w);

            // Restore edge
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        return (minCycle == INT_MAX) ? -1 : minCycle;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> edges;
        int i = 0;
        while (i++ < E) {
            int u, v, w;
            cin >> u >> v >> w;
            edges.push_back({u, v, w});
            edges.push_back({v, u, w});
        }

        Solution obj;
        int res = obj.findMinCycle(V, edges);

        cout << res << endl;
    }

    return 0;
}
// https://www.geeksforgeeks.org/problems/minimum-weight-cycle/1