#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 3e5 + 9;

int a[N];
struct ST {
  int t[4 * N];
  static const int inf = 1e9;
  ST() {
    memset(t, 0, sizeof t);
  }
  void upd(int n, int b, int e, int i, int x) {
    if (b > i || e < i) return;
    if (b == e && b == i) {
      t[n] = x;
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l | 1;
    upd(l, b, mid, i, x);
    upd(r, mid + 1, e, i, x);
    t[n] = t[l] + t[r];
  }
  int query(int n, int b, int e, int i, int j) {
    if (b > j || e < i) return 0;
    if (b >= i && e <= j) return t[n];
    int mid = (b + e) >> 1, l = n << 1, r = l | 1;
    int L = query(l, b, mid, i, j);
    int R = query(r, mid + 1, e, i, j);
    return L + R;
  }
};

void solve() {
  int n; cin >> n;
  int a[n];
  vector <int> even, odd;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    if (i & 1) even.push_back(a[i]);
    else odd.push_back(a[i]);
  }
  
  auto invCnt = [&](vector <int> &v) {
    int ret = 0;
    ST t;
    for (auto i : v) {
      ret += t.query(1, 1, n, i + 1, n);
      t.upd(1, 1, n, i, 1);
    }
    return ret & 1;
  };
  int invEven = invCnt(even);
  int invOdd = invCnt(odd);
  sort(even.begin(), even.end());
  sort(odd.begin(), odd.end());
  // cout << invEven << ' '<< invOdd << '\n';
  int ans[n];
  for (int i = 0; i < n / 2; ++i) {
    ans[i * 2] = odd[i], ans[i * 2 + 1] = even[i];
  }
  if (n & 1) ans[n - 1] = odd.back();
  if (invEven != invOdd) swap(ans[n - 1], ans[n - 3]);
  for (int i = 0; i < n; ++i) cout << ans[i] << " \n"[i == n- 1];
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int tt = 1; 
  cin >> tt; 
  while (tt--) {
    solve();
  }
}