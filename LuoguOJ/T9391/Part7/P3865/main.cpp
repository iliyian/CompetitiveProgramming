// 位运算优先级低于四则
// 顺便ios::sync_with_stdio(false)和cin.tie(0)或cout.tie(0)比快读快写还快
// 上一条不能用endl，会刷新缓冲区

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100010;
const int LOGN = 21;

array<array<int, LOGN>, MAXN> f{};
array<int, MAXN> logn;

// void read(int &n) {
//   n = 0; char ch = getchar();
//   while (!isdigit(ch)) ch = getchar();
//   while (isdigit(ch)) n = n * 10 + ch - '0', ch = getchar();
// }

// void write(int x) {
//   if (!x) return;
//   write(x / 10);
//   putchar(x % 10 + '0');
// }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  freopen("data.in", "r", stdin);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> f[i][0];
  logn[2] = 1;
  for (int i = 3; i < n; i++)
    logn[i] = logn[i / 2] + 1;
  for (int j = 1; j < LOGN; j++) {
    for (int i = 0; i + (1 << j) <= n; i++) { // 惯例左闭右开
      f[i][j] = max(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
    }
  }
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y; x--, y--;
    int s = logn[y - x];
    cout << max(f[x][s], f[y - (1 << s) + 1][s]) << '\n';
    // if (n) write(n);
    // else putchar('0');
    // putchar('\n');
  }
  return 0;
}