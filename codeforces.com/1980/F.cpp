#include <bits/stdc++.h>

#define int long long
#define pb emplace_back
#define mp make_pair
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()

    typedef long double ld;
typedef long long ll;

using namespace std;

mt19937 rnd(time(nullptr));

const ll inf = 1e9 + 1;
const ll M = 998244353;
const ld pi = atan2(0, -1);
const ld eps = 1e-6;

bool cmp(pair<int, int> &a, pair<int, int> &b) {
  if (a.x != b.x)
    return a.x > b.x;
  return a.y < b.y;
}

void solve(int tc) {
  int n, m, k;
  cin >> n >> m >> k;
  vector<pair<int, int>> a(k);
  map<pair<int, int>, int> idx;
  for (int i = 0; i < k; ++i) {
    cin >> a[i].x >> a[i].y;
    idx[a[i]] = i;
  }
  idx[{0, 0}] = k++;
  a.emplace_back(0, 0);
  sort(all(a), cmp);
  vector<int> ans(k);
  vector<int> total(k + 1), cur(k + 1, m + 1), last(k + 1, n);
  for (int i = 1; i <= k; ++i) {
    auto e = a[i - 1];
    total[i] = total[i - 1];
    cur[i] = cur[i - 1];
    last[i] = last[i - 1];
    if (cur[i] > e.y) {
      ans[idx[e]] = 1;
      total[i] += (cur[i] - 1) * (last[i] - e.x);
      cur[i] = e.y;
      last[i] = e.x;
    }
  }
  cout << total[k] << "\n";
  for (int i = 1; i <= k; ++i) {
    auto e = a[i - 1];
    if (ans[idx[e]] == 0)
      continue;
    int tot = total[i - 1];
    int cr = cur[i - 1];
    int lst = last[i - 1];
    for (int j = i + 1; j <= k; ++j) {
      auto ee = a[j - 1];
      if (cr > ee.y) {
        tot += (cr - 1) * (lst - ee.x);
        cr = ee.y;
        lst = ee.x;
      }
      if (ans[idx[ee]] == 1) {
        ans[idx[e]] = tot - total[j];
        break;
      }
    }
  }
  ans.pop_back();
  for (int e : ans)
    cout << e << " ";
}

bool multi = true;

signed main() {
  freopen("F.in", "r", stdin);
  int t = 1;
  if (multi)
    cin >> t;
  for (int i = 1; i <= t; ++i) {
    solve(i);
    cout << "\n";
  }
  return 0;
}