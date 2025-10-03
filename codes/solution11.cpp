#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 10, MOD = 1e9 + 7;

void solve() {
  int n, q;
  cin >> n >> q;
  int arr[n], movesNeed[n], pSum[n + 1]{}, pSum2[n + 1]{};
  
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
    movesNeed[i] = __lg(arr[i]);
    pSum2[i + 1] = pSum2[i];

    int x = __lg(arr[i]);
    if ((1 << x) + 1 == arr[i]) {
      ++pSum2[i + 1];
    } else if (__builtin_popcount(arr[i]) != 1) ++movesNeed[i];
  }
  for (int i = 0; i < n; ++i) {
    pSum[i + 1] = pSum[i] + movesNeed[i];
  }
  while(q--) {
    int l, r;
    cin >> l >> r;
    cout << pSum[r] - pSum[l - 1] + (pSum2[r] - pSum2[l - 1]) / 2 << '\n';
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t = 1; 
  cin >> t;
  while (t--)
  solve();
}
