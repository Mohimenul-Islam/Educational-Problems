#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 10, MOD = 1e9 + 7;

void solve() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  //P = (Ps * 1) + (1 - Ps) * (Pm * 0) * ((1 - Pm) * P)
  //=> P = Ps / (1 - (1 - Ps) * (1 - Pm))
  long double Ps = a / (long double)b;
  long double Pm = c / (long double)d;
  cout << fixed << setprecision(10) << Ps / (1 - (1 - Ps) * (1 - Pm)) << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t = 1; 
  // cin >> t;
  while (t--)
  solve();
}
