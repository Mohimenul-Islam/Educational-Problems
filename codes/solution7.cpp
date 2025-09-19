#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e3 + 10, MOD = 1e9 + 7;

int n, t, vis[N][N];
long double dp[N][N], p;

long double f(int i, int time) {
  if (time == 0 or i == 0) return (long double)(n - i);
  long double &ret = dp[i][time];
  if (vis[i][time]) return ret;
  vis[i][time] = true;
  ret = f(i - 1, time - 1) * p + (1.0 - p) * f(i, time - 1);
  return ret;
}

void solve() {
  cin >> n >> p >> t;
  cout << fixed << setprecision(9) << f(n, t) << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t = 1; 
  // cin >> t;
  while (t--)
  solve();
}
