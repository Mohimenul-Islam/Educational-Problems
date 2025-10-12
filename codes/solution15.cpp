#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 10, MOD = 1e9 + 7;

void solve() {
  string s, t;
  cin >> s >> t;
  int n = s.size(), m = t.size();
  int pi[n]{};

  for (int i = 1, j = 0; i < m; ++i) {
    while (j > 0 and t[i] != t[j]) {
      j = pi[j - 1];
    }
    if (t[i] == t[j]) ++j;
    pi[i] = j;
  }
  int ans = 0;
  for (int i = 0, j = 0; i < n; ++i) {
    while(j > 0 and s[i] != t[j]) {
      j = pi[j - 1];
    }
    if (s[i] == t[j]) ++j;
    if (j == m) {
      ++ans;
      j = pi[j - 1];
    }
  }
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
