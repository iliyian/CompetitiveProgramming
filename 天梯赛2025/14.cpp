#include <bits/stdc++.h>
// #define int long long

// float get(int lx, int ly, int rx, int ry, std::vector<std::vector<float>> &v) {
float get(int l, int r, std::vector<float> &v) {
  return v[r] - v[l - 1];
  // return v[rx][ry] + v[lx - 1][ly - 1] - v[rx][ly - 1] - v[lx - 1][ry];
}

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<int>> a(n + 1, std::vector<int>(m + 1));
  std::vector<std::pair<float, float>> b;
  std::vector<float> vx = {DBL_MIN / 3}, vy = {DBL_MIN / 3};
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      std::cin >> a[i][j];
      b.push_back({(i + j) / 2.0, (i - j) / 2.});
      vx.push_back((i + j) / 2.0);
      vy.push_back((i - j) / 2.0);
    }
  }
  std::sort(vx.begin() + 1, vx.end());
  std::sort(vy.begin() + 1, vy.end());
  vx.erase(std::unique(vx.begin(), vx.end()), vx.end());
  vy.erase(std::unique(vy.begin(), vy.end()), vy.end());
  int nn = vx.size() - 1, mm = vy.size() - 1;
  // std::vector<std::vector<float>> sx(nn + 1, std::vector<float>(mm + 1));
  // std::vector<std::vector<float>> sy(nn + 1, std::vector<float>(mm + 1));
  // std::vector<std::vector<float>> sc(nn + 1, std::vector<float>(mm + 1));
  std::vector<float> sx(nn + 1), sy(mm + 1);
  std::vector<float> scx(nn + 1), scy(mm + 1);
  auto id = [&](float x, std::vector<float> &v) {
    return std::lower_bound(v.begin() + 1, v.end(), x) - v.begin();
  };
  for (auto [x, y] : b) {
    auto idx = id(x, vx);
    auto idy = id(y, vy);
    sx[idx] += x;
    sy[idy] += y;
    scx[idx]++;
    scy[idy]++;
    // sx[idx][idy] += x;
    // sy[idx][idy] += y;
    // sc[idx][idy] += 1;
  }
  for (int i = 1; i <= nn; i++) {
    sx[i] += sx[i - 1];
    scx[i] += scx[i - 1];
  }
  for (int i = 1; i <= mm; i++) {
    sy[i] += sy[i - 1];
    scy[i] += scy[i - 1];
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      float x = (i + j) / 2.0, y = (i - j) / 2.0;
      auto idx = id(x, vx);
      auto idy = id(y, vy);
      float ans = get(1, idx, scx) * x - get(1, idx, sx) + get(idx, nn, sx) - x * get(idx, nn, scx);
      ans += get(1, idy, scy) * y - get(1, idy, sy) + get(idy, mm, sy) - y * get(idy, mm, scy);
      std::cout << ans * a[i][j] << " \n"[j == m];
    }
  }
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  // std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}