#include <bits/stdc++.h>
using namespace std;

int a[270000], f[59][270000];

int main() {
  int n, ans = 1;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i], f[a[i]][i + 1] = i + 2;
  for (int num = 2; num <= 58; num++) {
    for (int l = 0; l < n; l++) {
      if (!f[num][l])
        f[num][l] = f[num - 1][f[num - 1][l]];
      if (f[num][l])
        ans = num;
    }
  }
  cout << ans;
  return 0;
}