//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int longestUniqueSubsttr(string S){
        //code
        unordered_map<char,int>mp;
        int ans =0;
        int count =0;
        int j=0;
        for(int i=0;i<S.size();i++){
            
            if(mp.find(S[i])!=mp.end()){
                while(mp[S[i]]>0){
                    mp[S[j]]--;
                    if(mp[S[j]]==0){mp.erase(S[j]);}
                    j++;
                }
               
            }
            mp[S[i]]++;
            count = i-j+1;
            ans = max(count,ans);
            
        }
        return ans;
        
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string str;
		cin>>str;
		Solution ob;
		cout<<ob.longestUniqueSubsttr(str)<<endl;
	}
	return 0;
}
// } Driver Code Ends