#include <bits/stdc++.h>
using namespace std;

int a[100005], n;

int getCount(int len) {
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    cnt += a[i] / len;
  }
  return cnt;
}

int main() {
  freopen("data.in", "r", stdin);
  int k, r = -1;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    r = max(r, a[i]);
  }
  int l = 0;
  while (r - l > 1) {
    int mid = l + (r - l) / 2;
    if (getCount(mid) >= k) {
      l = mid;
    } else {
      r = mid;
    }
  }
  cout << l;
  return 0;
}