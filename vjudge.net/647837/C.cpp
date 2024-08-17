#include <bits/stdc++.h>
#define int long long
// using namespace std;

struct Nodel {
  int l, r;
  bool operator < (const Nodel &b) const {
    return l < b.l;
  }
};

struct Noder {
  int l, r;
  bool operator < (const Noder &b) const {
    return r < b.r;
  }
};

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("C.in", "r", stdin);
  freopen("C.out", "w", stdout);

  int n, m;
  std::cin >> n >> m;

  std::vector<int> dl(n + 2), dr(n + 2);
  auto addl = [&](int x) {
    for (int i = x; i <= n + 1; i += i & -i) dl[i]++;
  };
  auto addr = [&](int x) {
    for (int i = x; i <= n + 1; i += i & -i) dr[i]++;
  };
  auto queryl = [&](int x) {
    int ans = 0;
    for (int i = x; i > 0; i -= i & -i) ans += dl[i];
    return ans;
  };
  auto queryr = [&](int x) {
    int ans = 0;
    for (int i = x; i > 0; i -= i & -i) ans += dr[i];
    return ans;
  };
  int cnt = 0;
  for (int i = 1; i <= m; i++) {
    int op, l, r;
    std::cin >> op >> l >> r;
    if (op == 1) {
      addl(l);
      addr(r);
    } else {
      int bad = queryr(l - 1) + cnt - queryl(r);
      std::cout << cnt - bad << '\n';
    }
  }

  return 0;
}