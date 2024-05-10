// date: 2024-05-09 13:00:43
// tag: 二分

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n, q;
  cin >> n >> q;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  auto check = [&](int mid) {
    int cur = q, cnt = 0;
    for (int i = mid + 1; i <= n; i++) {
      cur -= cur < a[i];
      if (!cur && i < n) {
        return false;
      }
    }
    return cur >= 0;
  };
  int l = 0, r = n, ans = 0;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (check(mid)) r = mid - 1, ans = mid;
    else l = mid + 1;
  }
  for (int i = 1; i <= n; i++) {
    if (i <= ans) {
      cout << (int)(a[i] <= q);
    } else {
      cout << 1;
    }
  }
  cout << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("A.in", "r", stdin);
  freopen("A.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}