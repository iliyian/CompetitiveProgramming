// date: 2024-11-12 18:40:32
// tag: 字符串哈希

#include <bits/stdc++.h>
#define int long long

std::mt19937_64 rd(std::random_device{}());

bool isprime(int n) {
  if (n <= 1) return false;
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}

int findPrime(int n) {
  while (!isprime(n)) {
    n++;
  }
  return n;
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  
  const int P = findPrime(rd() % (int)9e8 + (int)1e8);
  const int base = findPrime(rd() % (int)9e8 + (int)1e8);

  auto qpow = [&](int a, int b) {
    int ans = 1;
    while (b) {
      if (b & 1) ans = ans * a % P;
      a = a * a % P;
      b >>= 1;
    }
    return ans;
  };

  auto inv = [&](int x) {
    return qpow(x, P - 2);
  };

  int n;
  std::cin >> n;
  std::string ans;
  std::vector<int> h(1e6 + 10);
  std::vector<int> p(1e6 + 10);
  // int invbase = inv(base);
  // in[0] = p[0] = 1;
  p[0] = 1;
  for (int i = 1; i <= 1e6 + 9; i++) {
    // in[i] = in[i - 1] * invbase % P;
    p[i] = p[i - 1] * base % P;
  }
  int anslen = 0;
  for (int i = 1; i <= n; i++) {
    std::string s;
    std::cin >> s;
    int len = 0;
    std::vector<int> g(s.size());
    for (int j = 0; j < s.size(); j++) {
      g[j] = (j ? g[j - 1] : 0) * base % P + s[j];
      g[j] %= P;
    }
    for (int j = std::min(ans.size(), s.size()); j > 0; j--) {
      // for last j in ans and first j in s is same
      int hashs = g[j - 1];
      int hashans = (h[anslen - 1] - (anslen - j - 1 >= 0 ? h[anslen - j - 1] * p[j] % P : 0) + P) % P;
      if (hashs == hashans) {
        len = j;
        break;
      }
    }
    for (int j = len; j < s.size(); j++) {
      h[anslen] = (anslen ? h[anslen - 1] : 0) * base % P + s[j];
      h[anslen++] %= P;
      ans += s[j];
    }
  }

  std::cout << ans << '\n';

  return 0;
}