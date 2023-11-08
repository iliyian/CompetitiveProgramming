// tips: 差分恐怕是少见的 N+1 索引有效的了
// wa#01: 用 mod 2 和 加法差分 代替了 异或差分
// wa#02: 输出的两个值反了

#include <bits/stdc++.h>
#define N 5020
using namespace std;

int a[N], d[N];

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);

  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    char ch;
    cin >> ch;
    a[i] = ch == 'F';
  }
  int ans = 0x3f3f3f3f, ansk = -1;
  for (int k = 1; k <= n; k++) {
    bool f = true;
    int cur = 0, cnt = 0;
    memset(d, 0, sizeof(d));
    for (int i = 1; i <= n; i++) {
      cur ^= d[i]; // 欠债还钱
      if (cur ^ a[i] == 0) {
        if (i + k > n + 1) {
          f = false;
          break;
        }
        cnt++;
        d[i + k] ^= 1, cur ^= 1;
      }
    }
    if (!f) continue;
    if (cnt < ans) {
      ans = cnt;
      ansk = k;
    }
  }
  cout << ansk << ' ' << ans;
  return 0;
}