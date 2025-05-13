#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 8e3 + 10;

vector <int> vx, vy;
string s;
int n, sz, sz2, x, y;
bool dp[N][N + N], dp2[N][N + N], vis[N][N + N], vis2[N][N + N];

bool f(int i, int sum) {
  if (i == sz) return (sum == N + x);
  bool &ret = dp[i][sum];
  if (vis[i][sum]) return ret;
  vis[i][sum] = true;
  if (!i and s[0] == 'F') ret = f(i + 1, sum + vx[i]);
  else ret = (f(i + 1, sum + vx[i]) or f(i + 1, sum - vx[i]));
  return ret;
}

bool f2(int i, int sum) {
  if (i == sz2) return (sum == N + y);
  bool &ret = dp2[i][sum];
  if (vis2[i][sum]) return ret;
  vis2[i][sum] = true;
  ret = (f2(i + 1, sum + vy[i]) or f2(i + 1, sum - vy[i]));
  return ret;
}

void solve() {
  cin >> s;
  n = s.size();
  cin >> x >> y;

  int len = 0, fl = 1;
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'F') ++len;
    if (s[i] == 'T' or i == n - 1) {
      if (fl) vx.push_back(len);
      else vy.push_back(len);
      fl ^= 1;
      len = 0;
    }
  }
  sz = vx.size(), sz2 = vy.size();
  bool fl2 = (f(0, N) and f2(0, N));
  cout << (fl2? "Yes\n" : "No\n");
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int tt = 1; 
  //cin >> tt; 
  while (tt--) {
    solve();
  }
}