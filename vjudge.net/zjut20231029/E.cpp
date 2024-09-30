#include <bits/stdc++.h>
using namespace std;

int pos[200001], a[200001];

void swap(int &a, int &b) {
  a ^= b;
  b ^= a;
  a ^= b;
}

int main() {
  freopen("E.in", "r", stdin);
  ios::sync_with_stdio(false); cin.tie(0);
  int n, q;
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    pos[i] = i;
    a[i] = i;
  }
  for (int i = 0; i < q; i++) {
    int x;
    cin >> x;
    if (pos[x] == n) {
      pos[x] = n - 1;
      pos[a[n - 1]] = n;
      swap(a[n - 1], a[n]);
    } else {
      pos[a[pos[x] + 1]]--;
      swap(a[pos[x]], a[pos[x] + 1]);
      pos[x]++;
    }
  }
  for (int i = 1; i <= n; i++)
    cout << a[i] << ' ';
  return 0;
}