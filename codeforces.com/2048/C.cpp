#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> prefix_function(const string &s) {
  int n = s.size();
  vector<int> pi(n);
  for (int i = 1; i < n; i++) {
    int j = pi[i - 1];
    while (j > 0 && s[i] != s[j]) j = pi[j - 1];
    if (s[i] == s[j]) j++;
    pi[i] = j;
  }
  return pi;
}

void solve() {
  std::string str;
  std::cin >> str;
  int n = str.size();
  if (str.find('0') == -1) {
    std::cout << 1 << ' ' << n << ' ' << 1 << ' ' << 1 << '\n';
    return;
  }
  str = '#' + str;
  int p = 1;
  while (str[p] == '1') p++;
  auto mx = str;
  int ansl = 0, ansr = 0;
  for (int l = 1; l + (n - p) <= n; l++) {
    int r = l + n - p;
    auto t = str;
    for (int i = r; i >= l; i--) {
      t[n + i - r] ^= str[i] == '1';
    }
    if (t > mx) {
      mx = t;
      ansl = l, ansr = r;
    }
  }
  // std::cout << mx << '\n';
  std::cout << 1 << ' ' << n << ' ' << ansl << ' ' << ansr << '\n';
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
