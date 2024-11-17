#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  std::string str;
  std::cin >> str;
  int prv = 0;
  for (int i = 1; i < str.size(); i++) {
    if (str[i] == '|') {
      std::cout << i - prv - 1 << ' ';
      prv = i;
    }
  }
  std::cout << '\n';
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  // std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
};