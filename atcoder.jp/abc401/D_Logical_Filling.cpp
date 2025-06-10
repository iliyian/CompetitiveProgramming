#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::string str;
  std::cin >> str;
  str = '#' + str;
  for (int i = 2; i <= n; i++) {
    if (str[i] == '?' && str[i - 1] == 'o') {
      str[i] = '.';
    }
  }
  for (int i = 1; i <= n - 1; i++) {
    if (str[i] == '?' && str[i + 1] == 'o') {
      str[i] = '.';
    }
  }
  int cnt = 0, mx = 0, need = k;
  for (int i = 1; i <= n; i++) {
    need -= str[i] == 'o';
  }
  bool f = true;
  std::vector<int> l(n + 1), r(n + 1);
  int prv = 0;
  for (int i = 1; i <= n; i++) {
    if (str[i] == '?') {
      cnt++;
      if (prv == 0) {
        prv = i;
      }
      l[i] = prv;
    } else if (cnt) {
      prv = 0;
      mx += (cnt + 1) / 2;
      cnt = 0;
    }
  }
  if (cnt) {
    mx += (cnt + 1) / 2;
    cnt = 0;
  }
  prv = 0;
  for (int i = n; i >= 1; i--) {
    if (str[i] == '?') {
      if (prv == 0) {
        prv = i;
      }
      r[i] = prv;
    } else {
      prv = 0;
    }
  }
  // std::cerr << need << ' ' << mx << '\n';
  for (int i = 1; i <= n; i++) {
    if (str[i] == '?') {
      if (!need) {
        std::cout << ".";
        continue;
      }
      // std::cerr << i << ' ' << l[i] << ' ' << r[i] << '\n';
      if (need != mx) {
        std::cout << "?";
        continue;
      }
      int len = r[i] - l[i] + 1;
      if (len % 2 == 0) {
        std::cout << "?";
        continue;
      }
      // std::cerr << l[i] << ' ';
      if ((i - l[i]) % 2 == 0) {
        std::cout << "o";
      } else {
        std::cout << ".";
      }
    } else {
      std::cout << str[i];
    }
  }
  std::cout << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  // std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}