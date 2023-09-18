#include <bits/stdc++.h>
using namespace std;

long long pos[100000], sp[100000];

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  int n, t;
  cin >> n >> t;
  for (int i = 0; i < n; i++)
    cin >> pos[i] >> sp[i], pos[i] += sp[i] * t;
  int ans = 1;
  for (int i = n - 2; i >= 0; i--) {
    if (pos[i] >= pos[i + 1])
      pos[i] = pos[i + 1];
    else
      ans++;
  }
  cout << ans;
  return 0;
}