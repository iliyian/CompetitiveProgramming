#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, x, y, z;
  std::cin >> n >> x >> y >> z;
  std::vector<int> a(n), bucket(n + 1);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
    bucket[a[i]]++;
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (bucket[i]) {
      ans += x;
      bucket[i]--;
    }
  }
  std::vector<int> p(n + 1);
  std::iota(p.begin() + 1, p.end(), 1);
  std::sort(p.begin() + 1, p.end(), [&](auto x, auto y) {
    return bucket[x] < bucket[y];
  });
  int lim = (x == y ? LLONG_MAX / 3 : (x - z + x - y - 1) / (x - y)) - 1;
  int j = 0, k = 0;
  while (bucket[p[j]] == 0) j++;
  while (j + 1 <= n && bucket[p[j + 1]]) j++;
  k = j;
  j -= lim;
  j = std::max(j, 0ll);
  int pre = 0;
  for (int i = 1; i <= n; i++) {
    if (i <= j) {
      if (bucket[p[i]] > bucket[p[i - 1]]) {
        ans += (bucket[p[i]] - pre) * ((k - i + 1 - 1) * x + z);
        pre = bucket[p[i]];
      }
    } else {
      ans += (bucket[p[i]] - pre) * y;
    }
  }
  // if (j == 0ll) {
  //   ans += x - y;
  // } else {
  //   ans += x - z;
  // }
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