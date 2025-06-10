#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::string str;
  std::cin >> n >> str;
  str = '#' + str;
  std::vector<int> l, r;
  int rs = 0;
  for (int i = 1; i <= n; i++) {
    if (str[i] == '>') {
      l.push_back(i);
    } else {
      r.push_back(i);
      rs += i;
    }
  }
  int ls = 0;
  int lcnt = 0, rcnt = r.size();
  for (int i = 1; i <= n; i++) {
    if (str[i] == '>') {
      lcnt++, ls += i;
    }
    if (str[i] == '>') {
      if (rcnt < lcnt) { // right
        std::cout << n + 1 + rs * 2 - (ls - i) * 2 - i << '\n';
      } else { // left
        std::cout << rs * 2 - (ls - i) * 2 - i << '\n';
      }
    } else {
      if (lcnt < rcnt) { // left
        
      } else { // right

      }
    }
    if (str[i] == '<') {
      rcnt--, rs += i;
    }
  }
  std::cerr << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int t = 1;
  std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}