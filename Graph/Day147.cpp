//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User Function Template
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int S) {
        // Code here
          vector<vector<pair<int, int>>> adj(V);
        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            adj[u].push_back({v, w});
        }
         priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq; //min heap
        vector<int>res(V,INT_MAX);
        res[S]=0;
        pq.push({0,S});
        while(!pq.empty())
        {
            int dis=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(auto &vec:adj[node])
            {
                int neigh=vec.first;
                int d=vec.second;
                if(d+dis<res[neigh]) 
                {
                    res[neigh]=d+dis;
                    pq.push({d+dis,neigh});
                }
            }
        }
        return res;
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
        int src;
        cin >> src;
        cin.ignore();

        Solution obj;
        vector<int> res = obj.dijkstra(V, edges, src);

        for (int i = 0; i < V; i++)
            cout << res[i] << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}
//https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1