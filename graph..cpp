// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
#include <bits/stdc++.h>
#include<algorithm>
#include <vector>


void addEdge(vector<int>adj[],int u,int v){
   adj[u].push_back(v);
   adj[v].push_back(u);
}
void printGraph(vector<int>adj[],int v){
    for(int i =0;i<v;i++){
        for(auto x : adj[i]){
            cout<<i<<"->"<<x<<"  ";
        }
        cout<<endl;
    }
}
void BSF(vector<int>adj[],int v,int s){
    vector<bool>visited(v+1,false);
    queue<int>q;
    visited[s] = true;
    q.push(s);
    cout<<"BSF:";
    while(!q.empty()){
        int u = q.front();
        cout<<u<<" ";
        q.pop();
        for(auto x:adj[u]){
            if(visited[x]==false){
                visited[x]=true;
                q.push(x);
            }
        }
    }
    
}

void DFS_Rec(vector<int>adj[],int sourse,vector<bool>&visited){
    visited[sourse]=true;
    cout<<sourse<<" ";
    for(int x:adj[sourse]){
        if(visited[x]==false){
            DFS_Rec(adj,x,visited);
        }
    }
}
void DFS(vector<int>adj[],int sourse,int v){
    cout<<"DSF:";
    vector<bool>visited(v+1,false);
    // this part is for DFs from sourse only
     if(visited[sourse]==false){
            DFS_Rec(adj,sourse,visited);
        }
        // this for all nodes DFS
    // for(int i =0;i<v;i++){
    //     if(visited[i]==false){
    //         DFS_Rec(adj,i,visited);
    //     }
    // }
}
bool Detect_Cycle_Rec(vector<int>adj[],int source,vector<bool>&visited,int parent){
    visited[source]=true;
    for(auto x:adj[source]){
        if(visited[x]==false){
            Detect_Cycle_Rec(adj,x,visited,source);
        }
        else if( x!= parent){
            cout<<endl;
            cout<< "Cycle Detected at edge:"<<parent<<endl;
            return true;
        }
       
    }
    return false;

}
bool Detect_Cycle(vector<int>adj[],int v){
    cout<< "Detecting cycle ...."<<endl;
    vector<bool>visited(v,false);
    
    for(int i = 0;i<v;i++){
     if(visited[i]==false){
        if(Detect_Cycle_Rec(adj,i,visited,-1)){
            return true;
        }
     }
    }
    return false;
}
// topological sort
vector<int> topoSort(int V, vector<int> adj[]) 
	{   
	    int start = -1;
	    vector<int>ans;
	    queue<int>q;
	    vector<int>indegree(V,0);
	    
	    for(int i =0;i<V;i++){
	       // vector<int>data = adj[i];
	        for(auto x:adj[i]){
	            indegree[x]++;
	        }
	    }
	    
	    for(int i =0 ;i<V;++i){
	        if(indegree[i]==0){
	            start = i;
	            q.push(start);
	            
	        }
	    }
	    
	    if (start == -1) {
            cout << "Graph contains a cycle or has disconnected components." << endl;
            return {};
        }
	    
	    while(!q.empty()){
	        int u = q.front();
	        ans.push_back(u);
	        q.pop();
	       
	        
	        for(auto v:adj[u]){
	            indegree[v]--;
	            if(indegree[v]==0){
	                q.push(v);
	            }
	        }
	    }
	   
	    return ans;
	}

int main(){
    int v = 6;
 
    
    vector<int> adj[v];

    // addEdge(adj,0,1);
    // addEdge(adj,0,2);
    // addEdge(adj,0,5);
    // addEdge(adj,1,3);
    // addEdge(adj,2,4);
    // addEdge(adj,3,5);
    // addEdge(adj,4,5);


    // addEdge(adj,4,5);
    // addEdge(adj,0,1);
    // addEdge(adj,1,2);
    // addEdge(adj,2,3);
    // addEdge(adj,0,4);
    
    // addEdge(adj,4,6);

    // addEdge(adj,0,1);                         0----1                    5
    // addEdge(adj,0,2);                         -     -  -                |
    // addEdge(adj,2,3);                         -     -     -  4          6
    // addEdge(adj,1,3);                         -     -  -                |
    // addEdge(adj,1,4);                         2----3                    7
    // addEdge(adj,4,3);
    // addEdge(adj,5,6);
    // addEdge(adj,7,6);

    addEdge(adj,0,1);
    addEdge(adj,0,2);
    addEdge(adj,2,1);                                    //
    addEdge(adj,3,1);                                    //
    addEdge(adj,3,4);                                    //    0 -----1-----3------4
    addEdge(adj,3,5);                                    //    |    /         \    |
    addEdge(adj,4,5);                                    //    |  /             \  |
                                                         //    2                   5
                                                         //

    printGraph(adj,v);
    BSF(adj,v,0);
    cout<<"calling DSF"<<endl;
    DFS(adj,2,3);
    cout<<endl;
    Detect_Cycle(adj,6);

    return 0;
}