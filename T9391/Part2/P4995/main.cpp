#include <bits/stdc++.h>
using namespace std;

int stones[305];

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> stones[i];
  sort(stones, stones + n);
  int l = 0, r = n - 1, preh = 0;
  bool f = false;
  long long ans = 0;
  while (l <= r) {
    if (f) {
      ans += (preh - stones[l]) * (preh - stones[l]);
      preh = stones[l]; l++;
    } else {
      ans += (preh - stones[r]) * (preh - stones[r]);
      preh = stones[r]; r--;
    }
    f = !f;
  }
  cout << ans;
  return 0;
}