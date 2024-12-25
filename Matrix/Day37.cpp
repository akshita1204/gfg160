//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to rotate matrix anticlockwise by 90 degrees.
    void rotateby90(vector<vector<int>>& mat) {
        // code here
        int n=mat.size();
        vector<vector<int>>matrix(n,vector<int>(n,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                matrix[i][j]=mat[j][i];
                /*
                1 4 7
                2 5 8
                3 6 9
                */
            }
        }
        for(int k=0;k<n;k++)
        {
           int top=0 ,bottom=n-1;
           while(top<bottom)
           {
               swap(matrix[top][k],matrix[bottom][k]);
               top++;
               bottom--;
           }
        }
        mat=matrix;
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<vector<int> > matrix(n);

        for (int i = 0; i < n; i++) {
            matrix[i].assign(n, 0);
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        ob.rotateby90(matrix);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j)
                cout << matrix[i][j] << " ";
            cout << endl;
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
/*
https://www.geeksforgeeks.org/batch/gfg-160-problems/track/matrix-gfg-160/problem/rotate-by-90-degree-1587115621
 */