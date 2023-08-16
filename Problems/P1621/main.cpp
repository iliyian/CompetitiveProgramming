#include <bits/stdc++.h>
using namespace std;

bitset<100001> vis;
int pris[100001], pricnt = 0, pa[100001];

int find(int x) {return x == pa[x] ? x : pa[x] = find(pa[x]);}

int main() {
  int a, b, P;
  cin >> a >> b >> P;
  for (int i = 1; i <= b; i++) pa[i] = i;
  for (int i = 2; i <= b; i++) {
    if (!vis[i]) {
      pris[pricnt++] = i;
    }
    for (int j = 0; j < pricnt; j++) {
      if (1ll * pris[j] * i > b) break;
      vis[pris[j] * i] = true;
      if (i % pris[j] == 0) break;
    }
  }

  for (int i = 0; i < pricnt; i++) {
    int p = pris[i];
    if (p >= P) {
      for (int j = (a - 1) / p + 1; p * (j + 1) <= b; j++)
        pa[find(p * (j + 1))] = find(j * p);
    }
  }
  int ans = 0;
  for (int i = a; i <= b; i++) {
    if (pa[i] == i) ans++;
  }
  cout << ans;
  return 0;
}