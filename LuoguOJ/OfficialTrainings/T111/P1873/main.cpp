#include <bits/stdc++.h>
using namespace std;

int a[1000006], n;

long long getSum(int h) {
  long long sum = 0;
  for (int i = 0; i < n; i++)
    sum += max(0, a[i] - h);
  return sum;
}

int main() {
  freopen("data.in", "r", stdin);
  int m, maxh = -1, minh = 1e9;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    maxh = max(maxh, a[i]);
    minh = min(minh, a[i]);
  }
  int l = minh, r = maxh, sum = 0;
  while (r - l > 1) {
    int mid = l + (r - l) / 2;
    if (getSum(mid) < m) {
      r = mid;
    } else {
      l = mid;
    }
  }
  cout << l;
  return 0;
}