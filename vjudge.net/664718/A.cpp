#include <bits/stdc++.h>
#define int long long

signed main() {
  int n;
  std::cin >> n;
  std::vector<std::string> a(n);
  std::map<std::string, int> cnt;
  for (auto &s : a) {
    std::cin >> s;
    cnt[s]++;
  }
  for (auto &[k, v] : cnt) {
    if (v > n / 2) {
      std::cout << k << '\n';
      return 0;
    }
  }
  std::cout << "uh-oh" << '\n';
}