#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, len;
  string str;
  cin >> len >> n >> str;
  vector<int> l(n), r(n);
  for (int i = 0; i < n; i++)
    cin >> l[i], l[i]--;
  for (int i = 0; i < n; i++)
    cin >> r[i], r[i]--;
  int k;
  cin >> k;
  vector<int> cnt(len);
  for (int i = 0; i < k; i++) {
    int x;
    cin >> x;
    cnt[--x]++;
  }
  for (int i = 0; i < n; i++) {
    int sum = 0;
    for (int j = l[i]; j <= (l[i] + r[i]) / 2; j++) {
      sum += cnt[j] + cnt[r[i] - (j - l[i])];
      if (sum & 1)
        swap(str[j], str[r[i] - (j - l[i])]);
    }
  }
  cout << str << '\n';
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("D.in", "r", stdin);
  freopen("D.out", "w", stdout);
  int _; cin >> _;
  while (_--) solve();
}