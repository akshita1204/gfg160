//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
 void fdfs(int node,vector<int>&vis,vector<vector<int>>&adj,vector<int>&res)
  {
    
    vis[node]=1;
    res.push_back(node);
    for(int neigh:adj[node])
    {
        if(!vis[neigh])
        {
            fdfs(neigh,vis,adj,res);
        }
    }
  }
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        int n=adj.size();
        vector<int>res;
        vector<int>vis(n,0);
        fdfs(0,vis,adj,res);
        return res;
        
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
        vector<vector<int>> adj(
            V); // Use vector of vectors instead of array of vectors.

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
        vector<int> ans = obj.dfs(adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

//https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1