#include <bits/stdc++.h>
using namespace std;

bitset<100> e[100];

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      int a; cin >> a;
      e[i][j] = a;
    }
  for (int j = 0; j < n; j++)
    for (int i = 0; i < n; i++)
      if (e[i][j])
        e[i] |= e[j];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++)
      cout << e[i][j] << ' ';
    cout << '\n';
  }
  return 0;
}