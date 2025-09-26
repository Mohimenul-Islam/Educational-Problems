#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 10, MOD = 1e9 + 7;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
  int n, q; 
  cin >> n >> q;
  int arr[n], arr2[n];
  vector <int> vec;
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
    arr2[i] = arr[i];
    vec.push_back(arr[i]);
  }
  sort(vec.begin(), vec.end());
  vec.erase(unique(vec.begin(), vec.end()), vec.end());
  for (int i = 0; i < n; ++i) {
    arr[i] = lower_bound(vec.begin(), vec.end(), arr[i]) - vec.begin();
  }
  vector <int> idx[n];
  for (int i = 0; i < n; ++i) {
    idx[arr[i]].push_back(i);
  }

  int vis[n]{};
  while (q--) {
    int l, r;
    cin >> l >> r;
    --l, --r;
    int len = r - l + 1, rem = len;
    vector <int> ans;
    int cnt = 70;
    vector<int>clear;
    while (cnt and rem > len / 3) {
      int id = uniform_int_distribution<ll>(l, r)(rng);
      int val = arr[id], val2 = arr2[id];
      --cnt;
      if (vis[val]) continue;
      clear.push_back(val);
      int fre = upper_bound(idx[val].begin(), idx[val].end(), r) - lower_bound(idx[val].begin(), idx[val].end(), l);
      vis[val] = true;
      if (fre > len / 3) ans.push_back(val2);
      rem -= fre;
    }
    for (auto i : clear) vis[i] = false; 
    if (ans.empty()) {
      cout << "-1\n";
      continue;
    }
    if (ans.size() == 2) {
      if (ans[0] > ans[1]) swap(ans[0], ans[1]);
    }
    for (auto i : ans) cout << i << ' ';
    cout << '\n';
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
