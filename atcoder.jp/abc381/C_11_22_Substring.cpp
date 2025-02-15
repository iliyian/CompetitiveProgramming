#include <bits/stdc++.h>
#define int long long

std::vector<int> prefix_function(const std::string &s) {
  int n = s.size();
  std::vector<int> pi(n);
  for (int i = 1; i < n; i++) {
    int j = pi[i - 1];
    while (j > 0 && s[i] != s[j]) j = pi[j - 1];
    if (s[i] == s[j]) j++;
    pi[i] = j;
  }
  return pi;
}

void solve() {
  int n;
  std::string str;
  std::cin >> n >> str;
  int ans = 0;
  auto check = [&](int mid) {
    std::string s;
    for (int i = 0; i < mid; i++) s += '1';
    s += '/';
    for (int i = 0; i < mid; i++) s += '2';
    s += '#';
    s += str;
    auto pi = prefix_function(s);
    for (int i = mid * 2 + 2; i < pi.size(); i++) {
      if (pi[i] == mid * 2 + 1) {
        return true;
      }
    }
    return false;
  };
  int l = 0, r = n;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (check(mid)) l = mid + 1, ans = mid;
    else r = mid - 1;
  }
  std::cout << ans * 2 + 1 << '\n';
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