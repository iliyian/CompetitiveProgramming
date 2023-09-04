#include <bits/stdc++.h>
#define N 2100000
using namespace std;

const double pi = acos(-1);

complex<double> a[N], b[N];

int rev[N], ans[N];

void init(complex<double> x[], int len) {
  for (int i = 0; i < len; i++) {
    rev[i] = rev[i >> 1] >> 1;
    if (i & 1) {
      rev[i] |= len >> 1;
    }
  }
  for (int i = 0; i < len; i++)
    if (i < rev[i])
      swap(x[i], x[rev[i]]);
}

void fft(complex<double> x[], int len, int f) {
  init(x, len);
  for (int i = 2; i <= len; i <<= 1) {
    complex<double> wn(cos(2 * pi / i), sin(2 * f * pi / i));
    for (int j = 0; j < len; j += i) {
      complex<double> w(1, 0);
      for (int k = j; k < j + i / 2; k++) {
        complex<double> u = x[k];
        complex<double> t = w * x[k + i / 2];
        x[k] = u + t;
        x[k + i / 2] = u - t;
        w *= wn;
      }
    }
  }
  if (f == -1) {
    for (int i = 0; i < len; i++)
      x[i] /= len;
  }
}

void change(const string &str, int len, complex<double> a[]) {
  for (int i = 0; i < str.size(); i++)
    a[i] = complex<double>(*(str.end() - 1 - i) - '0', 0);
  for (int i = str.size(); i < len; i++)
    a[i] = complex<double>(0, 0);
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  string stra, strb;
  cin >> stra >> strb;
  int maxlen = max(stra.size(), strb.size());
  int len = 1;
  while (len < 2 * maxlen - 1) len <<= 1;

  change(stra, len, a);
  change(strb, len, b);

  fft(a, len, 1);
  fft(b, len, 1);
  for (int i = 0; i < len; i++)
    a[i] *= b[i];
  fft(a, len, -1);

  memset(ans, 0, sizeof(ans));
  for (int i = 0; i < len; i++) {
    ans[i] += int(a[i].real() + 0.5);
    ans[i + 1] += ans[i] / 10;
    ans[i] %= 10;
  }
  while (ans[len] >= 10) {
    ans[len + 1] = ans[len] / 10;
    ans[len++] %= 10;
  }
  while (!ans[len] && len > 0) len--;

  for (int i = len; i >= 0; i--)
    cout << char(ans[i] + '0');
  return 0;
}