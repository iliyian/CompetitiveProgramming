// date: 2024-05-30 21:04:23
// tag: 位运算，区间数据结构

#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("A.in", "r", stdin);
  freopen("A.out", "w", stdout);

  int n;
  cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  stack<int> s;
  vector<int> l(n + 1), r(n + 1);
  for (int i = 1; i <= n; i++) {
    while (!s.empty() && a[s.top()] < a[i]) {
      r[s.top()] = i - 1;
      s.pop();
    }
    s.push(i);
  }
  while (!s.empty()) {
    r[s.top()] = n;
    s.pop();
  }
  
  for (int i = n; i >= 1; i--) {
    while (!s.empty() && a[s.top()] < a[i]) {
      l[s.top()] = i + 1;
      s.pop();
    }
    s.push(i);
  }
  while (!s.empty()) {
    l[s.top()] = 1;
    s.pop();
  }
  // for (int i = 1; i <= n; i++) {
  //   cerr << l[i] << " \n"[i == n];
  // }
  // for (int i = 1; i <= n; i++) {
  //   cerr << r[i] << " \n"[i == n];
  // }

  assert(s.empty());
  vector<vector<int>> lone(n + 1, vector<int>(32)), rone(n + 1, vector<int>(32));
  for (int i = 31; i >= 0; i--) {
    for (int j = 1; j <= n; j++) {
      if (a[j] >> i & 1) {
        while (!s.empty()) {
          rone[s.top()][i] = j;
          s.pop();
        }
      } else {
        s.push(j);
      }
    }
    while (!s.empty()) {
      rone[s.top()][i] = n + 1;
      s.pop();
    }
    
    for (int j = n; j >= 1; j--) {
      if (a[j] >> i & 1) {
        while (!s.empty()) {
          lone[s.top()][i] = j;
          s.pop();
        }
      } else {
        s.push(j);
      }
    }
    while (!s.empty()) {
      lone[s.top()][i] = 0;
      s.pop();
    }
  }

  int ans = n * (n - 1) / 2;
  unordered_map<int, unordered_map<int, int>> vis;
  for (int i = 1; i <= n; i++) {
    int rmax = r[i];
    int lmax = l[i];
    for (int j = 31; j >= 0; j--) {
      if (a[i] >> j & 1 ^ 1) {
        lmax = max(lmax, lone[i][j] + 1);
        rmax = min(rmax, rone[i][j] - 1);
      }
    }
    // if (a[i] == 0) rmax = n, lmax = 1;
    // ans -= rmax - i + i - lmax;
    int rawlmax = lmax, &t = vis[lmax][rmax];
    if (t) {
      lmax = max(lmax, t + 1);
    }
    ans -= (i - lmax + 1) * (rmax - i + 1) - 1;
    // cout << i << ' ' << lmax << ' ' << rmax << '\n';
    vis[rawlmax][rmax] = i;
    // cout << i << ' ' << rmax << '\n';
    // if (i != rmax) {
    //   cout << "i != rmax" << '\n';
    // }
  }
  cout << ans << '\n';

  return 0;
}