//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:

    // Function to find minimum time required to rot all oranges.
    int orangesRotting(vector<vector<int>>& mat) {
       int n=mat.size(),m=mat[0].size();
       queue<pair<int,int>>q;
       int fo=0;
      //count the fresh oranges and push the rotten into the queue
       for(int i=0;i<n;i++)
       {
           for(int j=0;j<m;j++)
           {
               if(mat[i][j]==1) fo++;
               else if(mat[i][j]==2) q.push({i,j});
           }
       }
       q.push({-1,-1}); //to mark the level 
       int ans=0;
       vector<vector<int>> dir={{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
       while(!q.empty())
       {
           auto cell=q.front();
           q.pop();
           //agar ek level hogya hai
           if(cell.first==-1 and cell.second==-1)
           {
               ans++;
               if(!q.empty()) q.push({-1,-1});
               else break;
           }
           else
           {
               int i=cell.first;
               int j=cell.second;
               for(int d=0;d<4;d++)
               {
                   int newi=i+dir[d][0];
                   int newj=j+dir[d][1];
                   if(newi<0 or newj<0 or newi>=n or newj>=m) continue;
                   if(mat[newi][newj]==2 or mat[newi][newj]==0) continue;
                   fo--;
                   mat[newi][newj]=2;
                   q.push({newi,newj});
               }
           }
       }
       return (fo==0) ?ans-1 : -1;
    }
};



//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> mat[i][j];
            }
        }
        Solution obj;
        int ans = obj.orangesRotting(mat);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends

//https://www.geeksforgeeks.org/problems/rotten-oranges2536/1