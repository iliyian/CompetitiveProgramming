// 难得一道没看过题解的
// 真理的永恒，永恒的真理真的很美啊

#include <bits/stdc++.h>
using namespace std;

map<int, int> a, cur;

int main() {
  freopen("data.in", "r", stdin);
  ios::sync_with_stdio(false); cin.tie(0);
  int n, m1, m2;
  cin >> n >> m1 >> m2;

  if (m1 == 1) {
    cout << 0;
    return 0;
  }

  int tot = 0;
  for (int i = 2; i * i <= n; i++) {
    if (m1 % i == 0) {
      a[i]++;
      m1 /= i;
      while (m1 % i == 0) m1 /= i, a[i]++;
      a[i] *= m2;
      tot++;
    }
  }
  if (m1 != 1) {
    a[m1]++;
    a[m1] *= m2;
    tot++;
  }

  int ans = 0x3f3f3f3f;
  for (int i = 1; i <= n; i++) {
    int s;
    cin >> s;
    int cnt = 0, res = -1;
    cur.clear();
    for (int j = 2; j * j <= s; j++) {
      if (s % j == 0 && a[j]) {
        s /= j;
        cur[j]++;
        while (s % j == 0) s /= j, cur[j]++;

        res = max(res, (a[j] - 1) / cur[j] + 1), cnt++; 
      }
    }
    if (s != 1 && a[s]) {
      cur[s]++;
      cnt++;
      res = max(res, (a[s] - 1) / cur[s] + 1);
    }
    if (cnt == tot) {
      ans = min(ans, res);
    }
  }

  cout << (ans == 0x3f3f3f3f ? -1 : ans);
  return 0;
}