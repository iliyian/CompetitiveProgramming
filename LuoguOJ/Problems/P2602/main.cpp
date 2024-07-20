// date: 2024-07-19 16:28:49
// tag: 数位dp

#include <bits/stdc++.h>
#define int long long
// using namespace std;

int qpow(int a, int b) {
  int ans = 1;
  while (b) {
    if (b & 1) ans = ans * a;
    a = a * a;
    b >>= 1;
  }
  return ans;
}

std::vector<int> f(14);
std::vector<int> solve(int x) {
  int t = x;
  std::vector<int> a;
  while (t) {
    a.push_back(t % 10);
    t /= 10;
  }
  std::vector<int> ans(10);
  for (int i = a.size() - 1; i >= 0; i--) {
    x -= qpow(10, i) * a[i];
    ans[a[i]] += x + 1;
    for (int j = 0; j < a[i]; j++) {
      ans[j] += qpow(10, i);
    }
    for (int j = 0; j < 10; j++) {
      ans[j] += f[i] * a[i];
    }
    ans[0] -= qpow(10, i);
  }
  return ans;
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int l, r;
  std::cin >> l >> r;

  for (int i = 1; i <= 13; i++) {
    f[i] = qpow(10, i - 1) + f[i - 1] * 10;
  }
  auto x = solve(r), y = solve(l - 1);
  for (int i = 0; i < 10; i++) {
    std::cout << x[i] - y[i] << ' ';
  }
  std::cout << '\n';

  // std::vector<int> ans(13);
  // for (int i = l; i <= r; i++) {
  //   int t = i;
  //   for (char ch : std::to_string(t)) {
  //     ans[ch - '0']++;
  //   }
  // }
  // for (int i = 0; i < 10; i++) {
  //   std::cout << ans[i] << ' ';
  // }

  return 0;
}