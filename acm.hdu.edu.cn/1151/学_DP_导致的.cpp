#include <bits/stdc++.h>
#define int long long

void solve() {
  std::string str, sk;
  std::cin >> str >> sk;
  int k = 0;
  if (sk.size() >= 10) {
    k = 50;
  } else {
    k = std::min(50ll, std::stoll(sk));
  }
  std::string res;
  for (int i = 0; i < k; i++) {
    res += str;
  }
  std::vector<int> b;
  for (int i = 0; i < res.size(); i++) {
    auto p = std::lower_bound(b.begin(), b.end(), res[i]);
    if (b.empty() || p == b.end()) b.push_back(res[i]);
    else *p = res[i];
  }
  // for (auto i : b) {
  //   std::cerr << char(i);
  // }
  std::cout << b.size() << '\n';
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