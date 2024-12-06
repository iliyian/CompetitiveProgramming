#include <bits/stdc++.h>
#define int long long

std::vector<int> f(1 << 19, INT_MIN);
std::vector<int> a(19);

int dx[] = {-1, -1, 0, 1, 1, 0}, dy[] = {0, 1, 1, 1, 0, -1};

bool in(int x, int y) {
  if (x < 1 || x > 5 || y < 1)
    return false;
  if (x == 1 || x == 5)
    return y <= 3;
  if (x == 2 || x == 4)
    return y <= 4;
  return y <= 5;
}

std::pair<int, int> xy(int id) {
  if (id <= 3)
    return {1, id};
  if (id <= 7)
    return {2, id - 3};
  if (id <= 12)
    return {3, id - 7};
  if (id <= 16)
    return {4, id - 12};
  return {5, id - 16};
}

int id(int x, int y) {
  if (x == 1)
    return y;
  if (x == 2)
    return 3 + y;
  if (x == 3)
    return 7 + y;
  if (x == 4)
    return 12 + y;
  return 16 + y;
}

int get(int x, int y, int S) {
  int i = id(x, y);
  return S >> (i - 1) & 1;
}

std::pair<int, int> nxt(int x, int y, int d) {
  if (d == 1)
    return {x, y + 1};
  if (d == 4)
    return {x, y - 1};
  if (d == 0)
    return {x - 1, y + (x > 3)};
  if (d == 2)
    return {x + 1, y + (x < 3)};
  if (d == 3)
    return {x + 1, y - (x > 3)};
  if (d == 5)
    return {x - 1, y - (x < 3)};
  assert(false);
}

int dfs(int S) {
  if (!S) return 0;
  if (f[S] != INT_MIN) return f[S];
  for (int i = 0; i < 19; i++) {
    if (S >> i & 1) {
      auto [x, y] = xy(i + 1);
      for (int d = 0; d < 6; d++) {
        auto [xx, yy] = nxt(x, y, d);
        if (!in(xx, yy) || !get(xx, yy, S)) 
          continue;
        auto [xxx, yyy] = nxt(xx, yy, d);
        if (!in(xxx, yyy) || get(xxx, yyy, S))
          continue;
        int ss = S ^ (1 << (id(xx, yy) - 1)) ^ (1 << (id(xxx, yyy) - 1)) ^
                  (1 << i);
        f[S] = std::max(f[S], dfs(ss) + a[id(xx, yy) - 1]);
        // f[ss] = std::max(f[ss], f[S] + a[id(xx, yy) - 1]);
      }
    } else {
      f[S] = std::max(f[S], dfs(S ^ (1 << i)));
      // f[S ^ (1 << i)] = std::max(f[S ^ (1 << i)], f[S]);
    }
  }
  return f[S];
}

void solve() {
  int cur = 0;
  for (int i = 0; i < 19; i++) {
    char ch;
    std::cin >> ch;
    if (ch == '#')
      cur ^= 1 << i;
  }
  std::cout << dfs(cur) << '\n';
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  f[0] = 0;
  for (int i = 0; i < 19; i++) {
    std::cin >> a[i];
  }
  // for (int t = 0; t < 19; t++) {
  // for (int S = 0; S < (1 << 19); S++) {
  // }
  // }
  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}