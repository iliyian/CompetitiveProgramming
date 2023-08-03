#include <bits/stdc++.h>
using namespace std;

const int N = 1000000;
bitset<100000000> vis;
int pri[1000000], cnt = 0;

int main() {
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
  for (int i = 0; i < cnt; i++)
    cout << pri[i] << ' ';
  return 0;
}