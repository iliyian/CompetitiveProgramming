#include <bits/stdc++.h>
#define int long long

int a[] = {-2, -1, 0, 1, 2};
std::vector<int> cur;

int len = 7;

void dfs(int u) {
  if (u == len + 1) {
    bool f = true;
    for (int S = 0; S < (1 << len); S++) {
      int a = 1, b = 1;
      if (__builtin_popcountll(S) != (len - 1) / 2) continue;
      for (int i = 0; i < len; i++) {
        if (S >> i & 1) {
          a = a * cur[i];
        } else {
          b = b * cur[i];
        }
      }
      if (a <= b) {
        f = false;
        break;
      }
    }
    if (f) {
      for (auto i : cur) {
        std::cout << i << ' ' ;
      }
      std::cout << '\n';
      exit(0);
    }
    return;
  }
  for (int i = 0; i < 5; i++) {
    cur.push_back(a[i]);
    dfs(u + 1);
    cur.pop_back();
  }
}

void solve() {
  int n;
  std::cin >> n;
  std::cout << "YES\n";
  if (n == 0) {
    std::cout << -2 << '\n';
    return;
  }
  if (n % 2 == 0) {
    for (int i = 1; i <= n * 2 + 1; i++) {
      std::cout << -2 << ' ';
    }
    std::cout << '\n';
  } else {
    for (int i = 1; i < n * 2 + 1; i++) {
      std::cout << -1 << ' ';
    }
    std::cout << 2 << '\n';
  }
  // for (int i = 1; i <= n;)
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  // dfs(1);
  // return 0;

  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}