#include <bits/stdc++.h>
#define N 101
using namespace std;

bitset<N> vis;
vector<int> pri;

void solve() {
  string str;
  cin >> str;
  int a = str[0] - '0';
  for (int i = 1; i <= 9; i++)
    if (!vis[a * 10 + i] && i != a) {
      cout << a * 10 + i << '\n';
      return;
    }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("A.in", "r", stdin);
  freopen("A.out", "w", stdout);
  int _; cin >> _;

  for (int i = 2; i <= 100; i++) {
    if (!vis[i]) {
      pri.push_back(i);
    }
    for (int p : pri) {
      if (i * p > 100) break;
      vis[i * p] = true;
      if (i % p == 0) break;
    }
  }

  while (_--) solve();
}