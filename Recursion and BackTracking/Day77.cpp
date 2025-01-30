//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  int N;
  bool isvalid(vector<vector<int>>&board,int r,int c)
  {
      
      for(int i=r-1;i>=0;i--)
      {
          if(board[i][c]==1) return false;
      }
      
      for(int i=r-1,j=c-1;i>=0 and j>=0;i--,j--)
      {
          if(board[i][j]==1) return false;
      }
      
      for(int i=r-1,j=c+1;i>=0 and j<N;i--,j++)
      {
          if(board[i][j]==1) return false;
      }
     
      return true;
  }
  
  
  void solve(vector<vector<int>>&board,int row,vector<int>&cur,vector<vector<int>>&ans)
  {
      if(row==N)
      {
          ans.push_back(cur);
          return;
      }
      for(int col=0;col<N;col++)
      {
          if(isvalid(board,row,col))
          {
              board[row][col]=1;
              cur.push_back(col+1);
              solve(board,row+1,cur,ans);
              board[row][col]=0;
              cur.pop_back();
          }
      }
      
  }
  
    vector<vector<int>> nQueen(int n) {
        // code here
        N=n;
        vector<vector<int>>board(N,vector<int>(N,0));
        vector<vector<int>>ans;
        vector<int>cur;
        solve(board,0,cur,ans);
        return ans;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if (ans.size() == 0)
            cout << -1 << "\n";
        else {
            sort(ans.begin(), ans.end());
            for (int i = 0; i < ans.size(); i++) {
                cout << "[";
                for (int u : ans[i])
                    cout << u << " ";
                cout << "] ";
            }
            cout << endl;
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
/*https://www.geeksforgeeks.org/batch/gfg-160-problems/track/recursion-and-backtracking-gfg-160/problem/n-queen-problem0315*/