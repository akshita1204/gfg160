//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        unordered_map<int,vector<int>>adj;
        for(auto e:edges)
        {
            adj[e[0]].push_back(e[1]);
        }
          queue<int>q;
       vector<int>indegree(V,0);
       for(int u=0;u<V;u++)
       {
           for(int &v:adj[u])
           {
               indegree[v]++;
           }
       }
       //fill queue
       int c=0;
       for(int i=0;i<V;i++)
       {
           if(indegree[i]==0) 
           {
               q.push(i);
               c++;
           }
       }
       while(!q.empty())
       {
           int u=q.front();
           q.pop();
           for(auto &v:adj[u])
           {
               indegree[v]--;
               if(indegree[v]==0) 
               {
                   q.push(v);
                   c++;
               }
           }
       }
       if(c==V) return false;
       return true;
        
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        int V, E;
        cin >> V >> E;
        cin.ignore();
        vector<vector<int>> edges;
        for (int i = 1; i <= E; i++) {
            int u, v;
            cin >> u >> v;
            edges.push_back({u, v});
        }

        Solution obj;
        bool ans = obj.isCyclic(V, edges);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";
    }
    return 0;
}
//https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1