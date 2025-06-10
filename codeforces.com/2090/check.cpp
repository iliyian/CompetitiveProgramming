#include <bits/stdc++.h>
#define int long long

int isprime(int x) {
  if (x < 2)
    return false;
  for (int i = 2; i * i <= x; i++) {
    if (x % i == 0) {
      return false;
    }
  }
  return true;
}

void solve() {
  int x;
  std::vector<int> vec;
  while (std::cin >> x) {
    vec.push_back(x);
  }
  int cnt = 0, sum = 0;
  for (int i = 0; i < vec.size(); i++) {
    sum += vec[i];
    if (isprime((sum + i) / (i + 1))) {
      cnt++;
    }
  }
  std::cout << cnt << '\n';
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