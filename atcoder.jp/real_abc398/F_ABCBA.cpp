#include <bits/stdc++.h>
#define int long long

std::mt19937 rd(std::random_device{}());

bool isprime(int x) {
  if (x < 2) return false;
  for (int i = 2; i * i <= x; i++) {
    if (x % i == 0) {
      return false;
    }
  }
  return true;
}

int findPrime(int x) {
  while (!isprime(x)) x++;
  return x;
}

const int P = findPrime(rd() % (int)9e8 + (int)1e8);

void solve() {
  std::string str;
  std::cin >> str;
  int n = str.size();
  str = '#' + str;
  std::vector<int> pre(n + 1), suf(n + 2), p(n + 1);
  p[0] = 1;
  for (int i = 1; i <= n; i++) {
    p[i] = p[i - 1] * 128 % P;
  }
  for (int i = 1; i <= n; i++) {
    pre[i] = pre[i - 1] * 128 % P + str[i];
    pre[i] %= P;
  }
  for (int i = n; i >= 1; i--) {
    suf[i] = suf[i + 1] * 128 % P + str[i];
    suf[i] %= P;
  }
  auto check = [&](int l, int r) {
    int x = pre[r] - pre[l - 1] * p[r - l + 1] % P;
    if (x < 0) x += P;
    int y = suf[l] - suf[r + 1] * p[r - l + 1] % P;
    if (y < 0) y += P;
    return x == y;
  };
  for (int i = 1; i <= n; i++) {
    if (check(i, n)) {
      std::cout << str.substr(1, str.size() - 1);
      for (int j = i - 1; j >= 1; j--) {
        std::cout << str[j];
      }
      std::cout << '\n';
      return;
    }
  }
  std::cout << str.substr(1, str.size() - 1);
  std::reverse(str.begin() + 1, str.end());
  std::cout << str.substr(1, str.size() - 1) << '\n';
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