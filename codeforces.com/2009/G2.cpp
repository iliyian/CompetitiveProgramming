#include <bits/stdc++.h>
#define int long long
// using namespace std;

void solve() {
  int n, k, q;
  std::cin >> n >> k >> q;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    a[i] -= i;
  }
  
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("G2.in", "r", stdin);
  freopen("G2.out", "w", stdout);

  int _;
  std::cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}