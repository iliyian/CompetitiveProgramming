#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, a, b;
  std::cin >> n >> a >> b;
  int m;
  std::cin >> m;
  int S = 0, tm = 0;
  std::vector<int> fail(n), fst(n);
  for (int i = 1; i <= m; i++) {
    int t;
    char c;
    std::string s;
    std::cin >> t >> c >> s;
    c -= 'A';
    // std::cerr << t << ' ' << c << ' ' << s << '\n';
    if (s == "ac") {
      if (S >> (int)c & 1 ^ 1) {
        S |= 1ll << c;
        tm += fail[c] * 20 + t;
      }
    } else if (s == "rj") {
      if (S >> (int)c & 1 ^ 1) {
        fail[(int)c]++;
      }
    } else {
      if (!fst[(int)c]) {
        fst[(int)c] = t;
      }
    }
  }
  std::vector<int> v;
  for (int i = 0; i < n; i++) {
    if (S >> i & 1 ^ 1) {
      if (fst[i]) {
        v.push_back(i);
      }
    }
  }
  std::sort(v.begin(), v.end(), [&](auto x, auto y) {
    return fst[x] + fail[x] * 20 < fst[y] + fail[y] * 20;
  });
  int p = __builtin_popcountll(S), q = tm;
  if (std::pair{p, -q} > std::pair{a, -b}) {
    std::cout << 0 << '\n';
    return;
  }
  for (int i = 0; i < v.size(); i++) {
    p++, q += fst[v[i]] + fail[v[i]] * 20;
    if (std::pair{p, -q} > std::pair{a, -b}) {
      std::cout << i + 1 << '\n';
      return;
    }
  }
  std::cout << -1 << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int t = 1;
  std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}