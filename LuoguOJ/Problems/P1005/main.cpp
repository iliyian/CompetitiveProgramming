// date: 2023/12/4
// tag: 区间动态规划
// wa#01: 忘记位运算主动进行类型转换 int()

#include <bits/stdc++.h>
#define N 100
#define int __int128_t
using namespace std;

int a[N][N], f[N][N];

istream& operator >> (istream &is, int &a) {
  a = 0; char ch = getchar();
  while (!isdigit(ch)) ch = getchar();
  while (isdigit(ch)) a = a * 10 + ch - '0', ch = getchar();
  return is;
}

void write(int a) {
  if (a >= 10) write(a / 10);
  putchar(a % 10 + '0');
}

ostream& operator << (ostream &os, int a) {
  write(a);
  return os;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      cin >> a[i][j];

  auto get = [&](const int r) {
    auto v = a[r];
    for (int i = 1; i <= m; i++)
      f[i][i] = 0;
    for (int len = 1; len <= m; len++) {
      for (int i = 1; i <= m - len + 1; i++) {
        int j = i + len - 1;
        // what a typo int()
        f[i][j] = max(f[i + 1][j] + (int(1) << 1 + m - len) * v[i],
          f[i][j - 1] + (int(1) << 1 + m - len) * v[j]);
      }
    }
    return f[1][m];
  };
  int ans = 0;
  for (int i = 1; i <= n; i++)
    ans += get(i);
  cout << ans;
}