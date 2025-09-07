#include <bits/stdc++.h>
#define int long long

std::map<std::array<int, 3>, int> mp;

std::pair<int, int> near(int i, int n, int typ) {
  if (typ == 1) {
    if (i == 0) return {1, 1};
    if (i == n - 1) return {n - 2, n - 2};
    return {i - 1, i + 1};
  }
  return {(i + 1) % n, (i - 1 + n) % n};
}

int get(int n, int S, int type) {
  if (__builtin_popcountll(S) == n) return 0;
  if (mp.count({n, S, type})) return mp[{n, S, type}];
  std::set<int> s;
  for (int i = 0; i < n; i++) {
    auto [l, r] = near(i, n, type);
    if ((S >> l & 1 ^ 1) || (S >> r & 1 ^ 1)) { // 存在可支配
      int t = S;
      t |= 1 << l;
      t |= 1 << r;
      t |= 1 << i;
      s.insert(get(n, t, type));
    }
  }
  int mex = 0;
  while (s.count(mex)) mex++;
  return mp[{n, S, type}] = mex;
}

int get(int n, int type) {
  if (type == 1) {
    if (n == 3) return 2;
    if (n % 4 == 0) return 0;
    if (n % 4 == 3) return 3;
    return 1;
  } else {
    if (n <= 2) return 1;
    if (n % 4 == 3) return 1;
    return 0;
  }
}

void solve() {
  int n;
  std::cin >> n;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    int num, type;
    std::cin >> num >> type;
    ans ^= get(num, type);
  }
  std::cout << (ans ? "Yes" : "No") << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  // for (int i = 1; i <= 20; i++) {
  //   for (int j = (i >= 3 ? 0 : 1); j < 2; j++) {
  //   // for (int j = 0; j < 2; j++) {
  //   // for (int j = 0; j < 2; j++) {
  //     std::cout << i << ' ' << j << ' ' << get(i, 0, j) << '\n';
  //     assert(get(i, 0, j) == get(i, j));
  //   }
  // }

  int t = 1;
  std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}