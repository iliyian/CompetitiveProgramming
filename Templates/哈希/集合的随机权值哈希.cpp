// date: 2024-07-26 10:22:59
// tag: 随机权值实现的集合哈希，暴力，构造

#include <bits/stdc++.h>
#define int long long
// using namespace std;

std::mt19937_64 rd(std::random_device{}());
using u64 = unsigned long long;

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<int>> a(n + 1, std::vector<int>(m + 1));
  std::vector<u64> h(m + 1), p(n + 1), ones(m + 1);
  for (int i = 1; i <= n; i++) {
    p[i] = rd();
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      char x;
      std::cin >> x;
      a[i][j] = x - '0';
      if (a[i][j]) {
        h[j] ^= p[i];
        ones[j]++;
      }
    }
  }

  std::map<u64, int> cnt;
  std::string ans(n + 1, '0');
  int mx = 0, anst = 0;
  for (int j = 1; j <= m; j++) {
    std::string cur(n + 1, '0');
    for (int i = 1; i <= n; i++) {
      if (a[i][j]) {
        cur[i] = '1';
      }
    }
    for (int i = 1; i <= n; i++) {
      char tmp = cur[i];
      u64 H = h[j] ^ p[i];
      if (tmp == '1') {
        cur[i] = '0';
      } else {
        cur[i] = '1';
      }

      cnt[H]++;
      if (cnt[H] > mx) {
        mx = cnt[H];
        ans = cur;
      }

      cur[i] = tmp;
    }
  }
  std::cout << mx << '\n';
  for (int i = 1; i <= n; i++) {
    std::cout << ans[i];
  }
  std::cout << '\n';
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