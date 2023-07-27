// m, n的变量名实在不该搞错
// 对于 lower_bound，范围为1，如果找不到，返回idx=0，而upper_bound则是idx=1，
// 太tmd细了

#include <bits/stdc++.h>
using namespace std;

int a[100001];

int main() {
  freopen("data.in", "r", stdin);
  int m, n;
  cin >> m >> n;
  for (int i = 0; i < m; i++) {
    cin >> a[i];
  }
  sort(a, a + m);
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    int s, d;
    cin >> s;
    int *t = upper_bound(a, a + m, s);
    if (t == a + m) {
      d = abs(s - *(t - 1));
    } else if (t != a) {
      d = min(abs(s - *(t - 1)), abs(s - *t));
    } else d = abs(s - *t);
    ans += d;
  }
  cout << ans;
  return 0;
}