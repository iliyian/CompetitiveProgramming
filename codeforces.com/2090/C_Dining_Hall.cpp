#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  std::priority_queue<std::array<int, 3>, std::vector<std::array<int, 3>>, std::greater<>> q1;
  q1.push({2, 1, 1});
  std::map<std::array<int, 2>, bool> vis;
  std::map<std::array<int, 2>, bool> visid;
  auto getd = [&](int xid, int yid, int dx, int dy) {
    int d = 3 * (xid + yid) + dx + dy;
    if (dx == 2 && dy == 2) d += 2;
    return d;
  };
  int xid2 = 0, yid2 = 0, sum = 0;
  auto visit = [&](int x, int y) {
    int xid = x / 3, yid = y / 3;
    int dx = x % 3, dy = y % 3;
    if (dx == 2) {
      q1.push({getd(xid + 1, yid, 1, dy), 3 * (xid + 1) + 1, 3 * yid + dy});
    } else {
      q1.push({getd(xid, yid, 2, dy), 3 * xid + 2, 3 * yid + dy});
    }
    if (dy == 2) {
      q1.push({getd(xid, yid + 1, dx, 1), 3 * xid + dx, 3 * (yid + 1) + 1});
    } else {
      q1.push({getd(xid, yid, dx, 2), 3 * xid + dx, 3 * yid + 2});
    }
    vis[{x, y}] = 1;
    if (xid2 == xid && yid2 == yid) {
      if (yid2 == 0) {
        sum++;
        xid2 = 0, yid2 = sum;
      } else {
        xid2++;
        yid2--;
      }
    }
  };
  auto get1 = [&](auto self) -> std::array<int, 2> {
    auto [d, x, y] = q1.top(); q1.pop();
    if (vis[{x, y}]) return self(self);
    visit(x, y);
    return {x, y};
  };
  for (int i = 1; i <= n; i++) {
    if (a[i] == 1) {
      auto [x, y] = get1(get1);
      std::cout << x << ' ' << y << '\n';
    } else {
      std::cout << 3 * xid2 + 1 << ' ' << 3 * yid2 + 1 << '\n';
      visit(3 * xid2 + 1, 3 * yid2 + 1);
    }
  }
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