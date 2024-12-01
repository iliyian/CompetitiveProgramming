#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  int real = 0;
  for (int i = 0; i <= k; i++) {
    auto b = a;
    for (int j = 1; j <= n; j++) {
      b[j] ^= i;
    }
    if (std::is_sorted(b.begin() + 1, b.end())) {
      // std::cout << i << ' ';
      real++;
    }
  }
  std::vector<int> status(63, -1);
  bool ok = true;

  auto dfs = [&](auto self, int l, int r, int w) {
    if (l >= r || w < 0) return;
    if (a[l] >> w & 1 && a[r] >> w & 1) {
      for (int i = l; i <= r; i++) {
        if (a[i] >> w & 1 ^ 1) {
          ok = false;
          break;
        }
      }
      self(self, l, r, w - 1);
    } else if (a[l] >> w & 1 ^ 1 && a[r] >> w & 1 ^ 1) {
      for (int i = l; i <= r; i++) {
        if (a[i] >> w & 1) {
          ok = false;
          break;
        }
      }
      self(self, l, r, w - 1);
    } else {
      int mid = 0;
      for (int i = l; i <= r - 1; i++) {
        if ((a[i] >> w & 1) ^ (a[i + 1] >> w & 1)) {
          if (mid) {
            ok = false;
            break;
          }
          mid = i;
        }
      }
      if (!ok) return;
      if (a[l] >> w & 1) {
        if (status[w] == 0) {
          ok = false;
        }
        status[w] = 1;
      } else {
        if (status[w] == 1) {
          ok = false;
        }
        status[w] = 0;
      }
      self(self, l, mid, w - 1);
      self(self, mid + 1, r, w - 1);
    }
  };
  dfs(dfs, 1, n, 62);
  std::vector<int> vec;
  int pre = 0;
  for (int i = 62; i >= 0; i--) {
    if (status[i] == -1) {
      vec.push_back(i);
    } else if (status[i] == 1) {
      pre += 1ll << i;
    }
  }
  int ans = 0, cur = 0;
  // std::cout << pre << '\n';
  for (int w : vec) {
    if (cur + (1ll << w) + pre <= k) {
      ans = ans * 2 + 1;
      cur += (1ll << w);
    } else {
      ans = ans * 2;
    }
  }
  if (pre <= k) ans++;
  std::cout << (ok ? ans : 0) << '\n';
  std::cout << real << '\n';
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }
}