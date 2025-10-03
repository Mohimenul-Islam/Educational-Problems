#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 10, MOD = 1e9 + 7;

vector <int> adj[N], path, dis, par;
int l, r;

void dfs(int u, int p) {
  par[u] = p;
  for (auto v : adj[u]) {
    if (v == p) continue;
    dis[v] = 1 + dis[u];
    dfs(v, u);
  }
}

void solve() {
  int n; cin >> n;
  path.clear();
  for (int i = 0; i < n; ++i) adj[i].clear();
  int deg[n]{};
  for (int i = 0; i + 1 < n; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    adj[u].push_back(v);
    adj[v].push_back(u);
    ++deg[u], ++deg[v];
  }
  if (n <= 3) {
    cout << -1 << '\n';
    return;
  }
  dis.assign(n, 0);
  par.assign(n, -1);
  dfs(0, -1);
  int mx = -1;
  for (int i = 0; i < n; ++i)  {
    if (dis[i] > mx) {
      mx = dis[i], l = i;
    }
  }
  dis.assign(n, 0);
  par.assign(n, -1);
  dfs(l, -1);
  mx = -1;
  for (int i = 0; i < n; ++i)  {
    if (dis[i] > mx) {
      mx = dis[i], r = i;
    }
  }
  int curr = r;
  while (curr != -1) {
    path.push_back(curr);
    curr = par[curr];
  }

  int onDiameter[n]{};
  for (auto i : path) {
    onDiameter[i] = true;
  }
  for (int i = 1; i < path.size(); ++i) {
    for (auto v : adj[path[i]]) {
      if (!onDiameter[v]) {
        cout << path[i - 1] + 1 << ' ' << path[i] + 1 << ' ' << v + 1 << '\n';
        return;
      }
    }
  }
  cout << -1 << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t = 1; 
  cin >> t;
  while (t--)
  solve();
}
