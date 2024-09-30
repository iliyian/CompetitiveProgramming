#include <bits/stdc++.h>
#define N 5005
using namespace std;

int a[N], b[N];

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("L.in", "r", stdin);
  int n, x;
  cin >> n >> x;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  for (int i = 1; i <= n; i++)
    cin >> b[i];
  if (a[x] && a[1]) {
    cout << "YES";
    return 0;
  }
  if (!b[x] || !a[1]) {
    cout << "NO";
    return 0;
  }
  for (int i = x + 1; i <= n; i++) {
    if (a[i] & b[i]) {
      cout << "YES";
      return 0;
    }
  }
  cout << "NO";
  return 0;
}