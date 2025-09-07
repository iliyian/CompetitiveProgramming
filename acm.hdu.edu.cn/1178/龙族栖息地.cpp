#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n;

ll calc(ll q, vector<ll> &Q, vector<ll> &R) {
  ll c1 = 0, c2 = 0;
  for (int i = 0; i < Q.size(); i++)
    c1 += abs(q - Q[i]);
  vector<ll> a;
  for (int i = 0; i < R.size(); i++) {
    a.push_back(R[i]);
    a.push_back(R[i] + Q[i] - q);
  }
  sort(a.begin(), a.end());
  for (int i = 0; i < a.size(); i++)
    c2 += abs(a[i] - a[a.size() / 2]);
  return c1 + c2;
}
void solve() {
  vector<ll> Q, R;
  ll low = INT_MAX, high = INT_MIN;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    ll q, r, s;
    cin >> q >> r >> s;
    Q.push_back(q);
    R.push_back(r);
    low = min(low, q);
    high = max(high, q);
  }
  //    cout<<"!"<<low<<' '<<high<<endl;
  while (high - low > 4) {
    ll d = (high - low);
    ll mid1 = low + d / 3, mid2 = high - d / 3;
    if (calc(mid1, Q, R) < calc(mid2, Q, R))
      high = mid2;
    else
      low = mid1;
  }
  ll ans = LLONG_MAX;
  for (int i = low; i <= high; i++) {
    ans = min(ans, calc(i, Q, R));
  }
  cout << ans / 2 << endl;
}
int main() {
  ios::sync_with_stdio(false);
  int T = 1;
  cin >> T;
  while (T--)
    solve();
  return 0;
}