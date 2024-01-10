#include<bits/stdc++.h>
using namespace std;
// 登ってみる
#define fi first
#define inf 1e18
#define se second
#define int long long
#define pb push_back
#define isz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
 
const int N = 2e5 + 5;
const int mod = 1e9 + 7;
 
int n;
int dp[N][2];
vector<int> adj[N];
 
void dfs(int u, int p) {
          for (auto v : adj[u]) {
                    if (v == p) continue;
                    dfs(v, u);
                    dp[u][0] += max(dp[v][0], dp[v][1]);
          } // we have to complete dp[u][0] first
          for (auto v : adj[u]) {
                    if (v == p) continue;
                     dp[u][1] = max(dp[u][1], dp[v][0] + 1 + dp[u][0] - max(dp[v][0], dp[v][1]));
          }
}
 
void solve() {
          cin >> n;
          for (int i = 1; i < n; ++i) {
                    int u, v; cin >> u >> v;
                    adj[u].pb(v);
                    adj[v].pb(u);
          }
          dfs(1, 1);
          cout << max(dp[1][0], dp[1][1]);
}
 
int32_t main() {
          ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(0);
          // freopen(".inp", "r", stdin);
          // freopen(".out", "w", stdout);
          int tc = 1; // cin >> tc;
          for (int i = 1; i <= tc; ++i) solve();
          cerr << "\nTime elapsed: " << 1000.0 * clock() / CLOCKS_PER_SEC << " ms.\n";
          return 0;
}
