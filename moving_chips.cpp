#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
#define vll vector<long long>
#define vvi vector<vector<int>>
#define vpii vector<pair<int,int>>
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define F first
#define S second
#define sz(x) ((int)(x).size())
#define endl '\n'

const int mod = 1e9 + 7;
const int INF = 1e9;
const ll LINF = 1e18;

void solve() {
    int n;
    cin>>n;
    int resource=n;
    vector<int>st(n,0);
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        st[i]=temp;
    }
    int left,right;
    for(int i=0;i<n;i++){
        if(st[i]==1){
            left = i;
            break;
        }
    }
    for(int i=n-1;i>=0;i--){
        if(st[i]==1){
            right = i;
            break;
        }
    }
    int count =0;
    for(int i=left+1;i<right;i++){
         if(st[i]==0){count++;}
    }
    cout<<count<<endl;
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
     cin >> t; // Uncomment for multiple test cases
    while (t--) {
        solve();
    }

    return 0;
}
