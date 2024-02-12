#include <bits/stdc++.h>
#define N 1005
using namespace std;

int a[N], b[N];

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("D1.in", "r", stdin);
  freopen("D1.out", "w", stdout);
  int _; cin >> _;
  while (_--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
      cin >> a[i];
    for (int i = 0; i < n; i++)
      cin >> b[i];
    map<int, set<int>> m;
    for (int i = 0; i < n; i++) {
      for (int j = 0;; j++) {
        int p = i + j;
        if (p >= n || a[p] > a[i]) break;
        m[p].insert(a[i]);
      }
      for (int j = 0;; j++) {
        int p = i - j;
        if (p < 0 || a[p] > a[i]) break;
        m[p].insert(a[i]);
      }
    }
    bool f = true;
    for (int i = 0; i < n; i++)
      if (!m[i].count(b[i])) {
        f = false;
        break;
      }
    cout << (f ? "YES" : "NO") << '\n';
  }
}