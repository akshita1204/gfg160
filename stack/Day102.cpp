//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to calculate the span of stockâ€™s price for all n days.
    vector<int> calculateSpan(vector<int>& arr) {
        // write code here
       stack<int>st;
       vector<int>ans(arr.size(),1);
       for(int i=0;i<arr.size();i++)
       {
           while(!st.empty() and arr[i]>=arr[st.top()]) 
           {
               st.pop(); 
           }
           if(st.empty())
           {
               ans[i]=i+1;
           }
          else ans[i]=i-st.top();
          st.push(i);
       }
       return ans;
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
        vector<int> ans = obj.calculateSpan(arr);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
/*https://www.geeksforgeeks.org/problems/stock-span-problem-1587115621/1*/