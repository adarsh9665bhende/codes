//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    bool isValid(vector<vector<bool>>&visited,int i,int j,int n){
        return i>=0 && i<n && j>=0 && j<n && !visited[i][j];
    }
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    // Code here
	    int n =N;
	    int tx = TargetPos[0] -1,kx = KnightPos[0]-1;
	    int ty = TargetPos[1] -1,ky = KnightPos[1]-1;
	    int ans =0;
	    
	    vector<vector<bool>>visited(n,vector<bool>(n,false));
	    if(tx==kx && ty==ky){return ans;}
	    
	    queue<pair<int,int>>q;
	    q.push({kx,ky});
	    visited[kx][ky]=true;
	    while(!q.empty()){
	        int size = q.size();
	        ans++;
	        while(size!=0){
	            pair<int,int>p = q.front();
	            q.pop();
	            
	            int rows[8]={1,1,2,2,-1,-1,-2,-2};
	            int cols[8]={-2,2,-1,1,-2,2,-1,1};
	            for(int i=0;i<8;i++){
	                int row = p.first +rows[i];
	                int col = p.second + cols[i];
	                if(row==tx && col==ty){return ans;}
	                if(isValid(visited,row,col,n)){
	                    visited[row][col]=true;
	                    q.push({row,col});
	                }
	                
	            }
	            size--;
	        }
	    }
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends