#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 10, MOD = 1e9 + 7;

ll h, d;
ll nSum(ll n) {
  return (n * (n + 1)) / 2;
}

bool f(ll rests) {
  ll partitions = (rests + 1);
  ll sz = d / partitions, sz2 = d % partitions;
  ll x = partitions - sz2, y = sz2;
  ll reqHealth = x * (nSum(sz) - 1) + y * (nSum(sz + 1) - 1);
  return reqHealth + 1 < h;
}

void solve() {
  cin >> h >> d;
  ll lo = 0, hi = d, ans = -1;

  while (lo <= hi) {
    ll mid = (lo + hi) >> 1;
    if (f(mid)) {
      hi = mid - 1;
      ans = mid;
    } else lo = mid + 1;
  }
  cout << ans + d << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t = 1; 
  cin >> t;
  while (t--)
  solve();
}
