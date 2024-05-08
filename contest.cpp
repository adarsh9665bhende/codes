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
    int n,m;
    cin >> n >> m;
    if(n%2==0 &&(n/2)!=m || m%2==0 && (m/2)!=n){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
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
