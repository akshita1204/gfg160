//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> singleNum(vector<int>& arr) {
        // Code here.
        int n=arr.size();
        vector<int>ans;
        unordered_map<int,int> map;
        
        for(int& num : arr){
            map[num]++;
        }
        for(auto& pair : map){
            if(pair.second == 1){
                ans.push_back(pair.first);
            }
        }
        if(ans[0] > ans[1]){
            swap(ans[0],ans[1]);
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

        Solution ob;
        vector<int> ans = ob.singleNum(arr);
        for (auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
//https://www.geeksforgeeks.org/problems/finding-the-numbers0215/1