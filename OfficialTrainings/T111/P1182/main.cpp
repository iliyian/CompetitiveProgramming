#include <bits/stdc++.h>
using namespace std;

int a[100000], sums[100000], n, m;

bool check(int mid) {
  int sum = 0, cnt = 0;
  for (int i = 0; i < n; i++) {
    if (sum + a[i] <= mid) sum += a[i];
    else cnt++, sum = a[i];
  }
  return cnt < m;
}

int main() {
  freopen("data.in", "r", stdin);
  int l = -1, r = 0, mid;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    r += a[i];
    l = max(l, a[i]);
  }
  while (l <= r) {
    mid = l + (r - l) / 2;
    if (check(mid)) {
      r = mid - 1;
    } else l = mid + 1;
  }
  cout << l;
  return 0;
}