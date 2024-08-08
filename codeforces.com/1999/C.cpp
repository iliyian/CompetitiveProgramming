#include <bits/stdc++.h>
#define int long long
// using namespace std;

void solve() {
  int n, s, m;
  std::cin >> n >> s >> m;
  std::vector<int> l(n + 1), r(n + 1);
  bool f = false;
  for (int i = 1; i <= n; i++) {
    std::cin >> l[i] >> r[i];
    if (l[i] - r[i - 1] >= s) {
      f = true;
    }
  }
  std::cout << (f || m - r[n] >= s ? "YES" : "NO") << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("C.in", "r", stdin);
  freopen("C.out", "w", stdout);

  int _;
  std::cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}