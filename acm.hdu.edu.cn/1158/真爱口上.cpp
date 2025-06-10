#include <bits/stdc++.h>
#define int long long

std::string aeiou = "aeiou";
std::string ptks = "ptks";

int solve(std::string &str) {
  int n = str.size();
  str = '#' + str;
  auto isaeiou = [&](char c) {
    return aeiou.find(c) != std::string::npos;
  };
  auto isptks = [&](char c) {
    return ptks.find(c) != std::string::npos;
  };
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (isaeiou(str[i])) {
      ans++;
    }
  }
  for (int i = 2; i <= n; i++) {
    if (str[i] == str[i - 1] && isptks(str[i])) {
      ans++;
    }
  }
  for (int i = 1; i <= n - 1; i++) {
    if (str[i] == 'n' && str[i + 1] == 'n') {
      str[i] = str[i + 1] = '#';
      ans++;
    }
  }
  // for (int i = 1; i <= n - 1; i++) {
  //   if (str[i] == 'n' && (isaeiou(str[i + 1]) || str[i + 1] == 'y')) {
  //     str[i] = str[i + 1];
  //   }
  // }
  return ans;
}

void solve() {
  std::string a, b;
  std::cin >> a >> b;
  int x = solve(a), y = solve(b);
  std::cout << x << ' ' << y << '\n';
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