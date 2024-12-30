#include <bits/stdc++.h>

constexpr int N = 1 << 21 | 1145;
const double pi = acos(-1);

class complex {
private:
  double x;
  double y;

public:
  complex(double x = 0.0, double y = 0.0) : x(x), y(y) {}

  complex operator+(const complex &other) const {
    return complex(x + other.x, y + other.y);
  }

  complex operator-(const complex &other) const {
    return complex(x - other.x, y - other.y);
  }

  complex operator*(const complex &other) const {
    return complex(x * other.x - y * other.y, x * other.y + y * other.x);
  }

  constexpr double real() const {
    return x;
  }
  constexpr double imag() const {
    return y;
  }
} f[N], sav[N], g[N];

void fft(complex *f, int len, int opt) {
  if (len == 1) return;
  int mid = len >> 1;
  for (int i = 0; i < len; i++) {
    sav[i] = f[i];
  }
  complex *fl = f, *fr = f + mid;
  for (int i = 0; i < mid; i++) {
    fl[i] = sav[i << 1];
    fr[i] = sav[i << 1 | 1];
  }
  fft(fl, mid, opt);
  fft(fr, mid, opt);
  complex t(cos(2 * pi / len), sin(2 * pi / len) * opt);
  complex buf(1, 0);
  for (int i = 0; i < mid; i++) {
    sav[i] = fl[i] + buf * fr[i];
    sav[i + mid] = fl[i] - buf * fr[i];
    buf = buf * t;
  }
  for (int i = 0; i < len; i++) {
    f[i] = sav[i];
  }
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  std::cin >> n >> m;
  for (int i = 0; i <= n; i++) {
    int x;
    std::cin >> x;
    f[i] = complex(x, 0);
  }
  for (int i = 0; i <= m; i++) {
    int x;
    std::cin >> x;
    g[i] = complex(x, 0);
  }
  int len = n + m + 2, lim = 1;
  while (lim < len) lim <<= 1;
  fft(f, lim, 1);
  fft(g, lim, 1);
  for (int i = 0; i < lim; i++) {
    f[i] = f[i] * g[i];
  }
  fft(f, lim, -1);
  for (int i = 0; i <= n + m; i++) {
    std::cout << int(f[i].real() / lim + 0.5) << ' ';
  }
  std::cout << '\n';
  return 0;
}