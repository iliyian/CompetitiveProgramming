#include <bits/stdc++.h>
#define M 100005
using namespace std;

int cnt[M];

void solve() {
  int n;
  cin >> n;
  int cur = 1;
  fill(cnt, cnt + M, 0);
  vector<int> vec;
  while (cur < n) {
    vec.push_back(cur);
    cur <<= 1;
  }
  cur >>= 1;
  for (int i = vec.size() - 1; i >= 0; i--) {
    if (vec[i] + cur <= n) {
      cur += vec[i];
      vec.push_back(cur);
    }
  }
  cout << vec.size() << '\n';
  for (int i = vec.size() - 1; i >= 0; i--) {
    cout << vec[i] << " \n"[i == 0];
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("C.in", "r", stdin);
  freopen("C.out", "w", stdout);
  int _; cin >> _;
  while (_--) solve();
}

// 101
// 1 2 4 8 16 32 64
// 