#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  int A, B;
  cin >> A >> B;

  
  auto find = [&](auto self, int x) -> int {
    return pa[x] == -1 ? self(self, calc(x)) : pa[x];
  };

  vector<int> pa

  return 0;
}