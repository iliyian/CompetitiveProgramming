#include <bits/stdc++.h>
using namespace std;

array<int, 1000000> a;
array<int, 2001> cnt;

int n, m, ansl, ansr;
bool f = false;

bool check(int len) {
  int k = 0;
  cnt.fill(0);
  for (int i = 0; i < len; i++) if (!cnt[a[i]]++) k++;
  for (int i = len; i < n; i++) {
    int l = i - len, r = i;
    if (k == m) {
      f = true;
      ansl = l + 1, ansr = r;
      return true;
    }
    if (!--cnt[a[l]]) k--;
    if (!cnt[a[r]]++) k++;
  }
  return false;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> a[i];
  int l = 0, r = n;
  while (l <= r) {
    int mid = l + (r - l) / 2;
    if (check(mid)) r = mid - 1;
    else l = mid + 1;
  }
  if (f)
    cout << ansl << ' ' << ansr;
  else cout << 1 << ' ' << n;
  return 0;
}