// date: 2024-08-09 12:17:11
// tag: 卡常版rmq

#include <bits/stdc++.h>
// #define int long long

namespace GenHelper {
unsigned z1, z2, z3, z4, b;
unsigned rand_() {
  b = ((z1 << 6) ^ z1) >> 13;
  z1 = ((z1 & 4294967294U) << 18) ^ b;
  b = ((z2 << 2) ^ z2) >> 27;
  z2 = ((z2 & 4294967288U) << 2) ^ b;
  b = ((z3 << 13) ^ z3) >> 21;
  z3 = ((z3 & 4294967280U) << 7) ^ b;
  b = ((z4 << 3) ^ z4) >> 12;
  z4 = ((z4 & 4294967168U) << 13) ^ b;
  return (z1 ^ z2 ^ z3 ^ z4);
}
} // namespace GenHelper
void srand(unsigned x) {
  using namespace GenHelper;
  z1 = x;
  z2 = (~x) ^ 0x233333333U;
  z3 = x ^ 0x1234598766U;
  z4 = (~x) + 51;
}
int read() {
  using namespace GenHelper;
  int a = rand_() & 32767;
  int b = rand_() & 32767;
  return a * 32768 + b;
}

int premx[5000][5000], sufmx[5000][5000];

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  auto start = std::chrono::high_resolution_clock::now();

  int n, m, s;
  std::cin >> n >> m >> s;
  srand(s);
  std::vector<int> a(n + 1), belong(n + 1);
  int block = std::sqrt(n);
  int tot = n / block;
  if (n % block)
    tot++;
  std::vector<std::vector<int>> Mx(22, std::vector<int>(tot + 1));
  // std::vector<std::vector<int>> premx(tot + 1, std::vector<int>(block + 1)),
  //     sufmx(tot + 1, std::vector<int>(block + 2));
  std::vector<int> L(tot + 1), R(tot + 1);
  for (int i = 1; i <= n; i++) {
    a[i] = read();
    belong[i] = (i + block - 1) / block;
    L[belong[i]] = belong[i] * block - block + 1;
    R[belong[i]] = std::min(n, L[belong[i]] + block - 1);

    Mx[0][belong[i]] = std::max(Mx[0][belong[i]], a[i]);

    int pos = i - L[belong[i]] + 1;
    premx[belong[i]][pos] = std::max(premx[belong[i]][pos - 1], a[i]);
  }
  for (int i = n; i >= 1; i--) {
    int pos = i - L[belong[i]] + 1;
    sufmx[belong[i]][pos] = std::max(sufmx[belong[i]][pos + 1], a[i]);
  }

  for (int i = 1; i <= 21; i++) {
    for (int j = 1; j + (1 << (i - 1)) <= tot; j++) {
      Mx[i][j] = std::max(Mx[i - 1][j], Mx[i - 1][j + (1 << (i - 1))]);
    }
  }

  auto query = [&](int l, int r) {
    if (l > r)
      return 0;
    int len = std::__lg(r - l + 1);
    return std::max(Mx[len][l], Mx[len][r - (1 << len) + 1]);
  };
  unsigned long long ans = 0;
  for (int i = 1; i <= m; i++) {
    int l = read() % n + 1, r = read() % n + 1;
    if (l > r)
      std::swap(l, r);
    if (belong[l] == belong[r]) {
      ans += *std::max_element(a.begin() + l, a.begin() + r + 1);
    } else {
      int mx = std::max(sufmx[belong[l]][l - L[belong[l]] + 1],
                        premx[belong[r]][r - L[belong[r]] + 1]);
                        // 谁能猜到几乎绝大部分时间都在上面这里?
      mx = std::max(mx, query(belong[l] + 1, belong[r] - 1));
      ans += mx;
    }
  }
  std::cout << ans << '\n';

  auto end = std::chrono::high_resolution_clock::now();
  std::cout << std::chrono::duration<double, std::milli>(end - start) << '\n';

  return 0;
}