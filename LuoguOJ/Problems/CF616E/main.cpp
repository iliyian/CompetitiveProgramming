// date: 2024-03-03 19:24:41
// tag: 同P2261

#include <bits/stdc++.h>
#define int __int128_t
#define mod 1000000007
using namespace std;

void exgcd(int a, int b, int &x, int &y) {
  if (b == 0) {
    x = 1, y = 0;
    return;
  }
  exgcd(b, a % b, y, x);
  y -= a / b * x;
}

int read() {
  int x = 0;
  char ch = getchar();
  while (!isdigit(ch)) ch = getchar();
  while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
  return x;
}

void write(int x) {
  if (x >= 10) write(x / 10);
  putchar(x % 10 + '0');
}

istream& operator >> (istream& is, int &x) {
  x = read();
  return is;
}

ostream& operator << (ostream& os, const int &x) {
  write(x);
  return os;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  int t = 1;

  while (t--) {
    int n, m;
    cin >> n >> m;
    int ans = n * m;
    for (int l = 1, r; l <= m; l = r + 1) {
      int t = n / l;
      if (t == 0) break;
      else r = min(n / t, m);
      ans -= (r - l + 1) * (l + r) / 2 * t;
    }
    cout << signed(ans % mod) << '\n';
  }

  return 0;
}