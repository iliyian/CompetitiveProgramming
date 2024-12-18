// date: 2024-08-09 09:10:23
// tag: 分块模板

#include <algorithm>
#include <bits/stdc++.h>
#define int long long
// using namespace std;

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  int n, q;
  std::cin >> n >> q;

  std::vector<int> a(n + 1), d(n + 1), L(n + 1), R(n + 1), belong(n + 1),
      laz(n + 1);
  int block = sqrt(n);
  int tot = n / block;
  if (n % block)
    tot++;

  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }

  for (int i = 1; i <= n; i++) {
    belong[i] = (i + block - 1) / block;
    L[belong[i]] = block * belong[i] - block + 1;
    R[belong[i]] = std::min(n, L[belong[i]] + block - 1);
  }
  auto update = [&](int l, int r) {
    std::copy(a.begin() + l, a.begin() + r + 1, d.begin() + l);
    std::sort(d.begin() + l, d.begin() + r + 1);
  };
  auto add = [&](int l, int r, int c) {
    for (int i = l; i <= r; i++) {
      a[i] += c;
    }
  };
  auto query = [&](int l, int r, int k) {
    return std::count_if(a.begin() + l, a.begin() + r + 1,
                         [&](const int &x) { return x + laz[belong[l]] >= k; });
  };
  for (int i = 1; i <= tot; i++) {
    update(L[i], R[i]);
  }
  while (q--) {
    char ch;
    int x, y, k;
    std::cin >> ch >> x >> y >> k;
    if (ch == 'M') {
      if (belong[x] == belong[y]) {
        add(x, y, k);
        update(L[belong[x]], R[belong[y]]);
      } else {
        add(x, R[belong[x]], k);
        update(L[belong[x]], R[belong[x]]);
        add(L[belong[y]], y, k);
        update(L[belong[y]], R[belong[y]]);
        for (int i = belong[x] + 1; i <= belong[y] - 1; i++) {
          laz[i] += k;
        }
      }
    } else {
      int ans = 0;
      if (belong[x] == belong[y]) {
        ans = query(x, y, k);
      } else {
        ans += query(x, R[belong[x]], k);
        ans += query(L[belong[y]], y, k);
        for (int i = belong[x] + 1; i <= belong[y] - 1; i++) {
          ans += d.begin() + R[i] + 1 -
                 std::lower_bound(d.begin() + L[i], d.begin() + R[i] + 1,
                                  k - laz[i]);
        }
      }
      std::cout << ans << '\n';
    }
  }

  return 0;
}