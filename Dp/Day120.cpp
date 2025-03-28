//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// Function to return minimum number of jumps to end of array

class Solution {
  public:
    int minJumps(vector<int>& arr) {
        // code here
        if(!arr[0]) return -1; //no jump possible
        int ans=1;
        int jump=arr[0];
        int mx=0;
        for(int i=1;i<arr.size();i++)
        {
            mx--;
            jump--;
            mx=max(mx,arr[i]);
            if(!jump and i!=arr.size()-1)
            {
                if(mx<=0) return -1;
                jump=mx;
                mx=0;
                ans++;
            }
        }
        return ans;
        
    }
};




//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, i, j;
        vector<int> arr;
        string ip;
        int number;
        getline(cin, ip);
        stringstream ss(ip);

        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        cout << obj.minJumps(arr) << endl << "~\n";
    }
    return 0;
}

/*https://www.geeksforgeeks.org/problems/minimum-number-of-jumps-1587115620/1*/ 