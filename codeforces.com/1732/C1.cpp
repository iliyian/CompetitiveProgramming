// date: 2024-05-14 20:58:53
// tag: 位运算，二分

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n, q;
  cin >> n >> q;
  vector<int> a(n + 1), x(n + 1), s(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    x[i] = x[i - 1] ^ a[i];
    s[i] = s[i - 1] + a[i];
  }
  int L, R;
  cin >> L >> R;
  L = 1, R = n;
  auto check = [&](int l, int r) {
    return s[r] - s[l - 1] - (x[r] ^ x[l - 1]);
  };
  int mx = s[n] - x[n];
  int ansl = 1, ansr = n;
  for (int i = 1; i <= n; i++) {
    int l = i, r = n, cur = -1;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (check(i, mid) >= mx) r = mid - 1, cur = mid;
      else l = mid + 1;
    }
    if (check(i, cur) == mx) {
      if (ansr - ansl > cur - i) {
        ansr = cur, ansl = i;
      }
    }
  }
  cout << ansl << ' ' << ansr << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("C1.in", "r", stdin);
  freopen("C1.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}