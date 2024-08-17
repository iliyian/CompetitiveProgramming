#include <bits/stdc++.h>
#define int long long
// using namespace std;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  bool f = false, g = false;
  int mx = 0;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    f |= (a[i] & 1);
    g |= (a[i] & 1 ^ 1);
    if (a[i] & 1) {
      mx = std::max(mx, a[i]);
    }
  }
  if (!f || !g) {
    std::cout << 0 << '\n';
    return;
  }
  int ans = 0;
  std::vector<int> v;
  for (int i = 1; i <= n; i++) {
    if (a[i] & 1 ^ 1) {
      v.push_back(a[i]);
    }
  }
  std::sort(v.begin(), v.end());
  f = false;
  for (int i = 0; i < v.size(); i++) {
    if (v[i] > mx) {
      f = true;
      ans++;
    } else {
      ans++;
    }
    mx = v[i] + mx;
  }
  std::cout << ans + f << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("B.in", "r", stdin);
  freopen("B.out", "w", stdout);

  int _;
  std::cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}