//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        // Code here
        sort(arr.begin(),arr.end());
        vector<vector<int>>ans;
         ans.push_back(arr[0]); 
        //add the first interval
        for(int i=1;i<arr.size();i++)
        {
            if(arr[i][0]> ans.back()[1])
            {
                ans.push_back(arr[i]);
            }
            else 
            {
            ans.back()[1]=max(ans.back()[1],arr[i][1]);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<vector<int>> arr(n);
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            arr[i].push_back(x);
            arr[i].push_back(y);
        }
        Solution obj;
        vector<vector<int>> ans = obj.mergeOverlap(arr);
        for (auto i : ans) {
            for (auto j : i) {
                cout << j << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}
/*
https://www.geeksforgeeks.org/batch/gfg-160-problems/track/sorting-gfg-160/problem/overlapping-intervals--170633
*/