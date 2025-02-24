//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find largest rectangular area possible in a given histogram.
    int getMaxArea(vector<int> &arr) {
            int n=arr.size();
        int nsi[n];
        stack<int>st;
        nsi[n-1]=n;
        st.push(n-1);
        for(int i=n-2;i>=0;i--)
        {
            while(st.size()>0 && arr[st.top()]>=arr[i]) st.pop();
            if(st.size()==0) nsi[i]=n;
            else nsi[i]=st.top();
            st.push(i);
        }
        stack<int>gt;
        int psi[n];
        psi[0]=-1;
        gt.push(0);
            for(int i=1;i<n;i++)
        {
            while(gt.size()>0 && arr[gt.top()]>=arr[i]) gt.pop();
            if(gt.size()==0) psi[i]=-1;
            else psi[i]=gt.top();
            gt.push(i);
        }
        int b,h;
        int maxa=0;
        int a;
        for(int i=0;i<n;i++)
        {   h=arr[i];
            b=nsi[i]-psi[i]-1;
            a=h*b;
            maxa=max(maxa,a);
        
        }
        return maxa;
    }
};



//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.getMaxArea(arr);
        cout << res << endl;
        cout << "~" << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

/*https://www.geeksforgeeks.org/problems/maximum-rectangular-area-in-a-histogram-1587115620/1*/ 