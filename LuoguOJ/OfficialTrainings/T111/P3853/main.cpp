#include <bits/stdc++.h>
using namespace std;

int a[100000], L, N, K;

bool check(int mid) {
  int cnt = 0;
  for (int i = 0; i < N - 1; i++) {
    int d = a[i + 1] - a[i];
    if (d <= mid) continue;
    else {
      if (cnt >= K) return false;
      if (d % mid == 0) cnt += d / mid - 1;
      else cnt += d / mid;
    }
  }
  return cnt <= K;
}

int main() {
  cin >> L >> N >> K;
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }
  int l = 0, r = L;
  while (l < r - 1) {
    int mid = l + (r - l) / 2;
    if (check(mid)) {
      r = mid;
    } else l = mid;
  }
  cout << l;
  return 0;
}