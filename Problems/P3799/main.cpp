// 前中后最好都 mod 一下

#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;

int a[100000], cnt[5001];

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  int n;
  cin >> n;
  int minlen = 0x3f3f3f3f, maxlen = -1;
  memset(cnt, 0, sizeof(cnt));
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    cnt[a[i]]++;
    minlen = min(minlen, a[i]), maxlen = max(maxlen, a[i]);
  }
  int ans = 0;
  for (int i = minlen; i <= maxlen; i++) {
    if (cnt[i] >= 2) {
      int icnt = cnt[i] * (cnt[i] - 1) % mod / 2;
      for (int j = minlen; j <= i / 2; j++) {
        if (j * 2 == i && cnt[j] >= 2) {
          ans += cnt[j] * (cnt[j] - 1) % mod / 2 * icnt;
        } else if (j * 2 != i && cnt[i - j] && cnt[j]) {
          ans += cnt[j] * cnt[i - j] % mod * icnt;
        }
      }
      ans %= mod;
    }
  }
  cout << ans;
  return 0;
}