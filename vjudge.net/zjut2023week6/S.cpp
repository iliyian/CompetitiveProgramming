#include <bits/stdc++.h>
#define N 105
using namespace std;

bitset<N> a[N];

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  freopen("S.in", "r", stdin);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
      int x; cin >> x;
      a[i][j] = x;
    }
  for (int k = 1; k <= n; k++)
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
        a[i][j] = a[i][j] | (a[i][k] & a[k][j]);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      cout << a[i][j] << " \n"[j == n];
}