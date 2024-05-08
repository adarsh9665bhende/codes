//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
        int Sum(int n,vector<int>&dp){
            if(n==0){return 0;}
            if(dp[n]!=-1){return dp[n];}
            
            return dp[n]=max(n,Sum(n/2,dp)+Sum(n/3,dp)+Sum(n/4,dp));
        }
        int maxSum(int n)
        {
            //code here.
            vector<int>dp(n+1,-1);
            return Sum(n,dp);
        }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        Solution ob;
        cout<<ob.maxSum(n)<<"\n";
    }
    return 0;
}
// } Driver Code Ends