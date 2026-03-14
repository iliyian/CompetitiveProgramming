#include <bits/stdc++.h>
#define int long long

void solve() {
  std::set<int> st;
  int x;
  int ans = -1;
  while (std::cin >> x) {
    if (x == -1) break;
    if (ans == -1 && st.count(x)) ans = x;
    st.insert(x);
  }
  if (ans == -1) {
    std::cout << "NONE\n";
  } else {
    std::cout << ans << '\n';
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