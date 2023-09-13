#include <bits/stdc++.h>
using namespace std;

struct Book {
  int h, w;
  bool operator < (const Book &b) const {
    return h < b.h;
  }
} books[101];

int f[101][101];
// 以某本书结尾，长度为某时的最小不整齐度

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++)
    cin >> books[i].h >> books[i].w;
  sort(books, books + n);
  int r = n - k;
  memset(f, 0x3f, sizeof(f));
  for (int i = 0; i < n; i++)
    f[i][1] = 0;
  for (int i = 1; i < n; i++)
    for (int j = 0; j < i; j++)
      for (int l = 2; l <= min(i + 1, r); l++)
        f[i][l] = min(f[i][l], f[j][l - 1] + abs(books[i].w - books[j].w));
  int ans = 0x7fffffff;
  for (int i = r - 1; i < n; i++)
    ans = min(ans, f[i][r]);
  cout << ans;
  return 0;
}