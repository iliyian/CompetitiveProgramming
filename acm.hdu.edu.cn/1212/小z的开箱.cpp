/*

LLLLLLLLLLL             IIIIIIIIIIYYYYYYY       YYYYYYYIIIIIIIIII               AAA               NNNNNNNN        NNNNNNNN
L:::::::::L             I::::::::IY:::::Y       Y:::::YI::::::::I              A:::A              N:::::::N       N::::::N
L:::::::::L             I::::::::IY:::::Y       Y:::::YI::::::::I             A:::::A             N::::::::N      N::::::N
LL:::::::LL             II::::::IIY::::::Y     Y::::::YII::::::II            A:::::::A            N:::::::::N     N::::::N
  L:::::L                 I::::I  YYY:::::Y   Y:::::YYY  I::::I             A:::::::::A           N::::::::::N    N::::::N
  L:::::L                 I::::I     Y:::::Y Y:::::Y     I::::I            A:::::A:::::A          N:::::::::::N   N::::::N
  L:::::L                 I::::I      Y:::::Y:::::Y      I::::I           A:::::A A:::::A         N:::::::N::::N  N::::::N
  L:::::L                 I::::I       Y:::::::::Y       I::::I          A:::::A   A:::::A        N::::::N N::::N N::::::N
  L:::::L                 I::::I        Y:::::::Y        I::::I         A:::::A     A:::::A       N::::::N  N::::N:::::::N
  L:::::L                 I::::I         Y:::::Y         I::::I        A:::::AAAAAAAAA:::::A      N::::::N   N:::::::::::N
  L:::::L                 I::::I         Y:::::Y         I::::I       A:::::::::::::::::::::A     N::::::N    N::::::::::N
  L:::::L         LLLLLL  I::::I         Y:::::Y         I::::I      A:::::AAAAAAAAAAAAA:::::A    N::::::N     N:::::::::N
LL:::::::LLLLLLLLL:::::LII::::::II       Y:::::Y       II::::::II   A:::::A             A:::::A   N::::::N      N::::::::N
L::::::::::::::::::::::LI::::::::I    YYYY:::::YYYY    I::::::::I  A:::::A               A:::::A  N::::::N       N:::::::N
L::::::::::::::::::::::LI::::::::I    Y:::::::::::Y    I::::::::I A:::::A                 A:::::A N::::::N        N::::::N
LLLLLLLLLLLLLLLLLLLLLLLLIIIIIIIIII    YYYYYYYYYYYYY    IIIIIIIIIIAAAAAAA                   AAAAAAANNNNNNNN         NNNNNNN

 * 
 * ==============================================================================
 * @Author  : iliyian
 * @File    : 小z的开箱.cpp
 * @Time    : 2026-03-13 20:01:50
 * @Comment : 
 * ==============================================================================
*/

#include <bits/stdc++.h>
#define int long long

std::vector<int> primes, vis;

void sieve(int n) {
  vis.assign(n + 1, 0);
  for (int i = 2; i <= n; i++) {
    if (!vis[i]) {
      primes.push_back(i);
    }
    for (int p : primes) {
      if (i * p > n) break;
      vis[i * p] = 1;
      if (i % p == 0) break;
    }
  }
}

int solve(int n, std::vector<int> a) {
  int ans = 0;
  for (int i = 1; i <= n; i++) a.pop_back();
  for (int i = 1; i <= n; i++) {
    int now = 0;
    for (int j = 1, k = i; j <= n; j++, k = k % n + 1) {
      now = *std::prev(std::upper_bound(primes.begin(), primes.end(), now + a[k]));
    }
    ans = std::max(ans, now);
  }
  std::reverse(a.begin() + 1, a.end());
  for (int i = 1; i <= n; i++) {
    int now = 0;
    for (int j = 1, k = i; j <= n; j++, k = k % n + 1) {
      now = *std::prev(std::upper_bound(primes.begin(), primes.end(), now + a[k]));
    }
    ans = std::max(ans, now);
  }
  return ans;
}

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n * 2 + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    a[i + n] = a[i];
  }
  int log = std::__lg(n * 2 + 1);
  std::vector<std::vector<int>> mx(log + 1, std::vector<int>(n * 2 + 1));
  auto get = [&](int l, int r) {
    int len = std::__lg(r - l + 1);
    return std::max(mx[len][l], mx[len][r - (1 << len) + 1]);
  };
  
  int ans = 0;
  int _tot = 0;
  auto work = [&]() {
    for (int i = 1; i <= n * 2; i++) {
      mx[0][i] = a[i];
    }
    for (int i = 0; i < log; i++) {
      for (int j = 1; j + (1 << i) <= n * 2; j++) {
        mx[i + 1][j] = std::max(mx[i][j], mx[i][j + (1 << i)]);
      }
    }

    for (int i = 1; i <= n; i++) {
      int k = 0, p = i;
      while (primes[k] <= a[i]) k++;
      int now = primes[k - 1];
      ans = std::max(ans, now);
      for (int j = 1; j <= 35; j++) {
        while (primes[k] <= now) k++;
        now = primes[k - 1];
        ans = std::max(ans, now);
        int d = primes[k] - now;
        int l = p + 1, r = i + n - 1, nxt = -1;
        _tot++;
        while (l <= r) {
          int mid = (l + r) / 2;
          if (get(p + 1, mid) >= d) nxt = mid, r = mid - 1;
          else l = mid + 1;
        }
        if (nxt == -1) {
          break;
        } else {
          now += a[nxt];
          // now = *std::prev(std::upper_bound(primes.begin(), primes.end(), now + a[nxt]));
          // ans = std::max(ans, now);
          p = nxt;
        }
      }
    }
  };
  work();
  std::reverse(a.begin() + 1, a.end());
  work();
  // std::cerr << _tot << '\n';

  // int real = solve(n, a);
  // std::cout << real << ' ';
  // if (real != ans) {
  //   std::cout << n << '\n';
  //   for (auto i : a) {
  //     std::cerr << i << ' ';
  //   }
  //   std::cerr << '\n';
  //   assert(false);
  // }
  std::cout << ans << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  // auto start = std::chrono::high_resolution_clock::now();

  // freopen("d.in", "r", stdin);
  // freopen("d.out", "w", stdout);

  sieve(1000);
  primes.insert(primes.begin(), 0);

  int prv = 0;
  for (auto p : primes) {
    if (p == 127) {
      break;
    }
    // req.push_back(p - prv);
    prv = p;
  }

  int t = 1;
  std::cin >> t;

  while (t--) {
    solve();
  }

  // auto end = std::chrono::high_resolution_clock::now();
  // std::cerr << std::chrono::duration<double, std::milli>(end - start) << '\n';

  return 0;
}
