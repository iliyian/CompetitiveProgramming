#include <bits/stdc++.h>
#define int long long

void solve(int _t) {
  int n, f;
  std::cin >> n >> f;
  std::vector<std::array<int, 3>> a(n);
  int ans = 0, tot = 0;
  int rf = f, mxr = 0;
  for (auto &[l, r, idx] : a) {
    std::cin >> l >> r;
    idx = tot++;
    ans += r - l;
  }
  // std::cerr << ans << '\n';
  std::ranges::sort(a);
  if (_t == 19) {
    for (auto [l, r, idx] : a) {
      std::cerr << l << ' ' << r << ' ' << idx << '\n';
    }
    std::cerr << '\n';
  }
  std::priority_queue<std::pair<int, int>> q;
  std::vector<int> vec, vis(n);
  for (int i = 0; i < n; i++) {
    if (a[i][0] <= f) {
      q.push({a[i][1], a[i][2]});
    } else {
      if (q.empty() || q.top().first <= f) {
        vec.push_back(a[i][2]);
        vis[a[i][2]] = 1;
        f = a[i][1];
        continue;
      }
      auto [r, idx] = q.top();
      vis[idx] = 1;
      vec.push_back(idx);
      f = r;
      while (!q.empty()) {
        q.pop();
      }
      i--;
    }
    if (_t == 19) {
      std::cerr << "i = " << i << ", f = " << f << '\n';
      for (auto i : vec) {
        std::cerr << i + 1 << ' ';
      }
      std::cerr << '\n';
    }
  }
  if (_t == 19) {
    for (int i = 0; i < n; i++) {
      std::cerr << vis[i] << ' ';
    }
    std::cerr << '\n';
  }
  std::ranges::sort(a, [&](auto x, auto y) {
    return x[1] > y[1];
  });
  for (int i = 0; i < n; i++) {
    if (!vis[a[i][2]]) {
      vec.push_back(a[i][2]);
    }
  }
  std::ranges::sort(a, [&](auto x, auto y) {
    return x[2] < y[2];
  });
  f = rf;
  for (int i = 0; i < n; i++) {
    ans += std::max(0ll, a[vec[i]][0] - f);
    f = a[vec[i]][1];
  }
  std::cout << ans << '\n';
  for (auto i : vec) {
    std::cout << i + 1 << ' ';
  }
  std::cout << '\n';
  if (_t == 19) {
    std::cerr << ans << '\n';
    for (auto i : vec) {
      std::cerr << i + 1 << ' ';
    }
    std::cerr << '\n';
    std::cerr << n << ' ' << f << '\n';
    for (auto [l, r, idx] : a) {
      std::cerr << l << ' ' << r << '\n';
    }
    std::cerr << '\n';
  }
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int t = 1;
  std::cin >> t;

  for (int i = 1; i <= t; i++) {
    solve(i);
  }

  return 0;
}