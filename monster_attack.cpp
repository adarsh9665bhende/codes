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
    int n,k;
    cin>>n>>k;
    vector<int>a(n,0);
    vector<int>x(n,0);
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        a[i]=temp;
    }
     for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        x[i]=temp;
    }
    
    
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
