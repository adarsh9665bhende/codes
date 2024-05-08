//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	bool sameFreq(string s)
	{
	    // code here 
	    int mp[26];
	    memset(mp,0,sizeof(mp));
	    
	    for(char ch:s){
	        mp[ch-'a']++;
	    }
	    vector<int>res;
	    for(int i=0;i<26;i++){
	        if(mp[i]!=0){
	            res.push_back(mp[i]);
	        }
	    }
	    int maxFreq =0;
	    int minFreq =INT_MAX;
	    
	    for(int i=0;i<res.size();i++){
	        maxFreq = max(maxFreq,res[i]);
	        minFreq = min(minFreq,res[i]);
	    }
	    if(maxFreq==minFreq){return true;}
	    
	    else if(maxFreq-minFreq==1){
	        int countmaxFreq =0;
	        int countminFreq =0;
	        
	        for(int i=0;i<res.size();i++){
	            if(res[i]==maxFreq){countmaxFreq++;}
	            else if(res[i]==minFreq){countminFreq++;}
	        }
	        return (countmaxFreq ==1 || countminFreq==1);
	        
	    }
       return false;
	}
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.sameFreq(s)<<endl;
    }
}



// } Driver Code Ends