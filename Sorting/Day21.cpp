//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void sort012(vector<int>& arr) {
        int z=0,o=0,t=0;
       for(int i=0;i<arr.size();i++)
       {
           if(arr[i]==0) z++;
           else if(arr[i]==1) o++;
           else t++;
       }
       int idx=0;
       while(z--)
       {
           arr[idx]=0;
           idx++;
       }
        while(o--)
       {
           arr[idx]=1;
           idx++;
       }
        while(t--)
       {
           arr[idx]=2;
           idx++;
       }
       
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        vector<int> a;
        string input;
        int num;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }
        Solution ob;
        ob.sort012(a);

        int n = a.size();
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }

        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

/*
https://www.geeksforgeeks.org/batch/gfg-160-problems/track/sorting-gfg-160/problem/sort-an-array-of-0s-1s-and-2s4231
*/