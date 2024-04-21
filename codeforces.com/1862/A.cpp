#include <bits/stdc++.h>
using namespace std;

char a[30][30];

void solve() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> a[i][j];
  char t[] = {'v', 'i', 'k', 'a'};
  int cur = 0;
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++) {
      if (a[j][i] == t[cur]) {
        cur++;
        if (cur == 4) {
          cout << "YES\n";
          return;
        }
        break;
      }
    }
  cout << "NO\n";
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("A.in", "r", stdin);
  freopen("A.out", "w", stdout);
  int _; cin >> _;
  while (_--) solve();
}