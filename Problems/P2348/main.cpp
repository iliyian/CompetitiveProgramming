#include <bits/stdc++.h>
using namespace std;

string cn[100001], t[100001], temp[100001];

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  int n, k, m, p;
  cin >> n >> k >> m >> p;
  if (n * 4 > k) {
    cout << "Error:cards not enough";
    return 0;
  }
  for (int i = 1; i <= k; i++) {
    cin >> cn[i] >> t[i];
  }
  for (int i = 0; i < m; i++) {
    for (int j = 1, tt = 1; j <= k; j += 2, tt++) {
      temp[j + 1] = cn[tt];
      temp[j] = cn[k / 2 + tt];
    }
    for (int j = 1; j <= k; j++)
      cn[j] = temp[j];
    for (int j = 1, tt = 1; j <= k; j += 2, tt++) {
      temp[j + 1] = t[tt];
      temp[j] = t[k / 2 + tt];
    }
    for (int j = 1; j <= k; j++)
      t[j] = temp[j];
  }
  for (int i = 1, j = 0; i <= k && j < 4; i++) {
    if ((i - 1) % n + 1 == p) {
      cout << cn[i] << ' ' << t[i] << '\n';
      j++;
    }
  }
  return 0;
}
