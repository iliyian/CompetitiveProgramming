// date: 2024-08-28 17:42:38
// tag: 这玩意tm的怎么写啊

#include <bits/stdc++.h>
// using namespace std;

typedef std::chrono::duration<double, std::milli> Dur;

std::mt19937 rd(std::random_device{}());

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
#if DEBUG // 调试，可显示字符
    return getchar();
#endif
    if (p1 == p2)
      p2 = (p1 = buf) + fread(buf, 1, MAXSIZE, stdin);
    return p1 == p2 ? ' ' : *p1++;
  }

  bool blank(char ch) {
    return ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t';
  }

  template <class T> void read(T &x) {
    double tmp = 1;
    bool sign = 0;
    x = 0;
    char ch = gc();
    for (; !isdigit(ch); ch = gc())
      if (ch == '-')
        sign = 1;
    for (; isdigit(ch); ch = gc())
      x = x * 10 + (ch - '0');
    if (ch == '.')
      for (ch = gc(); isdigit(ch); ch = gc())
        tmp /= 10.0, x += tmp * (ch - '0');
    if (sign)
      x = -x;
  }

  void read(char *s) {
    char ch = gc();
    for (; blank(ch); ch = gc())
      ;
    for (; !blank(ch); ch = gc())
      *s++ = ch;
    *s = 0;
  }

  void read(char &c) {
    for (c = gc(); blank(c); c = gc())
      ;
  }

  void push(const char &c) {
#if DEBUG // 调试，可显示字符
    putchar(c);
#else
    if (pp - pbuf == MAXSIZE)
      fwrite(pbuf, 1, MAXSIZE, stdout), pp = pbuf;
    *pp++ = c;
#endif
  }

  template <class T> void write(T x) {
    if (x < 0)
      x = -x, push('-'); // 负数输出
    static T sta[35];
    T top = 0;
    do {
      sta[top++] = x % 10, x /= 10;
    } while (x);
    while (top)
      push(sta[--top] + '0');
  }

  template <class T> void write(T x, char lastChar) {
    write(x), push(lastChar);
  }
} io;

int32_t main() {
#ifndef W
  std::cin.tie(nullptr)->sync_with_stdio(false);
#endif

  std::ofstream gen("test_io.in");
  int n = 1e5;

  for (int i = 1; i <= n; i++) {
    gen << rd() << ' ';
    if (i % 10 == 0) {
      gen << '\n';
    }
  }
  gen.flush();

  freopen("test_io.in", "r", stdin);
  freopen("test_io.out", "w", stdout);

#ifdef W
  Dur wsync(0);
  auto begin = std::chrono::high_resolution_clock::now();
  int x;
  for (int i = 1; i <= n; i++) {
    std::cin >> x;
    x /= 2;
    std::cout << x << ' ';
  }
  std::cout << '\n';
  auto end = std::chrono::high_resolution_clock::now();
  wsync = end - begin;

  std::cout << "with sync and tie, std::iostream uses " << wsync << '\n';
  std::cout.flush();
#endif

#ifdef OPT
  Dur op;
  int x = 0;
  auto begin = std::chrono::high_resolution_clock::now();
  for (int i = 1; i <= n; i++) {
    io.read(x);
    x /= 2;
    io.write(x);
    io.write(' ');
  }
  io.write('\n');
  auto end = std::chrono::high_resolution_clock::now();
  op = end - begin;
  std::cout << "optimized io uses " << op << '\n';
#endif

#ifdef WO
  int x;
  Dur wosync(0);
  auto begin = std::chrono::high_resolution_clock::now();
  for (int i = 1; i <= n; i++) {
    std::cin >> x;
    x /= 2;
    std::cout << x << std::endl;
  }
  std::cout << '\n';
  auto end = std::chrono::high_resolution_clock::now();
  wosync = end - begin;
  std::cout << "without sync and tie, std::iostream uses " << wsync << '\n';
#endif

  return 0;
}