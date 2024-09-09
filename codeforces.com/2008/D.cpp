#include <bits/stdc++.h>
#define int long long
// using namespace std;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  std::string str;
  std::cin >> str;
  str = '#' + str;
  std::vector<int> pa(n + 1), vis(n + 1);
  std::iota(pa.begin() + 1, pa.end(), 1);
  for (int i = 1; i <= n; i++) {
    int x = i;
    while (!vis[x]) {
      pa[x] = i;
      vis[x] = 1;
      x = a[x];
    }
  }
  std::vector<int> ans(n + 1);
  for (int i = 1; i <= n; i++) {
    ans[pa[i]] += str[i] == '0';
  }
  for (int i = 1; i <= n; i++) {
    std::cout << ans[pa[i]] << " \n"[i == n];
  }
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("D.in", "r", stdin);
  freopen("D.out", "w", stdout);

  int _;
  std::cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}