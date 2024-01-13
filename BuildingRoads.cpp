#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
 
#include <bits/stdc++.h>
 
using namespace std;
 
#define fi first
#define se second
#define pb push_back
#define ll long long
#define ld long double
#define pi pair<ll, ll>
#define sz(a) (int)a.size()
#define all(a) a.begin(), a.end()
#define rep(i, a, b) for (int i = (int)a; i <= b; ++i)
#define rep2(i, a, b) for (int i = (int)a; i >= b; --i)
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
const int maxn = 1e5 + 5;
const ll mod = 1e9 + 7;
 
ll n, m;
bool vis[maxn];
vector<ll> adj[maxn], node;
 
void dfs(ll u) {
    vis[u] = true;
    for (auto v : adj[u]) {
        if (!vis[v]) {
            dfs(v);
        }
    }
}
 
void UocjAC() {
    cin >> n >> m;
    rep (i, 1, m) {
        ll u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    rep (i, 1, n) {
        if (!vis[i]) {
            dfs(i);
            node.pb(i);
        }
    }
    cout << sz(node) - 1 << "\n";
    rep (i, 0, sz(node) - 2) {
        cout << node[i] << " " << node[i + 1] << "\n";
    }
}
 
int main(){
    IOS
    // freopen(".inp","r",stdin);
    // freopen(".out","w",stdout);
    ll tc = 1; // cin >> tc;
    while(tc--) {
        UocjAC();
    }
    return 0;
}
