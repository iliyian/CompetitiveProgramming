// c,d数组转换成直线方程太巧妙了
// 最小化原则

#include <bits/stdc++.h>
using namespace std;

array<int, 25> a{};
bitset<25> b, c, d;
int n, t = 0, ans = 0;

void dfs(int i) {
  if (i >= n) {
    if (t < 3) {
      t++;
      for (int i = 0; i < n; i++) cout << a[i] + 1 << " ";
      cout << endl;
    }
    ans++;
    return;
  }
  for (int j = 0; j < n; j++) {
    if (b[j] || c[i + j] || d[i - j + n]) continue;
    a[i] = j;
    b[j] = c[i + j] = d[i - j + n] = 1;
    dfs(i + 1);
    b[j] = c[i + j] = d[i - j + n] = 0;
    a[i] = 0;
  }
}

int main() {
  cin >> n;
  dfs(0);
  cout << ans;
  return 0;
}