#include <bits/stdc++.h>
using namespace std;

int a[100000], dp[100000], nxt[100000], len = 0;
int maxn = -1, maxi;

void dpfunc() {
  for (int i = 0; i < len; i++) dp[i] = -0x7fffffff, nxt[i] = 0;
  for (int i = 0; i < len; i++) if (a[i]) {dp[i] = 1; break;}
  maxn = -1;
  for (int i = 0; i < len; i++) { 
    for (int j = 0; j < i; j++)
      if (a[i] && a[j] >= a[i]) {
        if (dp[j] < dp[i] + 1) {
          dp[j] = dp[i] + 1;
          nxt[i] = j; // reverse
        }
      }
  }
  for (int i = 0; i < len; i++) {
    if (dp[i] > maxn) maxn = dp[i], maxi = i;
  }
}

int main() {
  freopen("data.in", "r", stdin);
  int x;
  while (cin >> x) {a[len++] = x; dp[len - 1] = -0x7fffffff;}

  dpfunc();
  cout << maxn << '\n';

  int cleared = 0, ans = 0;
  while (cleared < len) {
    int cur = maxi, nx = nxt[cur];
    while (cur != nx) {
      a[cur] = 0;
      cur = nx;
      nx = nxt[nx];
      cleared++;
    }
    if (a[cur]) cleared++, a[cur] = 0;
    ans++;
    dpfunc();
  }
  cout << ans;
  return 0;
}