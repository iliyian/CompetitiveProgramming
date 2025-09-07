#include <bits/stdc++.h>
#define int long long

constexpr int N = 1e6;
std::vector<int> primes, minp;

void sieve(int n) {
  minp.assign(n + 1, 0);
  for (int i = 2; i <= n; i++) {
    if (!minp[i]) {
      minp[i] = i;
      primes.push_back(i);
    }
    for (int p : primes) {
      if (i * p > n) break;
      minp[i * p] = p;
      if (i % p == 0) break;
    }
  }
}

int qpow(int a, int b) {
  int ans = 1;
  while (b) {
    if (b & 1) ans = ans * a;
    a = a * a;
    b >>= 1;
  }
  return ans;
}

bool check(std::set<int> &s) {
  auto check = [&](int x) {
    int y = sqrtl(x);
    return y * y == x;
  };
  std::vector<int> v;
  for (auto i : s) v.push_back(i);
  for (int i = 0; i < v.size(); i++) {
    for (int j = 0; j < v.size(); j++) {
      for (int k = 0; k < v.size(); k++) {
        if (check(v[i] * v[j] * v[k])) {
          std::cout << v[i] << ' ' << v[j] << ' ' << v[k] << '\n';
          return false;
        }
      }
    }
  }
  return true;
}

void solve() {
  int n;
  std::cin >> n;
  // std::vector<int> ans;
  std::set<int> s;

  int cur = 0;
  for (int i = 1; i <= n; i++) {
    int val = 0, x = i;
    while (x > 1) {
      val ^= 1;
      x /= minp[x];
    }
    if (val) {
      std::cout << i << ' ';
      // s.insert(i);
      cur++;
      if (cur == n / 2) {
        break;
      }
    }
  }
  std::cout << '\n';
  // std::cout << s.size() << '\n';
  // for (auto i : s) {
  //   std::cout << i << ' ';
  // }
  // std::cout << '\n';
  // std::cout << check(s) << '\n';

//   while (s.size() < n / 2) {
//     auto t = s;
//     int val = *t.begin();
//     t.erase(t.begin());
//     // if (minp[val] == val) {
// 
//       for (int i : s) {
//         if (i != val && minp[i] == i && i * val <= n) {
//           t.insert(i * val);
//         }
//       }
//     // }
//     s = t;
//   }
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  sieve(N);

//   auto check = [&](int x) {
//     int y = sqrtl(x);
//     return y * y == x;
//   };
// 
//   for (int n = 2; n <= 2; n += 2) {
//     // int n = 16;
//     // for (int i = 0; i < (1ll << n); i++) {
//     for (int i = (1ll << n) - 1; i >= 0; i--) {
//       if (__builtin_popcountll(i) != n / 2) continue;
//       std::vector<int> v;
//       for (int j = 0; j < n; j++) {
//         if (i >> j & 1) {
//           v.push_back(j + 1);
//         }
//       }
//       bool f = true;
//       for (int a = 0; a < n / 2; a++) {
//         for (int b = 0; b < n / 2; b++) {
//           for (int c = 0; c < n / 2; c++) {
//             if (check(v[a] * v[b] * v[c])) {
//               f = false;
//               goto end;
//             }
//           }
//         }
//       }
//       end:;
//       if (f) {
//         for (int i : v) {
//           std::cout << i << ' ';
//         }
//         std::cout << '\n';
//         break;
//       }
//     }
//   }

  // return 0;

  int t = 1;
  std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}