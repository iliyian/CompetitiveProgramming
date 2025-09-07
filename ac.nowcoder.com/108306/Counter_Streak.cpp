#include <bits/stdc++.h>
#include <ranges>
#define int long long

const int DAYS[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> f(400000);
  std::vector<std::array<int, 2>> v;
  for (int i = 1; i <= n; i++) {
    std::string date, t;
    std::cin >> date >> t;
    int y = std::stoll(date.substr(0, 4));
    int m = std::stoll(date.substr(5, 2));
    int d = std::stoll(date.substr(8, 2));
    int dayc = (y - 2000) * 365 + (y - 2000 + 3) / 4;
    dayc -= (y - 2100 + 99) / 100;
    dayc += (y - 2400 + 399) / 400;
    for (int i = 1; i < m; i++) {
      dayc += DAYS[i];
    }
    dayc += d;
    if (std::chrono::year(y).is_leap() && m > 2) {
      dayc++;
    }
    dayc++;
    // std::cerr << dayc << '\n';
    int l = dayc, r = dayc;
    if (t <= "19:59:59") {
      l--;
    }
    if (t >= "18:00:00") {
      r++;
    }
    v.push_back({l, r});
  }
  std::ranges::sort(v);
  for (auto &[l, r] : v) {
    for (int i : std::views::iota(l, r + 1) | std::views::reverse) {
      f[i] = std::max(f[i], f[i - 1] + 1);
    }
  }
  int ans = 0;
  for (int i : f) {
    ans = std::max(ans, i);
  }
  std::cout << ans << ' ' << 1 << '\n';
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