//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minRemoval(vector<vector<int>> &intervals) {
        // code here
        int n=intervals.size();
        int ans=0;
        sort(intervals.begin(),intervals.end());
        int prev=intervals[0][1];
        for(int i=1;i<n;i++)
        {
            if(intervals[i][0]<prev)
            {
                ans++;
                prev=min(prev,intervals[i][1]);
            }
            else prev=intervals[i][1];
        }
        return ans;
    }
};
// [[1, 2], [1, 3], [2, 3], [3, 4]]


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<vector<int>> intervals(N, vector<int>(2));
        for (int i = 0; i < N; i++) {
            cin >> intervals[i][0] >> intervals[i][1];
        }
        Solution obj;
        cout << obj.minRemoval(intervals) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
/*
https://www.geeksforgeeks.org/batch/gfg-160-problems/track/sorting-gfg-160/problem/non-overlapping-intervals
*/