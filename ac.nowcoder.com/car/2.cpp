#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  std::cin >> n;
  int a[26];
  for (int i = 0; i < 26; i++) {
    std::cin >> a[i];
  }
  std::string str;
  std::cin >> str;
  char pre = str[0];
  int len = 1;
  for (int i = 1; i <= n; i++) {
    if (i == n || str[i] != pre) {
      if (a[pre - 'a'] == 0 || len % a[pre - 'a']) {
        std::cout << "No\n";
        return;
      }
      pre = str[i];
      len = 1;
    } else {
      len++;
    }
  }
  std::cout << "Yes\n";
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}