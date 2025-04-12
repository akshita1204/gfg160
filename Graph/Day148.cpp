//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
   void dfs(vector<vector<int>>& image, int i, int j, int color, int newColor, int n, int m) {
        // Boundary and base condition check
        if (i < 0 || j < 0 || i >= n || j >= m || image[i][j] != color) return;
        
        image[i][j] = newColor; // Recolor
        
        // 4-directional DFS
        dfs(image, i + 1, j, color, newColor, n, m);
        dfs(image, i - 1, j, color, newColor, n, m);
        dfs(image, i, j + 1, color, newColor, n, m);
        dfs(image, i, j - 1, color, newColor, n, m);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int newColor) {
        // Code here
         int n = image.size();
        int m = image[0].size();
        int color = image[sr][sc];
        if (color != newColor) {
            dfs(image, sr, sc, color, newColor, n, m);
        }
        return image;
        
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> image(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cin >> image[i][j];
        }
        int sr, sc, newColor;
        cin >> sr >> sc >> newColor;
        Solution obj;
        vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
        for (auto i : ans) {
            for (auto j : i)
                cout << j << " ";
            cout << "\n";
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// https://www.geeksforgeeks.org/problems/flood-fill-algorithm1856/1