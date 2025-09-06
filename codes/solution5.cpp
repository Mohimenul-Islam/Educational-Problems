#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 10, MOD = 1e9 + 7;

void solve() {
  int n, p;
  cin >> n >> p;
  array<int, 3> arr[n];
  for (int i = 0; i < n; ++i) {
  	cin >> arr[i][0] >> arr[i][1];
  	arr[i][2] = arr[i][1] / p - (arr[i][0] - 1) / p;
  }
  long double ans = 0;
  for (int i = 0; i < n; ++i) {
  	int j = (i + 1 == n? 0 : i + 1);
  	int range = arr[i][1] - arr[i][0] + 1, range2 = arr[j][1] - arr[j][0] + 1;
  	int ndi = (range - arr[i][2]);
  	int ndj = (range2 - arr[j][2]);
  	ans += (long double)1 - ((1LL * ndi * ndj) / (long double)(1LL * range * range2));
  }
  cout << setprecision(10) << fixed << ans * 2 * 1000 << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t = 1; 
  // cin >> t;
  while (t--)
  solve();
}
