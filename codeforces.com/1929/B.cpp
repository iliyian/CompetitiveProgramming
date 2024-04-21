#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;
  auto check = [&](const int &x) -> bool {
    if (x <= n * 2 - 2) {
      return x * 2 >= k;
    } else {
      return x * 2 + (n * 2 - x - 2) >= k;
    }
  };
  int l = 1, r = 2 * n, ans = -1;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (check(mid)) r = mid - 1, ans = mid;
    else l = mid + 1;
  }
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("B.in", "r", stdin);
  freopen("B.out", "w", stdout);

  int t;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}