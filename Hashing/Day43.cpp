//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        // Code here
        unordered_map<int,int>mp;
        int ans=0;
        for(int i=0;i<arr.size();i++)
        {
            int rem=target-arr[i];
            if(mp.find(rem)!=mp.end())
            {
                ans+=mp[rem];
            }
           mp[arr[i]]++;
        }
        return ans;
    }
};
/*
ans=1+1+1
1=>1
5=>1
7=>1
-1=>1
5=>1
*/


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
        int target;
        cin >> target;
        cin.ignore();
        Solution ob;
        int res = ob.countPairs(arr, target);

        cout << res << endl << "~" << endl;
    }
    return 0;
}
/*
https://www.geeksforgeeks.org/batch/gfg-160-problems/track/hashing-gfg-160/problem/count-pairs-with-given-sum--150253
*/