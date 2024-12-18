// date: 2024-12-18 16:52:29
// tag: 少见的O(n^8)的爆搜题，也即C(30,8)
// 这种小数据范围是真的不得不想想爆搜

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<double> v(n + 1);
  std::vector<int> s(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> v[i];
  }
  for (int i = 1; i <= n; i++) {
    std::cin >> s[i];
  }
  double bia[] = {8, 9, 10.5, 12};
  std::vector<int> vec(n + 1);
  std::iota(vec.begin(), vec.end(), 0);
  std::sort(vec.begin() + 1, vec.end(), [&](const int &x, const int &y) {
    return v[x] < v[y];
  });
  double ans = INT_MAX;
  for (int a = 1; a <= n; a++) {
    for (int b = a + 1; b <= n; b++) {
      for (int c = b + 1; c <= n; c++) {
        for (int d = c + 1; d <= n; d++) {
          for (int e = d + 1; e <= n; e++) {
            for (int f = e + 1; f <= n; f++) {
              for (int g = f + 1; g <= n; g++) {
                for (int h = g + 1; h <= n; h++) {
    std::array<int, 8> p = {vec[a], vec[b], vec[c], vec[d], vec[e], vec[f], vec[g], vec[h]};
    int cnt = 0;
    double dif = 0;
    bool f = true;
    for (int i = 0; i < 8; i += 2) {
      cnt += s[p[i]] == 1;
      cnt += s[p[i + 1]] == 1;
      if (v[p[i]] + 4 < v[p[i + 1]]) {
        f = false;
      }
      if (v[p[i]] > bia[i / 2] || v[p[i + 1]] > bia[i / 2]) {
        f = false;
      }
      dif += bia[i / 2] * 2 - v[p[i]] - v[p[i + 1]];
    }
    if (cnt < 2) f = false;
    if (f) {
      ans = std::min(ans, dif);
    }
                }
              }
            }
          }
        }
      }
    }
  }
  if (ans == INT_MAX) {
    std::cout << -1 << '\n';
    return;
  }
  std::cout << std::fixed << std::setprecision(2) << ans << '\n';
}

signed main() {
#ifndef ONLINE_JUDGE
	freopen("C.in", "r", stdin);
#endif
	std::cin.tie(0)->sync_with_stdio(false);
	int t = 1;
//	std::cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
