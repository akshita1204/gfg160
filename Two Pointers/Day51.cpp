//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int countTriplets(vector<int> &arr, int target) {
        // Code Here
        int n=arr.size();
        int c=0;
        for(int i=0;i<n-2;i++)
        {
            int j=i+1,k=n-1;
            while(j<k)
            {
                int sum=arr[i]+arr[j]+arr[k];
                if(sum==target)
                {
                    if(arr[j]==arr[k])
                    {
                    int numele=k-j+1;
                    c+=(numele*(numele-1))/2;
                    break;
                    }
                    int cj=1,ck=1;
                    while(j+1<k and arr[j]==arr[j+1])
                    {
                        j++;
                        cj++;
                    }
                    while(k-1>j and arr[k]==arr[k-1])
                    {
                        k--;
                        ck++;
                    }
                    c+=cj*ck;
                    j++;
                    k--;
                }
                
                else if(sum<target) j++;
                else k--;
                
            }
        }
        return c;
          
    }
};

//{ Driver Code Starts.

vector<int> lineArray() {
    string line;
    getline(cin, line);
    stringstream ss(line);
    vector<int> arr;
    int num;
    while (ss >> num) {
        arr.push_back(num);
    }
    return arr;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr = lineArray();
        int target;
        cin >> target;
        cin.ignore();

        Solution ob;
        int res = ob.countTriplets(arr, target);
        cout << res << endl;
        cout << "~" << endl;
    }
}

/*
https://www.geeksforgeeks.org/batch/gfg-160-problems/track/two-pointer-technique-gfg-160/problem/count-all-triplets-with-given-sum-in-sorted-array
*/