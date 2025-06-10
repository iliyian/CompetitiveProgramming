#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::string str;
  std::cin >> str;
  int acnt = 0, bcnt = 0, cnt = 0;
  str = '#' + str;
  for (int i = 1; i < (n - i + 1); i++) {
    if (str[i] != str[n - i + 1]) {
      bcnt++;
    } else if (str[i] == '0') {
      cnt += 2;
    }
  }
  if (n % 2 == 1 && (str[(n + 1) / 2] == '0')) {
    acnt = 1 + (cnt / 2) * 2;
    bcnt += (cnt + 1) / 2 * 2; 
  } else {
    acnt += 
  }
  std::cout << (acnt < bcnt ? "ALICE" : acnt == bcnt ? "DRAW" : "BOB") << '\n';
  // std::cerr << acnt << ' ' << bcnt << '\n';
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