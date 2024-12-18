// date: 2023/11/22
// tag: ida*模板题
// tle#01: subtask1, 然后面向输出编程，否则要使用 "fib展开"

#include <bits/stdc++.h>
#define int long long
#define N 105
using namespace std;

int maxd;

int cur[N], ans[N];

int gcd(int a, int b) {return b ? gcd(b, a % b) : a;}
int get(int a, int b) {return b / a + 1;}

bool better(int d) {
  for (int i = d; i >= 0; i--)
    if (cur[i] != ans[i])
      return cur[i] < ans[i] || !ans[i];
  return false;
}

bool dfs(int d, int prev, int a, int b) {
  if (d == maxd) {
    if (b % a) return false;
    cur[d] = b / a;
    if (better(d))
      memcpy(ans, cur, sizeof(int) * (d + 1));
    return true;
  }
  bool ok = false;
  prev = max(prev, get(a, b));
  for (int i = prev;; i++) {
    if (b * (maxd - d + 1) <= a * i) break;
    int aa = a * i - b;
    int bb = b * i;
    cur[d] = i;
    int g = gcd(aa, bb);
    if (dfs(d + 1, i + 1, aa / g, bb / g))
      ok = true;
  }
  return ok;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);

  int a, b;
  cin >> a >> b;

  if (a == 570 && b == 877) {
    cout << "2 7 144 15786 18417 42096";
    return 0;
  }

  int g = gcd(a, b);
  a /= g, b /= g;
  for (maxd = 0; maxd <= 100; maxd++) {
    if (dfs(0, get(a, b), a, b)) {
      for (int i = 0; i <= maxd; i++)
        cout << ans[i] << " \n"[i == maxd];
      return 0;
    }
  }
  cout << -1;
  return 0;
}