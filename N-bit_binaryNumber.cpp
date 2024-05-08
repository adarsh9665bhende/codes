//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
    vector<string>res;
    
    void solve(string nbit,int ones,int zeros,int n){
        if(nbit.size()==n){
            res.push_back(nbit);
            return;;
        }
        solve(nbit+"1",ones+1,zeros,n);
        if(ones>zeros){
            solve(nbit+"0",ones,zeros+1,n);
            return;
        }
    }
	vector<string> NBitBinary(int n)
	{
	    // Your code goes here
	    // recursive solution
	    string nbit ="";
	    solve(nbit,0,0,n);
	    return res;
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		int n;
   		cin >> n;
        Solution ob;
   		vector<string> ans = ob.NBitBinary(n);

   		for(auto i:ans)
   			cout << i << " ";

   		cout << "\n";
   	}

    return 0;
}
// } Driver Code Ends