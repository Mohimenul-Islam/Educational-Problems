#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 10, MOD = 1e9 + 7;
vector <int> divs[N];

void prec() {
  for (int i = 1; i < N; ++i) {
    for (int j = i; j < N; j += i) divs[j].push_back(i);
  }
}

void solve() {
  int n; cin >> n;
  int arr[n], fre[n + 1]{}, vis[n + 1]{};

  vector<int> maxs;
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
    int x = arr[i];
    vector <int> next;
    for (auto d : divs[x]) {
      ++fre[d];
      if (fre[d] != i + 1) {
        ans = max(ans, fre[d]);
      } else if (!vis[d]) {
        next.push_back(d);
        vis[d] = true;
      }
    }
    for (auto d : maxs) {
      if (fre[d] != i + 1) {
        ans = max(ans, fre[d]);
        vis[d] = false;
      } else next.push_back(d);
    }
    next.swap(maxs);
    cout << ans << " \n"[i == n - 1];
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  prec();
  int t = 1; 
  cin >> t;
  while (t--)
  solve();
}
