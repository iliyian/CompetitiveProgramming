#include <bits/stdc++.h>
#define int long long
// using namespace std;

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("D.in", "r", stdin);
  freopen("D.out", "w", stdout);

  int n, m, q;
  std::cin >> n >> m >> q;
  std::string str;
  std::cin >> str;
  str = '#' + str;
  int sum = std::count(str.begin(), str.end(), '1');
  std::vector<int> pa(n + 1), vis(n + 1);
  auto find = [&](auto self, int x) -> int {return x == pa[x] ? x : pa[x] = self(self, pa[x]);};
  std::vector<int> p(n + 1);
  int tot = 0;
  for (int i = 1; i <= m; i++) {
    int l, r;
    std::cin >> l >> r;
    for (int j = l; j <= r; j = find(find, j) + 1) {
      if (!vis[j]) {
        vis[j] = true;
        pa[j - 1] = j;
        p[j] = ++tot;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      p[i] = ++tot;
    }
  }
  std::vector<int> d(n + 1);
  auto add = [&](int x, int c) {
    for (int i = x; i <= n; i += i & -i) d[x]++;
  };
  auto query = [&](int x) {
    int ans = 0; for (int i = x; i > 0; i -= i & -i) ans += d[i]; return ans;
  };
  while ( q-- ) {
    int x;
    std::cin >> x;
    if (str[x] == '1') str[x] = '0', sum--;
    else str[x] = '1', sum++;
    
  }

  return 0;
}