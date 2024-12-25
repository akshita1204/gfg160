//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends




class Solution {
  public:
  bool search(vector<int>&arr,int x)
  {
      int low=0,high=arr.size()-1;
      while(low<=high)
      {
          int mid=(low+high)/2;
          if(arr[mid]==x) return true;
          else if(arr[mid]>x) high=mid-1;
          else low=mid+1;
      }
      return false;
  }
    // Function to search a given number in row-column sorted matrix.
    bool searchRowMatrix(vector<vector<int>> &mat, int x) {
        // code here
        int n=mat.size(), m=mat[0].size();
        for(int i=0;i<n;i++)
        {
            if(mat[i][0]<=x and x<=mat[i][m-1])
            {
                if(search(mat[i],x)) return true;
            }
        }
        return false;
        
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {

        int n, m;
        cin >> n >> m;
        vector<vector<int> > matrix(n);

        for (int i = 0; i < n; i++) {
            matrix[i].assign(m, 0);
            for (int j = 0; j < m; j++) {
                cin >> matrix[i][j];
            }
        }

        int x;
        cin >> x;
        Solution obj;
        if (obj.searchRowMatrix(matrix, x))
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

/*
https://www.geeksforgeeks.org/batch/gfg-160-problems/track/matrix-gfg-160/problem/search-in-a-row-wise-sorted-matrix
*/