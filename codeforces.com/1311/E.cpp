// date: 2024-08-03 10:46:47
// tag: 构造，树

#include <bits/stdc++.h>
#define int long long
// using namespace std;

void solve() {
  int n, k;
  std::cin >> n >> k;
  int mn = 0;
  std::vector<int> p(n + 1);
  std::vector<int> pos(n + 1), dep(n + 1);
  for (int i = 1; i <= n; i++) {
    dep[i] = std::__lg(i);
    mn += dep[i];
    p[i] = i >> 1;
    if (__builtin_popcount(i) == 1) {
      pos[dep[i]] = i;
    }
  }
  int maxd = std::__lg(n);
  if (mn > k || k > n * (n - 1) / 2) {
    std::cout << "NO\n";
    return;
  }
  int cur = n;
  for (int i = mn + 1; i <= k; i++) {
    if (__builtin_popcount(cur) == 1) {
      cur--;
    }
    p[cur] = pos[dep[cur]];
    int d = dep[p[cur]] + 1;
    dep[cur] = d;
    if (d > maxd) {
      maxd = d;
      pos[maxd] = cur;
      cur--;
    }
  }
  std::cout << "YES\n";
  for (int i = 2; i <= n; i++) {
    std::cout << p[i] << ' ';
  }
  std::cout << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("E.in", "r", stdin);
  freopen("E.out", "w", stdout);

  int _;
  std::cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}