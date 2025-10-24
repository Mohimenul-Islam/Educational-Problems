#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 4e5 + 5;
const ll INF = 4e18;

ll arr[N];

struct ST {
  #define lc (n << 1)
  #define rc ((n << 1) + 1)
  long long t[4 * N], lazy[4 * N];
  ST() {
    memset(t, 0, sizeof t);
    memset(lazy, 0, sizeof lazy);
  }
  inline void push(int n, int b, int e) { // change this
    if (lazy[n] == 0) return;
    t[n] = t[n] + lazy[n];
    if (b != e) {
      lazy[lc] = lazy[lc] + lazy[n];
      lazy[rc] = lazy[rc] + lazy[n];
    }
    lazy[n] = 0;
  }
  inline long long combine(long long a,long long b) { // change this
    return min(a, b);
  }
  inline void pull(int n) { // change this
    t[n] = min(t[lc], t[rc]);
  }
  void build(int n, int b, int e) {
    lazy[n] = 0; // change this
    if (b == e) {
      t[n] = arr[b];
      return;
    }
    int mid = (b + e) >> 1;
    build(lc, b, mid);
    build(rc, mid + 1, e);
    pull(n);
  }
  void upd(int n, int b, int e, int i, int j, long long v) {
    push(n, b, e);
    if (j < b || e < i) return;
    if (i <= b && e <= j) {
      lazy[n] = v; //set lazy
      push(n, b, e);
      return;
    }
    int mid = (b + e) >> 1;
    upd(lc, b, mid, i, j, v);
    upd(rc, mid + 1, e, i, j, v);
    pull(n);
  }

  long long query(int n, int b, int e, int i, int j) {
    push(n, b, e);
    if (i > e or j < b) return INF;
    if (b >= i and e <= j) return t[n];
    int mid = (b + e) >> 1;
    return combine(query(lc, b, mid, i, j), query(rc, mid + 1, e, i, j));
  }

  long long idx_query(int n, int b, int e, int i, int j, ll val) {
    push(n, b, e);
    if (i > e || b > j) return INF; //return inf
    if(b == e) return t[n] < val? b : INF;
    int mid = (b + e) >> 1;
    if (t[lc] + lazy[lc] < val) {
      ll ret = idx_query(lc, b, mid, i, j, val);
      if (ret != INF) return ret;
    }
    return idx_query(rc, mid + 1, e, i, j, val);
  }
}st;

void solve() {
  ll n, k; 
  cin >> n >> k;
  int m = n ;
  for (int i = 1; i <= n; ++i) {
    cin >> arr[i];
    arr[n + i] = arr[i];
  }
  n += n;
  for (int i = 1; i <= n; ++i) {
    arr[i] -= 1LL * (i - 1) * k;
  }
  st.build(1, 1, n);

  for (int i = 1; i <= m; ++i) {
    int lo = i + 1, hi = n;
    ll val = st.query(1, 1, n, i, i);
    ll res = st.idx_query(1, 1, n, i + 1, n, val);
    st.upd(1, 1, n, i + 1, n, k);
    cout << (res % m == 0? m : res % m) << " \n"[i == m];
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int tt = 1;
  // cin >> tt;
  while (tt--) {
    solve();
  }
}