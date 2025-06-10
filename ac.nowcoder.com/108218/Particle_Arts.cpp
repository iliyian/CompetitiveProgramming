#include <bits/stdc++.h>
#define int long long

std::mt19937 rd(std::random_device{}());

__int128 gcd(__int128 a, __int128 b) {
  return b ? gcd(b, a % b) : a;
}

void write(__int128 x) {
  if (!x) return;
  write(x / 10);
  std::cout << (int)x % 10;
}

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  int c[16] {};
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    for (int j = 0; j < 15; j++) {
      c[j] += a[i] >> j & 1;
    }
  }
  int sx2 = 0, s2x = 0;
  while (1) {
    int x = 0;
    for (int i = 0; i < 15; i++) {
      if (c[i]) {
        c[i]--;
        x ^= 1 << i;
      }
    }
    sx2 += x * x, s2x += x;
    if (!x) {
      break;
    }
  }
  s2x *= s2x;
  int p1 = sx2, q1 = n;
  int p2 = s2x, q2 = n * n;
  __int128 p = __int128(p1) * q2 - __int128(q1) * p2, q = __int128(q1) * q2;
  __int128 g = gcd(p, q);
  if (!p) {
    std::cout << "0/1\n";
    return;
  }
  // std::cout << p / g << "/" << q / g << '\n';
  write(p / g);
  std::cout << "/";
  write(q / g);
  std::cout << '\n';
  // std::cout << 1.0 * (p / g) / (q / g) << '\n';

//   double prvans = -1;
//   for (int t = 0; t < 1000; t++) {
//     auto x = rd() % (a.size() - 1) + 1, y = rd() % (a.size() - 1) + 1;
//     while (x == y) {
//       x = rd() % (a.size() - 1) + 1, y = rd() % (a.size() - 1) + 1;
//     }
//     a.push_back(a[x] & a[y]);
//     a.push_back(a[x] | a[y]);
//     a.erase(a.begin() + x);
//     if (y > x) y--;
//     a.erase(a.begin() + y);
// 
//     double ex2 = 0, e2x = 0;
//     for (int i = 1; i < a.size(); i++) {
//       ex2 += 1.0 * a[i] * a[i] / (a.size() - 1);
//       e2x += 1.0 * a[i] / (a.size() - 1);
//     }
//     e2x *= e2x;
//     double ans = ex2 - e2x;
//     // if (std::abs(ans - prvans) < 1e-9) {
//     //   break;
//     // }
//     prvans = ans;
//   }
  // std::cout << prvans << '\n';
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