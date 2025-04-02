//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(vector<vector<int>> &adj) {
        int V=adj.size();
      vector<int>vis(V,0);
       vis[0]=1;
       queue<int>q;
       q.push(0);
       vector<int>v;
       while(!q.empty())
       {
           int cur=q.front();
           q.pop();
           v.push_back(cur);
           for(auto neigh: adj[cur])
           {
               if(!vis[neigh])
               {
                   vis[neigh]=1;
                   q.push(neigh);
               }
           }
       }
       return v;
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        int V;
        cin >> V;
        cin.ignore();
        // Use vector of vectors instead of array of vectors.
        vector<vector<int>> adj(V);

        for (int i = 0; i < V; i++) {
            string input;
            getline(cin, input);
            int num;
            vector<int> node;
            stringstream ss(input);
            while (ss >> num) {
                node.push_back(num);
            }
            adj[i] = node;
        }

        Solution obj;
        vector<int> ans = obj.bfs(adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

/*https://www.geeksforgeeks.org/problems/bfs-traversal-of-graph/1*/