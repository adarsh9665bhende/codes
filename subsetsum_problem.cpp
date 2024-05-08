//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool subsetsum(vector<int>arr, int sum,int n,vector<vector<int>>&dp){
        // base condition
        if(dp[n][sum]!=-1){return dp[n][sum];}
        if(arr[n-1]<=sum){
            return dp[n][sum]=subsetsum(arr,sum-arr[n-1],n-1,dp) || subsetsum(arr,sum,n-1,dp) ;
        }
        else{
            return dp[n][sum]= subsetsum(arr,sum,n-1,dp) ;
        }
    }
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        vector<vector<int>>dp(arr.size()+1,vector<int>(sum+1,-1));
        for(int i =0;i<=arr.size();i++){
            dp[i][0]=true;
        }
        for(int i =1;i<=sum;i++){
            dp[0][i]=false;
        }
        return subsetsum(arr,sum,arr.size(),dp);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends