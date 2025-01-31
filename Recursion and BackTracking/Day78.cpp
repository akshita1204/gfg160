//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  bool isvalid(vector<vector<int>> &mat,int row,int col,int num)
  {
      for(int i=0;i<9;i++)
      {
          if(mat[row][i]==num) return false;
          else if(mat[i][col]==num) return false;
          else if(mat[3*(row/3) + i/3][3*(col/3) + i%3]==num) return false;
      }
      return true;
  }
  
  bool solve(vector<vector<int>> &mat,int n)
  {
      for(int row=0;row<9;row++)
      {
          for(int col=0;col<9;col++)
          {
              if(mat[row][col]==0)
              {
                  for(int num=1;num<=9;num++)
                  {
                      if(isvalid(mat,row,col,num))
                      {
                          mat[row][col]=num;
                          if(solve(mat,n)) return true;
                          mat[row][col]=0;
                      }
                  }
                  return false;
              }
          }
      }
      return true;
  }
  // Function to find a solved Sudoku.
    void solveSudoku(vector<vector<int>> &mat) {
        // code here
        int n=mat.size();
        solve(mat,n);
    }
};

//{ Driver Code Starts.

vector<int> inputLine() {
    string str;
    getline(cin, str);
    stringstream ss(str);
    int num;
    vector<int> res;
    while (ss >> num) {
        res.push_back(num);
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<vector<int>> grid;
        for (int i = 0; i < 9; i++) {
            vector<int> v = inputLine();
            grid.push_back(v);
        }

        Solution ob;

        ob.solveSudoku(grid);

        for (auto v : grid) {
            for (auto elem : v) {
                cout << elem << " ";
            }
            cout << endl;
        }

        cout << "~" << endl;
    }
    return 0;
}
/*https://www.geeksforgeeks.org/batch/gfg-160-problems/track/recursion-and-backtracking-gfg-160/problem/solve-the-sudoku-1587115621*/ 