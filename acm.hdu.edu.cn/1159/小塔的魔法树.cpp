// date: 2025-05-17 16:26:53
// tag: 感觉是比较少见的按dfn序dp的

#include <bits/stdc++.h>

// #define DEBUG 1  // 调试开关
struct IO {
#define MAXSIZE (1 << 20)
#define isdigit(x) (x >= '0' && x <= '9')
  char buf[MAXSIZE], *p1, *p2;
  char pbuf[MAXSIZE], *pp;
#if DEBUG
#else
  IO() : p1(buf), p2(buf), pp(pbuf) {}

  ~IO() { fwrite(pbuf, 1, pp - pbuf, stdout); }
#endif
  char gc() {
#if DEBUG  // 调试，可显示字符
    return getchar();
#endif
    if (p1 == p2) p2 = (p1 = buf) + fread(buf, 1, MAXSIZE, stdin);
    return p1 == p2 ? ' ' : *p1++;
  }

  bool blank(char ch) {
    return ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t';
  }

  template <class T>
  void read(T &x) {
    double tmp = 1;
    bool sign = false;
    x = 0;
    char ch = gc();
    for (; !isdigit(ch); ch = gc())
      if (ch == '-') sign = 1;
    for (; isdigit(ch); ch = gc()) x = x * 10 + (ch - '0');
    if (ch == '.')
      for (ch = gc(); isdigit(ch); ch = gc())
        tmp /= 10.0, x += tmp * (ch - '0');
    if (sign) x = -x;
  }

  void read(char *s) {
    char ch = gc();
    for (; blank(ch); ch = gc());
    for (; !blank(ch); ch = gc()) *s++ = ch;
    *s = 0;
  }

  void read(char &c) { for (c = gc(); blank(c); c = gc()); }

  void push(const char &c) {
#if DEBUG  // 调试，可显示字符
    putchar(c);
#else
    if (pp - pbuf == MAXSIZE) fwrite(pbuf, 1, MAXSIZE, stdout), pp = pbuf;
    *pp++ = c;
#endif
  }

  template <class T>
  void write(T x) {
    if (x < 0) x = -x, push('-');  // 负数输出
    static T sta[35];
    T top = 0;
    do {
      sta[top++] = x % 10, x /= 10;
    } while (x);
    while (top) push(sta[--top] + '0');
  }

  template <class T>
  void write(T x, char lastChar) {
    write(x), push(lastChar);
  }
} io;

constexpr int mod = 1e9 + 7, N = 5e3;
int a[N + 1], rnk[N + 2], siz[N + 1], f[N + 2][N + 2];
std::vector<int> g[N + 1];

void solve() {
  int n, m;
  // std::cin >> n >> m;
  io.read(n), io.read(m);
  // std::vector<int> a(n + 2);
  for (int i = 1; i <= n; i++) {
    // std::cin >> a[i];
    io.read(a[i]);
    g[i].clear();
  }
  // std::vector<std::vector<int>> g(n + 1);
  for (int i = 1; i <= n - 1; i++) {
    int x, y;
    // std::cin >> x >> y;
    io.read(x), io.read(y);
    g[x].push_back(y);
    g[y].push_back(x);
  }
  // std::vector<int> dfn(n + 1), siz(n + 1), rnk(n + 2);
  int tot = 0;
  auto dfs = [&](auto self, int u, int p) -> void {
    rnk[++tot] = u;
    siz[u] = 1;
    for (int v : g[u]) {
      if (v != p) {
        self(self, v, u);
        siz[u] += siz[v];
      }
    }
  };
  rnk[n + 1] = n + 1;
  dfs(dfs, 1, 0);
  // std::vector<std::vector<int>> f(n + 2, std::vector<int>(m + 1));
  for (int u = 1; u <= n + 1; u++) {
    for (int i = 0; i <= m; i++) {
      f[u][i] = 0;
    }
  }
  f[1][0] = 1;
  for (int u = 1; u <= n; u++) {
    int v = rnk[u];
    for (int i = 0; i <= m; i++) {
      if (i >= a[v]) {
        auto &x = f[u + 1][i];
        x += f[u][i - a[v]];
        x %= mod;
        // f[rnk[dfn[u] + 1]][i] += f[u][i - a[u]];
      }
      auto &x = f[u + siz[v]][i];
      x += f[u][i];
      x %= mod;
      // f[rnk[dfn[u] + siz[u]]][i] += f[u][i];
    }
  }
  int ans = 0;
  for (int i = 0; i <= m; i++) {
    ans += f[n + 1][i];
    ans %= mod;
  }
  // std::cout << ans - 1 << '\n';
  io.write((ans + mod - 1) % mod, '\n');
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int t = 1;
  // std::cin >> t;
  io.read(t);

  while (t--) {
    solve();
  }

  return 0;
}