//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {

    // Function to find the trapped water between the blocks.
  public:
    int maxWater(vector<int> &arr) {
        // code here
        int n=arr.size();
        vector<int>pre(n);
        vector<int>suf(n);
        pre[0]=-1;
        suf[n-1]=-1;
        int maxi=arr[0];
        for(int i=1;i<n;i++)
        {
            pre[i]=maxi;
            if(arr[i]>maxi) maxi=arr[i];
        }
        //pre= -1 3 3 3 3 4
        int nmaxi=arr[n-1];
         for(int i=n-2;i>=0;i--)
        {
            suf[i]=nmaxi;
            if(arr[i]>nmaxi) nmaxi=arr[i];
        }
        //suf= 4 4 4 4 4 -1
        vector<int>mini(n);
        for(int i=0;i<n;i++)
        {
            mini[i]=min(pre[i],suf[i]);
        }
        // -1 3 3 3 3 -1
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(arr[i]<mini[i]) ans+=(mini[i]-arr[i]);
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
        vector<int> arr;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.maxWater(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

/*https://www.geeksforgeeks.org/batch/gfg-160-problems/track/two-pointer-technique-gfg-160/problem/trapping-rain-water-1587115621*/