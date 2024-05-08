//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    
    // Function to detect cycle in a directed graph.
    bool DFS(int i , vector<bool>&visited,vector<bool>&currVisited,vector<int> adj[]){
        visited[i]=true;
        currVisited[i] = true;
        
        for(auto x:adj[i]){
            if(!visited[x]){
                if( DFS(x,visited,currVisited,adj)){return true;}
            }
            else if(visited[x]==true && currVisited[x]==true){
                return true;
            }
            
        }
        currVisited[i] = false;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<bool>visited(V,false);
        vector<bool>currVisited(V,false);
        
        for(int i = 0;i<V;++i){
            if(visited[i]==false){
                if(DFS(i,visited,currVisited,adj)){return true;}
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends