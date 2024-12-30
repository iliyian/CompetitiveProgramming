#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct complex {
  double x, y;
  complex operator+(const complex &a) const {
    return (complex){x + a.x, y + a.y};
  }
  complex operator-(const complex &a) const {
    return (complex){x - a.x, y - a.y};
  }
  complex operator*(const complex &a) const {
    return (complex){x * a.x - y * a.y, x * a.y + y * a.x};
  }
  complex operator*(const double a) const { return (complex){x * a, y * a}; }
};
#define BUF 0x400000
#define LIGHTSPEED
namespace LightSpeedIO {
char ibuf[BUF], obuf[BUF], *li, *ri, *lo = obuf, *ro = obuf + BUF, st[100],
                                     *tp = st;
inline int gc() {
#ifndef LIGHTSPEED
  return getchar();
#endif

  if (li == ri) {
    li = ibuf;
    ri = li + fread(li, 1, BUF, stdin);
  }

  return *li++;
}
inline int read() {
  int x = 0, ch = gc();

  for (; ch < '0' || ch > '9'; ch = gc())
    ;

  for (; ch >= '0' && ch <= '9'; ch = gc())
    x = x * 10 + (ch ^ 48);

  return x;
}
inline void flush() {
  fwrite(obuf, 1, lo - obuf, stdout);
  lo = obuf;
}
inline void pc(int ch) {
  if (lo == ro)
    flush();

  *lo++ = ch;
}
inline void write(int x) {
  if (!x) {
    pc('0');
    return;
  }

  while (x) {
    *tp++ = x % 10;
    x /= 10;
  }

  while (tp > st)
    pc(*--tp + '0');
}
}; // namespace LightSpeedIO
using LightSpeedIO::flush;
using LightSpeedIO::gc;
using LightSpeedIO::pc;
using LightSpeedIO::read;
using LightSpeedIO::write;

#define N (1 << 20 | 4399)
#define swap(a, b, t) (t = a, a = b, b = t)

const double PI = acos(-1), PI2 = 2 * PI;
complex omega[N << 1];
int limit(int n) {
  int ans = 0;

  for (int i = 1; i < n; i <<= 1)
    ans++;

  return ans;
}
void init(int lim) {
  int n = 1 << lim;

  for (int i = 1; i <= n; i <<= 1)
    for (int j = 0; j < i; j++) {
      double deg = PI2 * j / i;
      omega[i | j] = (complex){cos(deg), sin(deg)};
    }
}
void butterfly(complex *const a, const int m, const int k) {
  complex *const b = a + m;
  complex *const omg = omega + k;

  for (register int i = 0; i < m; i++) {
    complex &x = a[i], &y = b[i];
    const complex tmp = y * omg[i];
    y = x - tmp;
    x = x + tmp;
  }
}
void FFT(complex *a, int lim, int flag) {
  const int n = 1 << lim, size = 1 << (lim < 16 ? lim : 16);
  complex tmp;

  for (int i = 0, j = 0; i < n; i++) {
    if (i < j)
      swap(a[i], a[j], tmp);

    for (int l = n >> 1; (j ^= l) < l; l >>= 1)
      ;
  }

  for (int i = 0; i < n; i += size)
    for (int m = 1, k = 2; m < size; m <<= 1, k <<= 1)
      for (int j = 0; j < size; j += k)
        butterfly(a + i + j, m, k);

  for (int m = size, k = size << 1; m < n; m <<= 1, k <<= 1)
    for (int j = 0; j < n; j += k)
      butterfly(a + j, m, k);

  if (!~flag) {
    for (int i = 1; i <= (n >> 1); i++)
      swap(a[i], a[n - i], tmp);

    for (int i = 0; i < n; i++)
      a[i] = a[i] * (1.0 / n);
  }
}
void FFT(complex *a, complex *b, int lim, int flag) {
  int n = 1 << lim;
  static complex p[N];

  if (~flag) {
    for (int i = 0; i < n; i++)
      p[i] = (complex){a[i].x, b[i].x};

    FFT(p, lim, 1);

    p[n] = p[0];

    for (int i = 0; i < n; i++) {
      const double x = p[i].x, y = p[i].y;
      const double z = p[n - i].x, w = -p[n - i].y;
      a[i] = (complex){(x + z) * .5, (y + w) * .5};
      b[i] = (complex){(y - w) * .5, (z - x) * .5};
    }
  } else {
    for (int i = 0; i < n; i++)
      p[i] = (complex){a[i].x - b[i].y, a[i].y + b[i].x};

    FFT(p, lim, -1);

    for (int i = 0; i < n; i++)
      a[i].x = p[i].x, a[i].y = p[i].y;
  }
}

#define DIGIT 4
#define M 10000

struct BigInt {
  int n;
  vector<int> a;
  BigInt() : a(2) { n = 1; }
  BigInt(int x) : a(3) {
    a[1] = x % M;
    a[2] = x / M;
    n = 1 + (bool)a[2];
  }
};
void read(BigInt &a) {
  static char buf[N * DIGIT];
  scanf(" %[0-9]", buf);
  a.n = 0;
  a.a.resize(1);

  for (int i = strlen(buf) - 1, j = M; i >= 0; i--, j *= 10) {
    if (j == M)
      a.a.push_back(0), a.n++, j = 1;

    a.a[a.n] += j * (buf[i] ^ 48);
  }
}
void write(const BigInt &a) {
  printf("%d", a.a[a.n]);

  for (int i = a.n - 1; i >= 1; i--)
    printf("%0*d", DIGIT, a.a[i]);
}

int cmp(const BigInt &a, const BigInt &b) {
  if (a.n != b.n)
    return a.n < b.n ? -1 : 1;

  for (int i = a.n; i >= 1; i--)
    if (a.a[i] != b.a[i])
      return a.a[i] < b.a[i] ? -1 : 1;

  return 0;
}
bool less(const BigInt &a, const BigInt &b) {
  if (a.n != b.n)
    return a.n < b.n;

  for (int i = a.n; i >= 1; i--)
    if (a.a[i] != b.a[i])
      return a.a[i] < b.a[i];

  return 0;
}
void add(BigInt &ans, const BigInt &a, const BigInt &b) {
  ans.n = max(a.n, b.n);
  ans.a.clear();
  ans.a.resize(ans.n + 2, 0);

  for (int i = 1; i <= ans.n; i++)
    if ((ans.a[i] += (i > a.n ? 0 : a.a[i]) + (i > b.n ? 0 : b.a[i])) >= M)
      ans.a[i] -= M, ans.a[i + 1] = 1;

  if (ans.a[ans.n + 1])
    ans.n++;
}
void sub(BigInt &ans, const BigInt &a, const BigInt &b) {
  ans.n = a.n;
  ans.a.clear();
  ans.a.resize(ans.n + 1);

  for (int i = 1; i <= ans.n; i++)
    if ((ans.a[i] += (i > a.n ? 0 : a.a[i]) - (i > b.n ? 0 : b.a[i])) < 0)
      ans.a[i] += M, ans.a[i + 1] = -1;

  while (ans.n > 1 && !ans.a[ans.n])
    ans.n--;

  ans.a.resize(ans.n + 1);
}
void mul(BigInt &ans, const BigInt &a, const BigInt &b) {
  int lim = limit(a.n + b.n - 1);
  static complex f[N], g[N];
  static long long buf[N];

  for (int i = 1; i <= (1 << lim); i++)
    f[i - 1].x = (i > a.n ? 0 : a.a[i]), g[i - 1].x = (i > b.n ? 0 : b.a[i]);

  init(lim);
  FFT(f, g, lim, 1);

  for (int i = 0; i < (1 << lim); i++)
    f[i] = f[i] * g[i];

  FFT(f, lim, -1);
  ans.n = a.n + b.n - 1;
  buf[1] = buf[ans.n + 1] = 0;

  for (int i = 1; i <= ans.n; i++) {
    buf[i + 1] = (buf[i] += f[i - 1].x + .5) / M;
    buf[i] %= M;
  }

  ans.a.resize(ans.n + 2);

  for (int i = 1; i <= ans.n + 1; i++)
    ans.a[i] = buf[i];

  if (ans.a[ans.n + 1])
    ans.n++;
}
void div_force(BigInt &ans, const BigInt &a, const BigInt &b) {
  BigInt x = b, y = 1, t;
  stack<BigInt> s1, s2;

  for (; cmp(x, a) <= 0; add(t, x, x), x = t, add(t, y, y), y = t)
    s1.push(x), s2.push(y);

  x = a, ans = 0;

  for (; !s1.empty(); s1.pop(), s2.pop())
    if (cmp(s1.top(), x) <= 0) {
      sub(t, x, s1.top()), x = t;
      add(t, ans, s2.top()), ans = t;
    }
}
void shift(BigInt &a, int shift) {
  if (shift >= 0) {
    a.a.resize(a.n + shift + 1);

    for (int i = a.n; i >= 1; i--)
      a.a[i + shift] = a.a[i];

    for (int i = 1; i <= shift; i++)
      a.a[i] = 0;

    a.n += shift;
  } else {
    shift = -shift;

    for (int i = 1; i <= a.n - shift; i++)
      a.a[i] = a.a[i + shift];

    a.n -= shift;
    a.a.resize(a.n + 1);
  }
}
void add1(BigInt &a) {
  a.a.resize(a.n + 2);

  for (int i = 1;; i++) {
    if (a.a[i] != M - 1) {
      a.a[i]++;
      break;
    }

    a.a[i] = 0;
  }

  if (a.a[a.n + 1])
    a.n++;
}
void sub1(BigInt &a) {
  for (int i = 1;; i++)
    if (!a.a[i]) {
      a.a[i] = M - 1;
    } else {
      a.a[i]--;
      break;
    }

  while (a.n > 1 && !a.a[a.n])
    a.n--;

  a.a.resize(a.n + 1);
}
void inv(BigInt &ans, const BigInt &a) {
  if (a.n <= 10) {
    BigInt b;
    b.a.resize((b.n = a.n * 2 + 1) + 1);
    b.a[b.n] = 1;
    div_force(ans, b, a);
    return;
  }

  BigInt b, c, d;
  int m = a.n, k = (a.n + 5) >> 1;
  b.n = k;
  b.a.resize(b.n + 1);

  for (int i = b.n, j = a.n; i; i--, j--)
    b.a[i] = a.a[j];

  inv(c, b);
  mul(b, a, c);
  mul(d, b, c);
  shift(d, -2 * k);
  add(b, c, c);
  shift(b, m - k);
  sub(ans, b, d);
  sub1(ans);
  d.a.clear(), d.a.resize((d.n = m * 2 + 1) + 1), d.a[d.n] = 1;
  mul(b, ans, a);
  sub(c, d, b);

  if (cmp(c, a) >= 0)
    add1(ans);
}
void div(BigInt &ans, const BigInt &a, const BigInt &b) {
  if (a.n < b.n)
    return void(ans = 0);

  BigInt x = a, y = b, z;
  int n = x.n, m = y.n;

  if (n > (m << 1)) {
    shift(x, n - (m << 1));
    shift(y, n - (m << 1));
    m = n - m;
    n = m << 1;
  }

  inv(z, y);
  mul(y, x, z);
  shift(y, -(m * 2));
  mul(x, b, y);
  sub(z, a, x);

  if (cmp(z, b) >= 0)
    add1(y);

  ans = y;
}

int main() {
  BigInt a, b, c;
  read(a);
  read(b);
  div(c, a, b);
  write(c);
}