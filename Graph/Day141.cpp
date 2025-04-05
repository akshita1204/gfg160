//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
void dfs(int i,int j,vector<vector<char>>&grid,int n,int m)
  {
      if(i<0 or j<0 or i>=n or j>=m ) return;
      if(grid[i][j]!='L') return;
      grid[i][j]='V';
      dfs(i+1,j,grid,n,m);
      dfs(i-1,j,grid,n,m);
      dfs(i,j+1,grid,n,m);
      dfs(i,j-1,grid,n,m);
      dfs(i+1,j+1,grid,n,m);
      dfs(i-1,j+1,grid,n,m);
      dfs(i+1,j-1,grid,n,m);
      dfs(i-1,j-1,grid,n,m);
  }
    int countIslands(vector<vector<char>>& grid) {
        // Code here
                int c=0;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='L')
                {
                    dfs(i,j,grid,n,m);
                    c++;
                }
            }
        }
        return c;
        
        

    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.countIslands(grid);
        cout << ans << '\n';

        cout << "~"
             << "\n";
    }
    return 0;
}
//https://www.geeksforgeeks.org/problems/find-the-number-of-islands/1