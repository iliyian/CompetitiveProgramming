#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1), b;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    if (!b.empty() && (a[i] < 0 && b.back() < 0 || a[i] > 0 && b.back() > 0)) {
      b.back() += a[i];
    } else {
      b.push_back(a[i]);
    }
  }
  if (b.size() == 1) {
    std::cout << std::abs(b.front()) << '\n';
    return;
  }
  std::vector<int> ls1(b.size()), rs1(b.size()), rs2(b.size()), ls2(b.size());
  for (int i = 0; i < b.size(); i++) {
    ls1[i] = (i ? ls1[i - 1] : 0);
    ls2[i] = (i ? ls2[i - 1] : 0);
    if (b[i] > 0) ls2[i] += b[i];
    else ls1[i] += b[i];
  }
  for (int i = b.size() - 1; i >= 0; i--) {
    rs1[i] = (i != b.size() - 1 ? rs1[i + 1] : 0);
    rs2[i] = (i != b.size() - 1 ? rs2[i + 1] : 0);
    if (b[i] > 0) rs2[i] += b[i];
    else rs1[i] += b[i];
  }
  int ans = 0;
  for (int i = 0; i < b.size() - 1; i++) {
    if (b[i] < 0) ans = std::max({ans, -ls1[i], rs2[i + 1]});
    else ans = std::max(ans, ls2[i] - rs1[i + 1]);
  }
  if (b.back() < 0) {
    ans = std::max(ans, -ls1[b.size() - 1]);
  }
  if (b.front() > 0) {
    ans = std::max(ans, rs2[0]);
  }
  std::cout << ans << '\n';
  // for (int i = 0; i < ls1.size(); i++) {
  //   std::cerr << ls1[i] << ' ' << rs1[i] << ' ' << ls2[i] << ' ' << rs2[i] << '\n';
  // }
  // std::cerr << '\n';
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