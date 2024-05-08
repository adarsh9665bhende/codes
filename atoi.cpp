//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string s) {
        //Your code here
        int res =0;
        bool neg =false;
        int i=0;
        if(s[0]=='-'){
            i++;
            neg =true;
        }
        for(;i<s.size();i++){
            if(s[i]-'0' >=0 && s[i]-'0'<=9){
                res = res*10 + (s[i]-'0');
            }
            else{
                return -1;
            }
        }
        return neg?-1*res:res;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		int ans=ob.atoi(s);
		cout<<ans<<endl;
	}
}
// } Driver Code Ends