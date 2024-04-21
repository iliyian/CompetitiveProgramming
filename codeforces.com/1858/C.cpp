// date: 2024/02/08 11:53:13
// tag: 关键还是找规律
// 循环的变量未必是索引，也可以是值

#include <bits/stdc++.h>
#define N 100005
using namespace std;

vector<int> pri;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1);
  int cur = 0;
  for (int i = 1; i <= n; i += 2) {
    for (int j = i; j <= n; j *= 2) {
      cout << j << ' ';
    }
  }
  cout << '\n';
}
// 1 2 4 8 3 6 5 10 7 9

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("C.in", "r", stdin);
  freopen("C.out", "w", stdout);

  // for (int i = 2; i <= N - 1; i++) {
  //   if (!vis[i]) {
  //     pri.push_back(i);
  //   }
  //   for (int p : pri) {
  //     if (i * p >= N) break;
  //     vis[i * p] = true;
  //     if (i % p == 0) break;
  //   }
  // }

  int _; cin >> _;
  while (_--) solve();
}