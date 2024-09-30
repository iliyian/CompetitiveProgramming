#include <bits/stdc++.h>
#define N 401
using namespace std;

int n, k, a[N], cnt[N], cntofcnt[N], viscnt;

bool checkcnt(int x) {
  return cntofcnt[x] == k && viscnt == k;
}

bool check(int mid) {
  memset(cntofcnt, 0, sizeof(cntofcnt));
  memset(cnt, 0, sizeof(cnt));
  viscnt = 0;
  for (int i = 0; i < n; i++) {
    cnt[a[i]]++;
    cntofcnt[cnt[a[i]]]++;
    cntofcnt[cnt[a[i]] - 1]--;

    if (cnt[a[i]] == 1) viscnt++;

    if (checkcnt(cnt[a[i]]) || checkcnt(cnt[a[i]] - 1)) {
      if (i >= mid - 1)
        return true;
    }
    if (i - mid >= 0) {
      --cnt[a[i - mid]];

      if (cnt[a[i - mid]] == 0) viscnt--;

      cntofcnt[cnt[a[i - mid]]]++;
      cntofcnt[cnt[a[i - mid]] + 1]--;
      if (checkcnt(cnt[a[i - mid]]) || checkcnt(cnt[a[i - mid]] - 1)) {
        return true;
      }
    }
  }
  return false;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("A.in", "r", stdin);
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int l = 0, r = n, ans = -1;
  while (l <= r) {
    int mid = l + (r - l >> 1);
    if (check(mid)) l = mid + 1, ans = mid;
    else r = mid - 1;
  }
  cout << (ans == -1 ? 0 : ans);
  return 0;
}