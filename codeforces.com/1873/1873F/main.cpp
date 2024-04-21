// it surprised me that no time_limit_exceeded.

#include <bits/stdc++.h>
using namespace std;

int a[200001], h[200001], sum[200001], n, k;

bool check(int len) {
  for (int l = 1; l <= n - len + 1; l++) {
    int r = l + len - 1;
    if (sum[r] - sum[l - 1] <= k) {
      bool f = true;
      for (int i = l; i < r; i++)
        if (h[i] % h[i + 1]) {
          f = false;
          break;
        }
      if (f)
        return true;
    }
  }
  return false;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  int T;
  cin >> T;
  while (T--) {
    cin >> n >> k;
    sum[0] = 0;
    for (int i = 1; i <= n; i++)
      cin >> a[i], sum[i] = sum[i - 1] + a[i];
    for (int i = 1; i <= n; i++)
      cin >> h[i];
    int l = 0, r = n, ans = 0;
    while (r >= l) {
      int mid = l + (r - l >> 1);
      if (check(mid)) l = mid + 1, ans = mid;
      else r = mid - 1;
    }
    cout << ans << '\n';
  }
  return 0;
}