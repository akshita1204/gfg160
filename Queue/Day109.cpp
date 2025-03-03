//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> longestSubarray(vector<int>& arr, int x) {
        // code here
            int n= arr.size();
          int left=0;
          int max_len=0;
          multiset<int> window;
          vector<int> best_yet;
          
          for(int right=0;right<n;right++)
          {
              window.insert(arr[right]);
          
          
          while(*window.rbegin()-*window.begin()>x)
          {
              window.erase(window.find(arr[left]));
              left++;
          }
          
          if(right-left + 1 > max_len)
          {
              max_len=right-left + 1;
              best_yet=vector<int>(arr.begin()+left,arr.begin()+right+1);
          }
          }
          return best_yet;
        
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
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution ob;
        vector<int> ans = ob.longestSubarray(arr, k);
        for (auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
/*https://www.geeksforgeeks.org/problems/longest-bounded-difference-subarray/1*/