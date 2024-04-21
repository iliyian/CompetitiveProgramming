// date: 2024/02/19 21:26:28
// tag: 经典的必要条件即充分条件，可以先想必要条件

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1);
  int sum = 0, mx = 0;;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    sum += a[i];
    mx = max(mx, a[i]);
  }
  if (mx >= 2 * (sum - mx)) {
    cout << sum - mx << '\n';
  } else {
    // 三个点一个三角形的上限
    cout << sum / 3 << '\n';
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("M.in", "r", stdin);
  freopen("M.out", "w", stdout);

  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}