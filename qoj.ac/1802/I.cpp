#include <bits/stdc++.h>
#define int long long

void solve() {
  std::string str;
  std::cin >> str;
  std::vector<int> a;
  int l = 0, r = str.size() - 1;
  if (str[l] == str[r]) {
    while (l <= r && str[l] == str[r]) l++;
    while (l <= r && str[r] == str[l - 1]) r--;
    a.push_back(l + str.size() - r - 1);
  }
  char prv = str[l];
  int cnt = 1;
  for (int i = l + 1; i <= r; i++) {
    if (str[i] == prv) {
      cnt++;
    } else {
      a.push_back(cnt);
      prv = str[i];
      cnt = 1;
    }
  }
  if (l <= r) {
    a.push_back(cnt);
  }
  int ans = 0;
  bool f = false;
  for (int i : a) {
    f |= i % 2 == 0;
    ans += i / 2;
    // std::cerr << i << ' ';
  }
  // std::cerr << '\n';
  std::cout << ans - (f && l <= r) << '\n';
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