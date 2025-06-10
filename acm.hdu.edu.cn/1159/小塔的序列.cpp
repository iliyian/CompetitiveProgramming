#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include <ext/pb_ds/hash_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;

// #define DEBUG 1  // 调试开关
struct IO {
#define MAXSIZE (1 << 23)
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

#define int long long

std::mt19937_64 rd(std::random_device{}());
constexpr int N = 1e6;
int vis[N + 1] {}, minp[N + 1] {};
std::vector<int> pri;
// int a[N + 1], s[N + 1] {};

using u64 = unsigned long long;

u64 val[N + 1], xval[N + 1];

void solve() {
  int n;
  // std::cin >> n;
  io.read(n);
  std::vector<int> a(n + 1);
  std::vector<u64> s(n + 1);
  // s[0] = 0;
  std::map<int, int> mp;
  // std::unordered_map<int, int> mp;
  // gp_hash_table<u64, int> mp;
  mp[0] = 0;
  for (int i = 1; i <= n; i++) {
    io.read(a[i]);
    // std::cin >> a[i];
    s[i] = s[i - 1] ^ xval[a[i]];
  }
  int ansl = -1, ansr = -1, ans = 0;
  for (int i = 1; i <= n; i++) {
    if (mp.find(s[i]) != mp.end()) {
      int x = mp[s[i]];
      if (i - x > ans) {
        ansl = x + 1, ans = i - x, ansr = i;
      }
    } else {
      mp[s[i]] = i;
    }
  }
  // std::cout << ansl << ' ' << ansr << '\n';
  io.write(ansl);
  io.push(' ');
  io.write(ansr);
  io.push('\n');
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  for (int i = 2; i <= N; i++) {
    if (!vis[i]) {
      pri.push_back(i);
      val[i] = rd();
      minp[i] = i;
    }
    for (int p : pri) {
      if (i * p > N) break;
      vis[i * p] = 1;
      minp[i * p] = p;
      if (i % p == 0) break;
    }
  }
  for (int i = 1; i <= N; i++) {
    int x = 0, t = i;
    while (t > 1) {
      x ^= val[minp[t]];
      t /= minp[t];
    }
    xval[i] = x;
  }

  int t = 1;
  // std::cin >> t;
  io.read(t);

  while (t--) {
    solve();
  }

  return 0;
}