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
ll dist[maxn], par[maxn];
vector<ll> adj[maxn];
void bfs(ll uu) {
     dist[uu] = 0;
     queue<ll> q;
     par[uu] = -1;
     q.push(uu);
     while (!q.empty()) {
          ll u = q.front();
          q.pop();
          for (auto v : adj[u]) {
               if (dist[v] == INT_MAX) {
                    dist[v] = dist[u] + 1;
                    par[v] = u;
                    q.push(v);
               }
          }
     }
}
void solve() {
     cin >> n >> m;
     for (int i = 1; i <= n; ++i) {
          dist[i] = INT_MAX;
          par[i] = 0;
     }
     for (int i = 1; i <= m; ++i) {
          ll u, v;
          cin >> u >> v;
          adj[u].pb(v);
          adj[v].pb(u);
     }
     bfs(1);
     if (dist[n] == INT_MAX) {
          cout << "IMPOSSIBLE\n";
          return;
     }
     cout << dist[n] + 1 << "\n";
     vector<ll> path;
     while (1) {
          path.pb(n);
          n = par[n];
          if (n == -1) break;
     }
     reverse(path.begin(), path.end());
     for (auto x : path) cout << x << " ";
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
