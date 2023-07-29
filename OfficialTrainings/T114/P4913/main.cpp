#include <bits/stdc++.h>
using namespace std;

int lch[100005], rch[100005], ans = 0;

void dfs(int n, int d) {
  if (lch[n] == 0 && rch[n] == 0) {
    ans = max(ans, d);
  } else {
    if (lch[n]) dfs(lch[n], d + 1);
    if (rch[n]) dfs(rch[n], d + 1);
  }
}

int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> lch[i] >> rch[i];
  }
  dfs(1, 1);
  cout << ans;
  return 0;
}