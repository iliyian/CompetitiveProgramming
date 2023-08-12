#include <bits/stdc++.h>
using namespace std;

const int N = 100000000;
bitset<100000000> vis;
int pri[10000000], cnt = 0;

int main() {
  freopen("prime.in", "w", stdout);
  vis[1] = vis[0] = false;
  for (int i = 2; i <= N; i++) {
    if (!vis[i]) {
      pri[cnt++] = i;
    }
    for (int j = 0; j < cnt; j++) {
      if (1ll * i * pri[j] > N) break;
      vis[i * pri[j]] = true;
      if (!(i % pri[j])) break;
    }
  }
  cout << cnt << ' ';
  for (int i = 0; i < cnt; i++)
    cout << pri[i] << ' ';
  return 0;
}