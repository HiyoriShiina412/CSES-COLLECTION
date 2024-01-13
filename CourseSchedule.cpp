#include <bits/stdc++.h>
using namespace std;
// 私の名前はバッハです！
#define fi first
#define se second
#define pb push_back
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(NULL)
const int maxn = 2e5 + 5;
const int mod = 1e9 + 7;
ll n, m;
ll vis[maxn];
vector<ll> adj[maxn], topo;
bool toposort(ll u) {
     vis[u] = 1;
     for (auto v : adj[u]) {
          if (vis[v] == 1) return false;
          if (!vis[v]) {
               if (!toposort(v)) return false;
          }
     }
     vis[u] = 2;
     topo.pb(u);
     return true;
}
void solve() {
     cin >> n >> m;
     for (int i = 1; i <= m; ++i) {
          ll u, v;
          cin >> u >> v;
          adj[u].pb(v);
     }
     for (int i = 1; i <= n; ++i) {
          if (!vis[i]) {
               if (!toposort(i)) {
                    cout << "IMPOSSIBLE\n";
                    return;
               }
          }
     }
     reverse(topo.begin(), topo.end());
     for (auto x : topo) cout << x << " ";
}
int main() {
     IOS;
     // freopen("KUMAR.inp", "r", stdin);
     // freopen("KUMAR.out", "w", stdout);
     ll tc = 1; 
     // cin >> tc;
     while (tc--) {
               solve();
     }
}
