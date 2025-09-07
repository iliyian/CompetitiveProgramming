#include <bits/stdc++.h>
#define int long long

std::mt19937_64 rd(std::random_device{}());

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> ans(n + 1);
  auto solve = [&](this auto &&self, int l, int r, std::vector<int> now) {
    if (l == r) {
      ans[l] = now.front();
      return;
    }
    int mid = (l + r) / 2;
    std::vector<int> lv, rv;
    std::vector<std::vector<int>> has(n + 1);
    for (int i : now) {
      has[i].push_back(i);
    }
    auto push = [&](int x, std::vector<int> &v) {
      for (int i : has[x]) {
        v.push_back(i);
      }
    };
    while (now.size() >= 2) {
      std::shuffle(now.begin(), now.end(), rd);
      std::cout << 0 << ' ';
      int len = now.size();
      for (int i = 1; i <= n; i++) {
        std::cout << (i <= mid ? now[len - 2] : now[len - 1]) << ' ';
      }
      std::cout << std::endl;
      int ans;
      std::cin >> ans;
      if (ans == 2) {
        push(now[len - 2], lv);
        push(now[len - 1], rv);
        now.pop_back();
        now.pop_back();
      } else if (ans == 1) {
        has[now[len - 2]].push_back(now[len - 1]);
        now.pop_back();
      } else {
        push(now[len - 1], lv);
        push(now[len - 2], rv);
        now.pop_back();
        now.pop_back();
      }
    }
    mid = (l + r) / 2;
    if (now.size() == 1) {
      if (lv.size() != mid - l + 1) {
        push(now.front(), lv);
      } else {
        push(now.front(), rv);
      }
    }
    self(l, mid, lv);
    self(mid + 1, r, rv);
  };
  std::vector<int> ini(n);
  std::ranges::iota(ini, 1);
  solve(1, n, ini);
  std::cout << 1 << ' ';
  for (int i = 1; i <= n; i++) {
    std::cout << ans[i] << ' ';
  }
  std::cout << std::endl;
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int t = 1;
  // std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}