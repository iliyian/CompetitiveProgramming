#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  std::map<int, int> cnt;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    cnt[a[i]]++;
    ans = std::max(ans, cnt[a[i]]);
  }
  std::cout << n - ans << '\n';
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  freopen("A.in", "r", stdin);
  int t;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}