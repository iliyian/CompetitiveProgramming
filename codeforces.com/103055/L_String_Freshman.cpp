#include <bits/stdc++.h>
#define int long long

int isPrime(int x) {
  for (int i = 2; i * i <= x; i++) {
    if (x % i == 0) {
      return false;
    }
  }
  return true;
}

int findPrime(int x) {
  while (!isPrime(x)) x++;
  return x;
}

std::mt19937 rd(std::random_device{}());

void solve() {
  const int P = findPrime(rd() % (int)(9e8) + (int)1e8);

  int n;
  std::string str;
  std::cin >> n >> str;
  str = '#' + str;
  std::vector<int> h(n + 1), b(n + 1);
  b[0] = 1;
  for (int i = 1; i <= n; i++) {
    b[i] = b[i - 1] * 26 % P;
    h[i] = h[i - 1] * 26 % P + str[i];
    h[i] %= P;
  }
  auto get = [&](int l, int r) {
    return (h[r] - h[l - 1] + P) % P
  };
  for (int i = 1; i <= n - 1; i++) {
    if (get(1, i) == get(n - i + 1, n)) {
      std::cout << "Wrong Answer\n";
      return;
    }
  }
  std::cout << "Correct\n";
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