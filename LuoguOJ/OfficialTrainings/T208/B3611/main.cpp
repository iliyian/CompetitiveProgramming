#include <bits/stdc++.h>
using namespace std;

bitset<100> e[100];

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      int a;
      cin >> a;
      e[i][j] = a;
    }
  for (int k = 0; k < n; k++)
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        if (!e[i][j])
          e[i][j] = e[i][k] & e[k][j];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++)
      cout << e[i][j] << ' ';
    cout << '\n';
  }
  return 0;
}