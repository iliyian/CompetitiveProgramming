#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  std::set<int> s;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    s.insert(a[i]);
    if (i > 1) {
      s.insert(a[i] ^ a[i - 1]);
      s.insert(a[i] & a[i - 1]);
      s.insert(a[i] | a[i - 1]);
      s.insert(a[i] & (a[i] ^ a[i - 1]));
      s.insert(a[i - 1] & (a[i] ^ a[i - 1]));
    }
  }
  s.insert(0);
  std::cout << s.size() << '\n';
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