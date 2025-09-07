#include <bits/stdc++.h>
#define int long long

int ans0[201][2] {};
constexpr int mod = 1e9 + 7;
int calc0(int x, int p) {
  if (x < 0) return 1;
  if (x == 1) return 5;
  if (x % 2 == 0) return 0;
  if (ans0[x][p]) return ans0[x][p];
  return ans0[x][p] = calc0(x - 2, p ^ 1) * 5 % mod;
}

int work(std::string &s) {
  if (s == "0") return 0;
  if (s.size() == 1) {
    return s.front() - '0';
  }
  int len = s.size();
  int ans = 0;
  // for (int i = 0; i < len; i++) {
  //   x[i] = std::min(x[i], x[len - i - 1]);
  // }
  s = '#' + s;
  bool f = true;
  std::string x(1, '#');
  for (int i = 1; i <= len; i++) {
    if (i <= len - i + 1) {
      if (i == 1) {
        x.push_back(s[i]);
      } else {
        if (x[i - 1] % 2 != s[i] % 2) {
          x.push_back(s[i]);
        } else {
          if (s[i] > '0') {
            x.push_back(s[i] - 1);
          } else {
            f = false;
            break;
          }
        }
      }
    } else {
      x.push_back(x[len - i + 1]);
    }
  }
  int i = 1;
  if (f) {
    while (i <= len && x[i] == s[i]) i++;
    if (i <= len && x[i] > s[i]) f = false;
  }
  // std::cerr << f << ' ' << x << '\n';
  if (len % 2 == 0) f = false;
  ans += f;
  for (int i = 1; i <= (len % 2 ? len - 2 : len - 1); i += 2) {
    ans += 4 * calc0(i - 2, 1) % mod;
    ans %= mod;
    ans += 5 * calc0(i - 2, 0) % mod;
    ans %= mod;
  }
  std::cerr << f << '\n';
  if (len % 2 == 1) {
    int y = (s[1] - '0') & 1;
    for (int i = 1; i <= len - i + 1; i++) {
      // int x = std::min(s[i], s[len - i + 1]) - '0';
      int x = s[i] - '0';
      for (int j = (i == 1 ? 1 : y); j < x; j += (i == 1 ? 1 : 2)) {
        ans += calc0(len - i * 2, j & 1 ^ 1);
        ans %= mod;
      }
      y ^= 1;
      if (i > 1 && s[i] % 2 == s[i - 1] % 2) {
        ans = (ans + mod - 1) % mod;
        break;
      }
      // if (s[len - i + 1] < s[i]) {
      //   break;
      // }
    }
  }
  return ans;
}

void solve() {
  std::string l, r;
  std::cin >> l >> r;
  if (l == "1") {
    l = "0";
  } else {
    l.back() -= 1;
    int x = l.size() - 1;
    while (l[x] < '0') {
      l[x - 1]--;
      l[x] += 10;
      x--;
    }
  }
  std::cout << (work(r) - work(l) + mod) % mod << '\n';
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}