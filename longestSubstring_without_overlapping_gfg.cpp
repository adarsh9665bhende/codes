//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    string longestSubstring(string s, int n) {
        // code here
        string res;
        int res_length=0;
        int index =0;
        int DP[n+1][n+1];
        memset(DP,0,sizeof(DP));
        
        for(int i =1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(s[i-1]==s[j-1] && DP[i-1][j-1]<j-i){
                    DP[i][j]=DP[i-1][j-1]+1;
                    
                    if(DP[i][j]>res_length){
                        res_length = DP[i][j];
                        index = max(i,index);
                    }
                }
                else{
                    DP[i][j]=0;
                }
            }
        }
        if(res_length>0){
            return s.substr(index-res_length,res_length);
        }
        return "-1";
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        string S;

        cin >> N;
        cin >> S;

        Solution ob;
        cout << ob.longestSubstring(S, N) << endl;
    }
    return 0;
}
// } Driver Code Ends