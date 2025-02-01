//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
bool f(vector<vector<char>>& board,int i,int j,int k,string &word)
{
    int n=board.size();
    int m=board[0].size();
    if(k==word.size()) return true;
    if(i<0 or j<0 or i>=n or j>=m) return false;
    if(board[i][j]!=word[k]) return false;
   
   char ch=board[i][j];
   board[i][j]='#'; //mark it as vis 
   
    //traverse the all five directions
    bool found= f(board,i+1,j,k+1,word) ||
    f(board,i-1,j,k+1,word) ||
    f(board,i,j+1,k+1,word) || 
    f(board,i,j-1,k+1,word);
    
    board[i][j]=ch;
    return found;
}
    bool isWordExist(vector<vector<char>>& board, string word) {
        // Code here
        vector<pair<int,int>>indices;
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(board[i][j]==word[0])
                {
                    indices.push_back({i,j});
                }
            }
        }
        bool ans=false;
        for(auto i:indices)
        {
            ans=ans || f(board,i.first,i.second,0,word);
        }
        return ans;
        
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> mat(n, vector<char>(m, '*'));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> mat[i][j];
        string word;
        cin >> word;
        Solution obj;
        bool ans = obj.isWordExist(mat, word);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
/*https://www.geeksforgeeks.org/batch/gfg-160-problems/track/recursion-and-backtracking-gfg-160/problem/word-search*/