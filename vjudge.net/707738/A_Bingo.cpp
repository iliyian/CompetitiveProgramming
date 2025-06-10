#include <bits/stdc++.h>
#define int long long

void solve() {
  std::string n;
  int m;
  std::cin >> n >> m;
  int nn = 0;
  if (n.size() < std::to_string(m).size()) {
    std::cout << m << '\n';
    return;
  }
  std::reverse(n.begin(), n.end());
  for (int i = 0; i < n.size(); i++) {
    nn = nn * 10 % m + n[i] - '0';
    nn %= m;
  }
  auto add = [&](std::string &t, int mid) {
    t.push_back('0');
    for (int i = 0; i < t.size(); i++) {
      t[i] += mid % 10;
      mid /= 10;
      t[i + 1] += (t[i] - '0') / 10;
      t[i] = (t[i] - '0') % 10 + '0';
    }
    while (t.back() == '0') t.pop_back();
    // std::reverse(t.begin(), t.end());
    // std::cout << t << '\n';
  };
  std::vector<int> p(11);
  p[0] = 1;
  for (int i = 1; i <= 10; i++) {
    p[i] = p[i - 1] * 10;
  }
  int len = 1;
  while (m >= p[len]) len++;
  std::string sm = std::to_string(m);
  auto check = [&](int mid) {
    std::string t = n;
    add(t, mid);
    for (int l = 0; l + len - 1 <= t.size() - 1; l++) {
      int r = l + len - 1;
      auto sn = n.substr(l, len);
      auto st = t.substr(l, len);
      std::reverse(sn.begin(), sn.end());
      std::reverse(st.begin(), st.end());
      if (sn <= sm && sm <= st || st <= sm && sm <= sn) {
        return true;
      }
    }
    return false;
  };
  int ans = m - nn;
  int l = 1, r = 1e10;
  std::cerr << ans << '\n';
  while (l <= r) {
    int mid = (l + r) / 2;
    if (check(mid)) r = mid - 1, ans = std::min(ans, mid);
    else l = mid + 1;
  }
  add(n, ans);
  std::reverse(n.begin(), n.end());
  std::cout << n << '\n';
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