// date: 2023/12/16
// tag: bit operation, split an number into diff of two 2^x
// wa#01: 总是在奇奇怪怪的时候让你不开long long见祖宗

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n, sum = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i], sum += a[i];
  if (sum % n) {
    cout << "NO\n";
    return;
  }
  int avg = sum / n;
  vector<int> cnt(32);
  for (int i = 0; i < n; i++) {
    int d = abs(a[i] - avg);
    int del = d & -d; // 这步太tmd妙了
    int add = d + del;
    if (__builtin_popcount(add) == 1) {
      if (a[i] < avg) cnt[log2(add)]++, cnt[log2(del)]--;
      else cnt[log2(add)]--, cnt[log2(del)]++;
    } else if (d) {
      cout << "NO\n";
      return;
    }
  }
  for (int i = 0; i <= 30; i++)
    if (cnt[i]) {
      cout << "NO\n";
      return;
    }
  cout << "YES\n";
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("D1.in", "r", stdin);
  freopen("D1.out", "w", stdout);
  int _; cin >> _;
  while (_--) solve();
}