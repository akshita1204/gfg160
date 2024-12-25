//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    void setMatrixZeroes(vector<vector<int>> &mat) {
        // code 
        int n=mat.size();
        int m=mat[0].size();
        bool firstrowzero=false, firstcolzero=false;
        //check if the first row has any zero
        for(int i=0;i<m;i++)
        {
            if(mat[0][i]==0) 
            {
                firstrowzero=true;
                break;
            }
        }
        //check if the first col has any zero
        for(int i=0;i<n;i++)
        {
            if(mat[i][0]==0) 
            {
                firstcolzero=true;
                break;
            }
        }
        //use the first row and col to mark others rows and cols
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                if(mat[i][j]==0)
                {
                    mat[i][0]=0;
                    mat[0][j]=0;
                }
            }
        }
        //mark the cells based zero based on marking
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
               if(mat[i][0]==0 or mat[0][j]==0)
               {
                   mat[i][j]=0;
               }
            }
        }
        //marking based on first row if needed
        if(firstrowzero)
        {
            for(int j=0;j<m;j++)
            {
                mat[0][j]=0;
            }
        }
          //marking based on first col if needed
        if(firstcolzero)
        {
            for(int i=0;i<n;i++)
            {
                mat[i][0]=0;
            }
        }
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int> > arr(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> arr[i][j];
            }
        }
        Solution ob;
        ob.setMatrixZeroes(arr);
        for (auto x : arr) {
            for (auto y : x)
                cout << y << " ";
            cout << endl;
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
/* PROBLEM LINK=>
https://www.geeksforgeeks.org/batch/gfg-160-problems/track/matrix-gfg-160/problem/set-matrix-zeroes
 */
