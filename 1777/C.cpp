#include <bits/stdc++.h>
using namespace std;

int a[200001];
int cnt[200001], pri[200001], pric = 0;
bitset<200001> vis;

int cntcnt = 0;
vector<vector<int>> factors;


// 暴力出奇迹
void gen() {
  factors.resize(200001);
  for (int i = 1; i <= 200000; i++)
    for (int j = i; j <= 200000; j += i)
      factors[j].push_back(i);
}

void solve() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  sort(a, a + n);

  memset(cnt, 0, sizeof(cnt));
  cntcnt = 0;
  int l = 0, ans = 0x3f3f3f3f;
  for (int r = 0; r < n; r++) {
    for (int i = 0; i < factors[a[r]].size(); i++) {
      if (factors[a[r]][i] > m) break;
      if (cnt[factors[a[r]][i]]++ == 0)
        cntcnt++;
    }
    while (cntcnt >= m) {
      ans = min(ans, a[r] - a[l]);
      for (int i = 0; i < factors[a[l]].size(); i++) {
        if (factors[a[l]][i] > m) break;
        if (--cnt[factors[a[l]][i]] == 0)
          --cntcnt;
      }
      l++;
    }
  }
  cout << (ans == 0x3f3f3f3f ? -1 : ans) << '\n';
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("C.in", "r", stdin);
  int t;
  cin >> t;
  gen();
  while (t--) solve();
  return 0;
}