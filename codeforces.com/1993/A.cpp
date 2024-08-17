#include <bits/stdc++.h>
#define int long long
// using namespace std;

void solve() {
  int n;
  std::string str;
  std::cin >> n >> str;
  std::vector<int> cnt(4);
  for (int i = 0; i < 4 * n; i++) {
    if (str[i] != '?') {
      cnt[str[i] - 'A']++;
    }
  }
  int ans = 0;
  for (int i = 0; i < 4; i++) {
    ans += std::min(n, cnt[i]);
  }
  std::cout << ans << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("A.in", "r", stdin);
  freopen("A.out", "w", stdout);

  int _;
  std::cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}