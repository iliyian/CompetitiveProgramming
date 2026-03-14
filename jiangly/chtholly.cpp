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
 * @Author : iliyian
 * @File   : C_Willem_Chtholly_and_Seniorious.cpp
 * @Time   : 2025-10-21 04:30:02
 * ==============================================================================
*/

#include <bits/stdc++.h>
#define int long long
  
struct Node {
  int l, r;
  mutable int v;
  Node(int l, int r = 0, int v = 0) : l(l), r(r), v(v) {}
  bool operator<(const Node &b) const { return l < b.l; }
};

std::set<Node> s;

auto split(int pos) {
  auto it = s.lower_bound(Node(pos));
  if (it != s.end() && it->l == pos) {
    return it;
  }
  it--;
  if (it->r < pos)
    return s.end();
  int l = it->l, r = it->r, v = it->v;
  s.erase(it);
  s.insert(Node(l, pos - 1, v));
  return s.insert(Node(pos, r, v)).first;
}

int n, m, seed, vmax;
int rnd() {
  int ret = seed;
  seed = (seed * 7 + 13) % 1000000007;
  return ret;
}

void assign(int l, int r, int x) {
  auto itr = split(r + 1), itl = split(l);
  s.erase(itl, itr);
  s.insert(Node(l, r, x));
}

void add(int l, int r, int x) {
  auto itr = split(r + 1), itl = split(l);
  for (auto it = itl; it != itr; it++) {
    it->v += x;
  }
}

int kth(int l, int r, int k) {
  std::vector<std::pair<int, int>> v;
  auto itr = split(r + 1), itl = split(l);
  for (auto it = itl; it != itr; it++) {
    v.push_back({it->v, it->r - it->l + 1});
  }
  std::ranges::sort(v);
  int tot = 0;
  for (auto [val, len] : v) {
    if (len + tot >= k) {
      return val;
    }
    tot += len;
  }
}

int qpow(int a, int b, int y) {
  int ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % y;
    a = a * a % y;
    b >>= 1;
  }
  return ans;
} 

int calP(int l, int r, int x, int y) {
  auto itr = split(r + 1), itl = split(l);
  int ans = 0;
  for (auto it = itl; it != itr; it++) {
    ans += qpow(it->v % y, x, y) * (it->r - it->l + 1) % y;
    ans %= y;
  }
  return ans;
}

void solve() {
  std::cin >> n >> m >> seed >> vmax;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    a[i] = rnd() % vmax + 1;
    // std::cerr << a[i] << ' ';
    s.insert(Node(i, i, a[i]));
  }
  // std::cerr << '\n';
  for (int i = 1; i <= m; i++) {
    int op = (rnd() % 4) + 1;
    int l = (rnd() % n) + 1;
    int r = (rnd() % n) + 1;
    if (l > r)
      std::swap(l, r);
    int x, y;
    if (op == 3)
      x = (rnd() % (r - l + 1)) + 1;
    else
      x = (rnd() % vmax) + 1;
    if (op == 4)
      y = (rnd() % vmax) + 1;
    // std::cerr << op << ' ' << l << ' ' << r << ' ' << x << ' ' << y << '\n';
    if (op == 1) {
      add(l, r, x);
    }
    if (op == 2) {
      assign(l, r, x);
    }
    if (op == 3) {
      std::cout << kth(l, r, x) << '\n';
    }
    if (op == 4) {
      std::cout << calP(l, r, x, y) << '\n';
    }
  }
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