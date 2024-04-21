// wa#01：没意识到二维前缀和求某个宽为1的矩阵和时仍然需要四角坐标
//        除非对于这种单次求和的宽必然为1的情况制作C个一维前缀和

#include <bits/stdc++.h>
#define N 505
using namespace std;

int a[N][N], s[N][N], R, C, A, B;

bool check(int mid) {
  int acnt = 0, prev = 0;
  for (int i = 1; i <= R; i++) {
    int bcnt = 0, sum = 0;
    for (int j = 1; j <= C; j++) {
      // (prev,j-1)-(i,j), width=1, height=i-prev
      sum += s[i][j] + s[prev][j - 1] - s[i][j - 1] - s[prev][j];
      // 当前满足要求，只要所有块大于要求即可
      if (sum >= mid) {
        // 注意B表示块数而不是刀数
        bcnt++, sum = 0;
      }
    }
    // 切多的块可以随意合并，即使多出来的单独<mid，随意合并即可
    if (bcnt >= B) {
      // 横向一份完成
      acnt++, prev = i;
    }
  }
  // 多出可以随意合并
  return acnt >= A;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  freopen("data.in", "r", stdin);
  cin >> R >> C >> A >> B;
  for (int i = 1; i <= R; i++)
    for (int j = 1; j <= C; j++) {
      cin >> a[i][j];
      s[i][j] = a[i][j] + s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
    }
  int l = 0, r = s[R][C], ans = -1;
  // 步子迈大才能真正拥抱
  while (l <= r) {
    int mid = l + (r - l >> 1);
    if (check(mid)) l = mid + 1, ans = mid;
    else r = mid - 1;
  }
  cout << ans;
  return 0;
}