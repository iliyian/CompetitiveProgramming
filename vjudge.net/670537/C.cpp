// date: 2024-11-12 18:40:32
// tag: 字符串

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

  int n, k;
  std::cin >> n >> k;
  std::vector<int> a(n + 1), p(n + 1);
  p[0] = 1;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    p[i] = p[i - 1] * base % P;
  }

  std::vector<int> h(n + 1);
  for (int i = 1; i <= n; i++) {
    h[i] = h[i - 1] * base % P + a[i];
    h[i] %= P;
  }

  auto check = [&](int mid) {
    std::map<int, int> cnt;
    for (int i = 1; i + mid - 1 <= n; i++) {
      int hash = (h[i + mid - 1] - h[i - 1] * p[mid] % P + P) % P;
      cnt[hash]++;
    }
    int mx = 0;
    for (auto [k, v] : cnt) {
      mx = std::max(mx, v);
    }
    return mx >= k;
  };

  int l = 1, r = n, ans = -1;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (check(mid)) l = mid + 1, ans = mid;
    else r = mid - 1;
  }
  std::cout << ans << '\n';

  return 0;
}