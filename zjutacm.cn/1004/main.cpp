#include <bits/stdc++.h>
using namespace std;

int a[100000];

void solve() {
  int N;
  cin >> N;
  cin >> a[0];
  int res = a[0];
  for (int i = 1; i < N; i++)
    cin >> a[i], res ^= a[i];
  int maxn = -1, idx = 0;
  for (int i = 0; i < N; i++) {
    int t = res ^ a[i];
    if (t > maxn) maxn = t, idx = i;
  }
  res = maxn;
  maxn = -1;
  for (int i = 0; i < N; i++) {
    if (idx == i) continue;
    int t = res ^ a[i];
    if (t > maxn) maxn = t;
  }
  cout << maxn << '\n';
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  int T;
  cin >> T;
  while (T--) solve();
  return 0;
}