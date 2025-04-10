//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int minCost(vector<vector<int>>& houses) {
        // code here
                int n = houses.size();
        vector<bool> visited(n, false);
        vector<int> minDist(n, INT_MAX); // Minimum cost to add each node
        minDist[0] = 0;

        int totalCost = 0;

        for (int i = 0; i < n; ++i) {
            int u = -1;

            // Find the unvisited node with the smallest distance
            for (int j = 0; j < n; ++j) {
                if (!visited[j] && (u == -1 || minDist[j] < minDist[u])) {
                    u = j;
                }
            }

            visited[u] = true;
            totalCost += minDist[u];

            // Update distances of remaining nodes
            for (int v = 0; v < n; ++v) {
                if (!visited[v]) {
                    int cost = abs(houses[u][0] - houses[v][0]) + abs(houses[u][1] - houses[v][1]);
                    minDist[v] = min(minDist[v], cost);
                }
            }
        }

        return totalCost;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> edges;

        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        Solution obj;

        cout << obj.minCost(edges);
        cout << "\n";
        cout << "~" << endl;
    }
}

//https://www.geeksforgeeks.org/problems/minimum-cost-to-connect-all-houses-in-a-city/1