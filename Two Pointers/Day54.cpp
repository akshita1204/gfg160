//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        // Complete the function
        //unordered_map<int,int>mp;
        int i=0,j=arr.size()-1,ans=0;
        while(i<j)
        {
            int sum=arr[i]+arr[j];
            if(sum==target)
            {
                int cl=1,cr=1;
                while(i<j and arr[i]==arr[i+1]) 
                {
                    cl++;
                    i++;
                }
                 while(j>i and arr[j]==arr[j-1]) 
                {
                    cr++;
                    j--;
                }
                if(arr[i]==arr[j]) ans+=(cl*(cl-1))/2;
                else ans+=(cl*cr);
                i++;
                j--;
            }
            else if(sum<target) i++;
            else j--;
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
        int target;
        string input;
        getline(cin, input);

        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        cin >> target;
        cin.ignore();
        Solution obj;
        cout << obj.countPairs(arr, target) << endl;
        cout << "~\n";
    }

    return 0;
}
/*
https://www.geeksforgeeks.org/batch/gfg-160-problems/track/two-pointer-technique-gfg-160/problem/pair-with-given-sum-in-a-sorted-array4940
*/