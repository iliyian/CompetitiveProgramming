#include <bits/stdc++.h>
#define mod 7
using namespace std;

array<int, 50000> a, sum, mods;

int N;

int find(int n) {
  int l = N, r = -1;
  for (int i = 0; i < N; i++) {
    if (sum[i] == n) {
      if (i < l) l = i;
      if (i > r) r = i;
    }
  }
  return r - l;
}

int main() {
//   freopen("data.in", "r", stdin);
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> a[i];
    if (i) sum[i] = sum[i - 1] + a[i];
    else sum[i] = a[i];
    sum[i] %= 7;
  }
  int ans = -1;
  for (int i = 0; i < 7; i++)
    ans = max(ans, find(i));
  cout << ans;
  return 0;
}