#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5 + 10, MOD = 1e9 + 7;


vector <int> adj[N];
ll ans = 0, up[N][6], down[N][6];
string s; 

void dfs(int u, int p) {
  if (s[u] == '{') up[u][1] = 1;
  else down[u][1] = 1;

  for (auto v : adj[u]) {
    if (v == p) continue;
    dfs(v, u);
    for (int i = 0; i <= 5; ++i) {
      ans += up[u][i] * down[v][i];
      ans += up[v][i] * down[u][i];
    }
    if (s[u] == '{') {
      for (int i = 0; i < 5; ++i) up[u][i + 1] += up[v][i];
      for (int i = 1; i <= 5; ++i) down[u][i - 1] += down[v][i];
    } else {
      for (int i = 1; i <= 5; ++i) up[u][i - 1] += up[v][i];
      for (int i = 0; i < 5; ++i) down[u][i + 1] += down[v][i];
    }
  }
}

void solve() {
  int n; cin >> n;
  for (int i = 0; i < n; ++i) {
    adj[i].clear();
    for (int j = 0; j <= 5; ++j) up[i][j] = down[i][j] = 0;
  }
  ans = 0;
  cin >> s;
  for (int i = 0; i + 1 < n; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(0, -1);
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t = 1; 
  cin >> t;
  while (t--)
  solve();
}
