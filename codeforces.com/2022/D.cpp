// date: 2024-12-13 22:28:18
// tag: 考虑边O(n)的类图问题，往往整体是个环

#include <bits/stdc++.h>
#define int long long

int ask(int x, int y) {
  int ans = 0;
  std::cout << "? " << x << ' ' << y << std::endl;
  std::cin >> ans;
  return ans;
}

void answer(int x) {
  std::cout << "! " << x << std::endl;
}

void solve() {
  int n;
  std::cin >> n;
  int ansx = 0, ansy = 0, z = 1;
  for (int i = 1; i < n; i += 2) {
    int x = ask(i, i + 1), y = ask(i + 1, i);
    if (x != y) {
      ansx = i, ansy = i + 1;
      break;
    }
  }
  if (!ansx && !ansy) {
    answer(n);
    return;
  }
  while (z == ansx || z == ansy) z++;
  if (ask(ansx, z) != ask(z, ansx)) {
    answer(ansx);
  } else {
    answer(ansy);
  }
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}