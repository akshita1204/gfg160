//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    string decodedString(string &s) {
        // code here
           stack<char>st;
        string str="";
        string count="";
        for(int i=0;i<s.length();i++)
        {
            if(s[i]==']')
            {
                while(st.top()!='[')
                {
                    str=st.top()+str;
                    st.pop();
                }
                st.pop(); //'[' pop this char

                //characters calculations
                while(!st.empty() and isdigit(st.top()))
                {
                    count=st.top()+count;
                    st.pop();
                }
                //convert the count to integer
                int c=stoi(count);
                while(c--)
                {
                    for(char it:str)
                    {
                        st.push(it);
                    }
                }
                str="";
                count="";
            }
            else st.push(s[i]);
        }
        string ans="";
        while(!st.empty())
        {
            ans=st.top()+ans;
            st.pop();
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution ob;
        cout << ob.decodedString(s) << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
/*https://www.geeksforgeeks.org/problems/decode-the-string2444/1*/