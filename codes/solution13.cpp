#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 5e4 + 10, MOD = 1e9 + 7, K = 505;

int n, k, dp[N][K];
vector <int> adj[N];
ll ans = 0;

void dfs(int u, int p) {
  dp[u][0] = 1;
  for (auto v : adj[u]) {
    if (v == p) continue;
    dfs(v, u);
    for (int d = 0; d < k; ++d) {
      int req = k - d - 1;
      ans += 1LL * dp[v][d] * dp[u][req];
    }
    for (int d = 0; d < k; ++d) {
      dp[u][d + 1] += dp[v][d];
    }
  }
}

void solve() {
  cin >> n >> k;
  for (int i = 0; i + 1 < n; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(0, 0);
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t = 1; 
  // cin >> t;
  while (t--)
  solve();
}
