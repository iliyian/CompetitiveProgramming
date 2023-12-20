#include <bits/stdc++.h>
#define N 105
using namespace std;

char a[N][N];

void solve() {
  int r, c;
  cin >> r >> c;
  for (int i = 0; i < r; i++)
    for (int j = 0; j < c; j++) {
      cin >> a[i][j];
      if (a[i][j] == 'X')
    }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("5.in", "r", stdin);
  freopen("5.out", "w", stdout);
  int _; cin >> _;
  while (_--) solve();
}