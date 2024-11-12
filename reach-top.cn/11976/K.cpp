#include <bits/stdc++.h>
#define int long long

int num(char x) {
  if (isdigit(x)) return x - '0';
  return x - 'A' + 10;
}

void solve() {
  int k;
  std::string s;
  std::cin >> k >> s;
  int ans = 0;
  for (int i = 0; i < s.size(); i++) {
    ans += pow(k, s.size() - i - 1) * num(s[i]);
  }
  std::cout << ans << '\n';
}

signed main() {
  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}