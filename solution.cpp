#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 10, MOD = 1e9 + 7;

struct P {
	ll x, y;
	void read() {
		cin >> x >> y;
	}
	P operator -(const P& b) const {
		return P{x - b.x, y - b.y};
	}
	void operator -=(const P& b) {
		x -= b.x;
		y -= b.y;
	}
	ll operator *(const P& b) const {
		return 1LL * x * b.y - 1LL * y * b.x;
	}
	ll triangle (const P& a, P& b) {
		return (a - *this) * (b - *this);
	}
};

bool contains_segemnt(P p1, P p2, P p3) {
	if (p1.triangle(p2, p3) != 0) return false;
	return min(p2.x, p3.x) <= p1.x and p1.x <= max(p2.x, p3.x) 
	  and min(p2.y, p3.y) <= p1.y and p1.y <= max(p2.y, p3.y);
}

bool is_intesect(P p1, P p2, P p3, P p4) {
	if ((p2 - p1) * (p3 - p4) == 0) {
		if (p1.triangle(p2, p3) != 0) return false;
		bool fl = false;
		int mnx = min(p1.x, p2.x), mxx = max(p1.x, p2.x), mny = min(p1.y, p2.y), mxy = max(p1.y, p2.y);
		int mnx2 = min(p3.x, p4.x), mxx2 = max(p3.x, p4.x), mny2 = min(p3.y, p4.y), mxy2 = max(p3.y, p4.y);
		return (max(mnx, mnx2) <= min(mxx, mxx2) && max(mny, mny2) <= min(mxy, mxy2));
	}

	ll sign1 = p1.triangle(p2, p3), sign2 = p1.triangle(p2, p4);
	if ((sign1 < 0 and sign2 < 0) or (sign1 > 0 and sign2 > 0)) return false;
	sign1 = p4.triangle(p3, p1), sign2 = p4.triangle(p3, p2);
	if ((sign1 < 0 and sign2 < 0) or (sign1 > 0 and sign2 > 0)) return false;
	return true;
}

void solve() {
	int n, q;
	cin >> n >> q;
	P arr[n];
	for (int i = 0; i < n; ++i) arr[i].read();
	while (q--) {
		P point, out;
		point.read();
		out = {point.x + 1, 3000000001};
		int cnt = 0;
		bool fl = false;
		for (int i = 0; i < n; ++i) {
			int j = (i + 1 == n? 0 : i + 1);
			if (contains_segemnt(point, arr[i], arr[j])) {
				fl = true;
				break;
			}
			cnt += is_intesect(point, out, arr[i], arr[j]);
		}
		if (fl) {
			cout << "BOUNDARY\n";
		} else if (cnt & 1) {
			cout << "INSIDE\n";
		} else cout << "OUTSIDE\n";
	}
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t = 1; 
  // cin >> t;
  while (t--)
  solve();
}
