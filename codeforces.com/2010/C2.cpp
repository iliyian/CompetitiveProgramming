// date: 2024-08-29 20:16:58
// tag: 莫名自然溢出的哈希被卡碰撞了？虽然正解类似kmp的双指针

#include <bits/stdc++.h>
#define int long long
// using namespace std;

constexpr int base = 2333;
constexpr int mod1 = 1e9 + 7, mod2 = 1e9 + 9;

int qpow(int a, int b, int mod) {
  int ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return ans;
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("C.in", "r", stdin);
  freopen("C2.out", "w", stdout);

  std::string str;
  std::cin >> str;
  int n = str.size();
  std::vector<int> h1(n), h2(n);
  h1[0] = h2[0] = str[0] - 'a' + 1;
  for (int i = 1; i < n; i++) {
    h1[i] = h1[i - 1] * base % mod1 + str[i] - 'a' + 1;
    h1[i] %= mod1;
    h2[i] = h2[i - 1] * base % mod2 + str[i] - 'a' + 1;
    h2[i] %= mod2;
  }
  int H1 = h1.back(), H2 = h2.back();
  for (int i = 1; i < n - 1; i++) {
    int r = n - i - 1;
    if (r < i) break;
    H1 -= (str[i - 1] - 'a' + 1) * qpow(base, n - i, mod1) % mod1;
    H1 = (H1 % mod1 + mod1) % mod1;
    H2 -= (str[i - 1] - 'a' + 1) * qpow(base, n - i, mod2) % mod2;
    H2 = (H2 % mod2 + mod2) % mod2;
    if (h1[r] == H1 && h2[r] == H2) {
      std::cout << "YES\n";
      std::cout << str.substr(0, r + 1) << '\n';
      return 0;
    }
  }
  std::cout << "NO\n";


  return 0;
}