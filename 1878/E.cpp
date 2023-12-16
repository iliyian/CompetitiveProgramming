#include <bits/stdc++.h>
#define N 200005
using namespace std;

int a[N], l, k;
int s[N][32];

bool check(int r) {
  int sum = 0;
  for (int i = 30; i >= 0; i--)
    if (s[r][i] - s[l - 1][i] == r - l + 1) {
      sum += 1 << i;
      if (sum >= k) return true;
    }
  return false;
}

void solve() {
  int n;
  cin >> n;;

  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    for (int j = 0; j <= 30; j++)
      s[i][j] = s[i - 1][j] + (a[i] >> j & 1);
  }
  

  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    cin >> l >> k;
    int ansl = l, ansr = n, ans = -1;
    while (ansl <= ansr) {
      int mid = ansl + (ansr - ansl >> 1);
      if (check(mid)) ansl = mid + 1, ans = mid;
      else ansr = mid - 1;
    }
    cout << ans << " \n"[i == q - 1];
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("E.in", "r", stdin);
  freopen("E.out", "w", stdout);
  int _; cin >> _;
  while (_--) solve();
}