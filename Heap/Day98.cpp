//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  priority_queue<double>maxi;
  priority_queue<double,vector<double>,greater<double>>mini;
  
    vector<double>getMedian(vector<int> &arr) {
        // code here
        vector<double>ans;
        for(int num:arr)
        {
            if(maxi.empty() or num<=maxi.top()) maxi.push(num);
            else mini.push(num);
            
            //balance the size
            if(maxi.size()>mini.size() +1)
            {
                mini.push(maxi.top());
                maxi.pop();
            }
            else if(mini.size()>maxi.size())
            {
                maxi.push(mini.top());
                mini.pop();
            }
            
            //compute the median
            if(maxi.size()>mini.size())
            {
                ans.push_back(maxi.top());
            }
            else 
            {
                ans.push_back((maxi.top()+mini.top())/2.0);
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

        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        vector<double> ans = ob.getMedian(nums);
        cout << fixed << setprecision(1);
        for (auto &i : ans)
            cout << i << " ";
        cout << "\n";
        cout << "~" << endl;
    }
    return 0;
}
/*https://www.geeksforgeeks.org/problems/find-median-in-a-stream-1587115620/1*/