//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<vector<int>> findTriplets(vector<int> &arr) {
        // Code here
       
        int n=arr.size();
        set<vector<int>>st;
        unordered_map<int,vector<pair<int,int>>>mp;
        for(int i=0;i<n;i++)
        {
          for(int j=i+1;j<n;j++)
          {
              mp[arr[i]+arr[j]].push_back({i,j});
          }
        }
        for(int i=0;i<n;i++)
        {
            int req=-arr[i];
            if(mp.find(req)!=mp.end())
            {
                for(auto it:mp[req])
                {
                    if(i!=it.first and i!=it.second)
                    {
                        vector<int>cur={i,it.first,it.second};
                        sort(cur.begin(),cur.end());
                        st.insert(cur);
                    }
                }
            }
        }
         vector<vector<int>>ans(st.begin(),st.end());
         return ans;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;

        vector<vector<int>> res = ob.findTriplets(arr);
        sort(res.begin(), res.end());
        if (res.size() == 0) {
            cout << "[]\n";
        }
        for (int i = 0; i < res.size(); i++) {
            for (int j = 0; j < res[i].size(); j++) {
                cout << res[i][j] << " ";
            }
            cout << endl;
        }
        cout << "~" << endl;
    }
}
/*
https://www.geeksforgeeks.org/batch/gfg-160-problems/track/hashing-gfg-160/problem/find-all-triplets-with-zero-sum
*/