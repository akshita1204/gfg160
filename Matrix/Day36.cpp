//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int> > &mat) {
        // code here
        int n=mat.size(), m=mat[0].size();
        int sr=0, sc=0 , er=n-1, ec=m-1;
        vector<int>ans;
        int t=n*m, c=0;
        while(sr<=er and sc<=ec)
        {
            for(int j=sc;j<=ec and c<t; j++)
            {
                ans.push_back(mat[sr][j]); 
                c++;
            }
            sr++;
            
            for(int i=sr;i<=er and c<t;i++)
            {
                ans.push_back(mat[i][ec]);
                c++;
            }
            ec--;
            
            for(int j=ec;j>=sc and c<t;j--)
            {
                ans.push_back(mat[er][j]);
                c++;
            }
            er--;
            
            for(int i=er; i>=sr and c<t;i--)
            {
                ans.push_back(mat[i][sc]);
                c++;
            }
            sc++;
            
        }
        return ans;
       
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r);

        for (int i = 0; i < r; i++) {
            matrix[i].assign(c, 0);
            for (int j = 0; j < c; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
/*
https://www.geeksforgeeks.org/batch/gfg-160-problems/track/matrix-gfg-160/problem/spirally-traversing-a-matrix-1587115621
 */