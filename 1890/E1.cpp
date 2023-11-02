#include <bits/stdc++.h>
#define N 200001
using namespace std;

int a[N], b[N];

void solve() {
  int n, m;
  cin >> n >> m;
  memset(a, 0, sizeof(a));
  vector<int> lens;
  for (int i = 0; i < m; i++) {
    int l, r;
    cin >> l >> r;
    a[l]++, a[r + 1]--;
    lens.push_back(r - l + 1);
  }
  sort(lens.begin(), lens.end());
  int ans = 0;
  int cnt = lens.back() + lens[lens.size() - 2];
  for (int i = 1; i <= n; i++) {
    a[i] += a[i - 1];
    if (!a[i]) ans++;
    else if (a[i] == 2) {

    }
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("E1.in", "r", stdin);
  int t; cin >> t;
  while (t--) solve();
  return 0;
}