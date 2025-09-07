#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef pair<int, int> pr;
typedef vector<int> vi;
inline int rd() {
  int x = 0, y = 1;
  char c = getchar();
  for (; c < '0' || c > '9'; c = getchar())
    if (c == '-')
      y = -1;
  for (; c >= '0' && c <= '9'; c = getchar())
    x = (x << 1) + (x << 3) + (c ^ 48);
  return x * y;
}
int n, m, T, a[17], f[1 << 17], an;
string s;
int main() {
  ios::sync_with_stdio(false);
  for (cin >> T; T--;) {
    cin >> n >> s;
    an = 1e9;
    memset(f, 0, sizeof(f));
    for (int i = 0; i < 17; ++i)
      cin >> a[i];
    cin >> m;
    if (m & 1)
      ++m;
    for (int i = 0; i + m - 1 < n; ++i) {
      int fl = 0, g = 0;
      for (int j = i; j <= i + m - 1; ++j)
        if (s[j] == s[i + m - 1 + i - j])
          fl = 1;
        else
          g |= 1 << min(s[j] - 'a', s[i + m - 1 + i - j] - 'a');
      if (!fl)
        f[(1 << 17) - 1 - g] = 1;
    }
    for (int i = 0; i < 17; ++i)
      for (int j = 0; j < (1 << 17); ++j)
        if (j >> i & 1)
          f[j ^ (1 << i)] |= f[j];
    for (int i = 0; i < (1 << 17); ++i)
      if (!f[i]) {
        int o = 0;
        for (int j = 0; j < 17; ++j)
          if (i >> j & 1)
            o += a[j];
        an = min(an, o);
      }
    printf("%d\n", an);
  }
  return 0;
}