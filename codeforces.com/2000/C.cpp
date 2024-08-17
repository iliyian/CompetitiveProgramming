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
  int m;
  std::cin >> m;
  for (int i = 1; i <= m; i++) {
    std::string str;
    std::cin >> str;
    bool f = true;
    std::vector<int> num(26, LLONG_MAX);
    std::set<int> s;
    if (str.size() != n) {
      std::cout << "NO\n";
      continue;
    }
    for (int j = 0; j < str.size(); j++) {
      auto &x = num[str[j] - 'a'];
      if (x == LLONG_MAX) {
        x = a[j + 1];
        if (s.count(a[j + 1])) {
          f = false;
          break;
        } else {
          s.insert((a[j + 1]));
        }
      } else if (x != a[j + 1]) {
        f = false;
        break;
      }
    }
    if (!f) {
      std::cout << "NO\n";
      continue;
    }
    std::cout << "YES\n";
  }
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("C.in", "r", stdin);
  freopen("C.out", "w", stdout);

  int _;
  std::cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}