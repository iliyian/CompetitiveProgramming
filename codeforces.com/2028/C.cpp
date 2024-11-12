// date: 2024-11-11 09:21:04
// tag: 

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n, m, v;
  std::cin >> n >> m >> v;
  std::vector<int> a(n + 2);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  int sum = 0;
  std::vector<int> l(n + 2), r(n + 2);
  for (int i = 1; i <= n; i++) {
    sum += a[i];
    if (sum >= v) {
      sum = 0;
      l[i] = l[i - 1] + 1;
    } else {
      l[i] = l[i - 1];
    }
  }
  sum = 0;
  for (int i = n; i >= 1; i--) {
    sum += a[i];
    if (sum >= v) {
      sum = 0;
      r[i] = r[i + 1] + 1;
    } else {
      r[i] = r[i + 1];
    }
  }
  for (int i = 1; i <= n; i++) {
    a[i] += a[i - 1];
    // std::cout << l[i] << ' ' << r[i] << '\n';
  }
  a[n + 1] = a[n];
  int ans = -1;
  for (int i = 1; i <= n; i++) {
    int s = i, t = n + 1, pos = -1;
    while (s <= t) {
      int mid = (s + t) / 2;
      if (l[i - 1] + r[mid] >= m) s = mid + 1, pos = mid;
      else t = mid - 1;
    }
    if (pos == -1) continue;
    ans = std::max(ans, a[pos - 1] - a[i - 1]);
  }
  std::cout << ans << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}