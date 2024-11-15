#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  std::cin >> n;
  int cnt0 = 0, cnt1 = 0;
  for (int i = 1; i <= n * 2; i++) {
    int x;
    std::cin >> x;
    cnt0 += !x;
    cnt1 += x;
  }
  std::cout << (cnt1 & 1 ? 1 : 0) << ' ' << std::min(cnt0, cnt1) << '\n';
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