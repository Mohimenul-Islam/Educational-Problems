#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n; cin >> n;
  array<int, 3> arr[n + n];
  for (int i = 0; i < n + n; ++i) {
    cin >> arr[i][0] >> arr[i][1];
    arr[i][2] = (i >= n);
  }
  sort(arr, arr + n + n);
  set <int, greater<int>> se;
  int ans = 0;
  for (auto [x, y, color] : arr) {
    if (!color) se.insert(y);
    else {
      if (se.empty()) continue;
      auto it = prev(se.end());
      if (*it > y) continue;
      it = se.lower_bound(y);
      se.erase(it);
      ++ans;
    }
  }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();
}