//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    //Function to check if a string is Pangram or not.
    bool checkPangram (string s) {
        // your code here
        if(s.size()<26){return false;}
        int arr[26];
        int ARR[26];
        memset(arr,0,sizeof(arr));
        memset(ARR,0,sizeof(arr));
        for(int i=0;i<s.size();i++){
            if(s[i]-'a'>=0 && s[i]-'a'<26){
                arr[s[i]-'a']++;
            }
            else if(s[i]-'A'>=0 && s[i]-'A'<26){
                ARR[s[i]-'A']++;
            }
        }
        for(int i=0;i<26;i++){
            if(arr[i]==0 && ARR[i]==0){
                return false;
            }
        }
        return true;
    }

};

//{ Driver Code Starts.

// Driver Program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--){
        string s;
        getline(cin, s);
        Solution obj;
        if (obj.checkPangram(s) == true)
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
    return(0);
}

// } Driver Code Ends