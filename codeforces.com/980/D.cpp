// date: 2024-08-04 10:48:03
// tag: 数学结论，区间统计

#include <bits/stdc++.h>
#define int long long
// using namespace std;

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("D.in", "r", stdin);
  freopen("D.out", "w", stdout);

  int n;
  std::cin >> n;
  std::vector<int> a(n + 1), pa(n + 1), siz(n + 1, 1);
  std::iota(pa.begin() + 1, pa.end(), 1);
  auto find = [&](auto self, int x) -> int {return x == pa[x] ? x : pa[x] = self(self, pa[x]);};
  auto merge = [&](int x, int y) {
    x = find(find, x), y = find(find, y);
    if (x == y) {
      return;
    }
    if (siz[x] > siz[y]) {
      std::swap(x, y);
    }
    pa[x] = y;
    siz[y] += siz[x];
  };
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      int x = a[i] * a[j];
      if (x > 0) {
        int t = sqrt(x);
        if (t * t == x) {
          merge(i, j);
        }
      }
    }
  }
  std::vector<int> ans(n + 1);
  for (int i = 1; i <= n; i++) {
    std::vector<int> cnt(n + 1);
    int sum = 0;
    for (int j = i; j <= n; j++) {
      if (a[j] == 0) {
        ans[std::max<int>(1, sum)]++; // 上善若0
        continue;
      }
      int x = find(find, j);
      if (++cnt[x] == 1) {
        sum++;
      }
      ans[sum]++;
    }
  }
  for (int i = 1; i <= n; i++) {
    std::cout << ans[i] << ' ';
  }
  std::cout << '\n';

  return 0;
}