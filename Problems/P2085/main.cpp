#include <bits/stdc++.h>
using namespace std;

int a[10001], b[10001], c[10001], x[10001];

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i] >> c[i];
  }
  for (int i = 0; i < n; i++)
    x[i] = 1;
  for (int i = 0; i < m; i++) {
    int minn = 0x3f3f3f3f, minx = 0;
    for (int j = 0; j < n; j++) {
      int v = a[j] * x[j] * x[j] + b[j] * x[j] + c[j];
      if (v < minn) {
        minn = v;
        minx = j;
      }
    }
    x[minx]++;
    cout << minn << ' ';
  }
  return 0;
}