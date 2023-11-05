// 桶的思想

#include <bits/stdc++.h>
using namespace std;

int a[250001], ans[250001], num[250001];
map<int, int> m;

int gcd(int a, int b) {
  return b == 0 ? a : gcd(b, a % b);
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);

  int n, cnt = 0;
  cin >> n;
  for (int i = 0; i < n * n; i++) {
    cin >> a[i];
    if (!m[a[i]]) num[cnt++] = a[i];
    m[a[i]]++;
  }
  sort(num, num + cnt);
  int anslen = 0;
  for (int i = cnt - 1; i >= 0 && anslen < n;) {
    // 充要条件，避免遗漏
    while (!m[num[i]]) i--;
    m[num[i]]--;
    ans[anslen++] = num[i];
    for (int j = 0; j < anslen - 1; j++)
      m[gcd(ans[j], num[i])] -= 2;
  }
  for (int i = 0; i < anslen; i++)
    cout << ans[i] << ' ';
  return 0;
}