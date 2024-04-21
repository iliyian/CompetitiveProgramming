#include <bits/stdc++.h>
using namespace std;

bitset<100001> vis;

int pri[100001], cnt = 0, f[100001];

void gen(int n) {
  for (int i = 2; i <= n; i++) {
    if (!vis[i]) {
      pri[cnt++] = i;
    }
    for (int j = 0; j < cnt; j++) {
      int p = 1ll * pri[j] * i;
      if (p > n) break;
      vis[p] = true;
      if (i % pri[j] == 0) break;
    }
  }
}

int main() {
  int n;
  cin >> n;
  gen(n + 1);
  for (int i = 2; i <= n + 1; i++) {
    if (!vis[i]) {
      f[i] = 1;
      for (int j = 2; j * i <= n + 1; j++) {
        f[j * i] = 2;
      }
    }
  }
  cout << (n < 3 ? 1 : 2) << '\n';
  for (int i = 2; i <= n + 1; i++)
    cout << f[i] << ' ';
  return 0;
}