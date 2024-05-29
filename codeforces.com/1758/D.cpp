// date: 2024-05-29 21:44:25
// tag: 二分，构造

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  cin >> n;
  int l = 0, r = ((int)1e9) - 2 * n - 1, sigma = n * n * 4;

  auto calc = [&](int mid) {
    int sum = (n + 2 * mid) * (n - 1) / 2 + 2 * n + 1 + mid;
    return sum;
  };

  while (l <= r) {
    int mid = (l + r) / 2;
    int sum = calc(mid);
    if (sum < sigma) {
      l = mid + 1;
    } else if (sum > sigma) {
      r = mid - 1;
    } else {
      for (int i = 1; i <= n - 1; i++) {
        cout << i + mid << ' ';
      }
      cout << 2 * n + 1 + mid << '\n';
      return;
    }
  }
  // l > r
  assert(calc(r) < sigma);
  int diff = sigma - calc(r);
  for (int i = 1; i <= n - 2; i++) {
    cout << i + r << ' ';
  }
  cout << n - 1 + r + diff << ' ' << 1 + r + n * 2 << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("D.in", "r", stdin);
  freopen("D.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}