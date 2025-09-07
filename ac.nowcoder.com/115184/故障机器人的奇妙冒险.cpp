#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<int> a(n + 1);
  int mn = LLONG_MAX, mntag = LLONG_MAX, addtag = 0;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    mn = std::min(mn, a[i]);
  }
  while (m--) {
    int op;
    std::cin >> op;
    if (op == 1) {
      int id, x;
      std::cin >> id >> x;
      a[id] = std::min(a[id], mntag - addtag) - x;
      mn = std::min(mn, a[id]);
    } else if (op == 2) {
      int id;
      std::cin >> id;
      std::cout << std::min(a[id] + addtag, mntag) << '\n';
    } else if (op == 3) {
      int x;
      std::cin >> x;
      addtag += x;
      mntag -= x;
    } else if (op == 4) {
      int x;
      std::cin >> x;
      mntag = std::min(mntag, x);
    } else {
      std::cout << std::min(mn + addtag, mntag) << '\n';
    }
  }
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