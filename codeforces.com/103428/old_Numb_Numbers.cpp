#include <bits/stdc++.h>
#define ll long long
#define N 5000005
using namespace std;
namespace Set {
const ll kInf = 1e15 + 2077;
std::multiset<ll> less, greater;
void init() {
  less.clear(), greater.clear();
  less.insert(-kInf), greater.insert(kInf);
}
void adjust() {
  while (less.size() > greater.size() + 1) {
    std::multiset<ll>::iterator it = (--less.end());
    greater.insert(*it);
    less.erase(it);
  }
  while (greater.size() > less.size()) {
    std::multiset<ll>::iterator it = greater.begin();
    less.insert(*it);
    greater.erase(it);
  }
}
void add(ll val_) {
  if (val_ <= *greater.begin())
    less.insert(val_);
  else
    greater.insert(val_);
  adjust();
}
void del(ll val_) {
  std::multiset<ll>::iterator it = less.lower_bound(val_);
  if (it != less.end()) {
    less.erase(it);
  } else {
    it = greater.lower_bound(val_);
    greater.erase(it);
  }
  adjust();
}
ll get_middle() { return *less.rbegin(); }
} // namespace Set
ll n, q, a[N], k;
void solve() {
  cin >> n >> q;
  k = n / 2;
  Set::init();
  for (int i = 1; i <= n; i++)
    cin >> a[i], Set::add(a[i]);
  while (q--) {
    ll id, v;
    cin >> id >> v;
    Set::del(a[id]);
    a[id] += v;
    Set::add(a[id]);
    ll maxn = Set::greater.size() - Set::greater.count(Set::get_middle()) - 1;
    if (maxn >= k)
      cout << n - maxn << endl;
    else
      cout << Set::less.size() - Set::less.count(Set::get_middle()) - 1 << endl;
  }
}
int main() {
  ios::sync_with_stdio(false);
  int T = 1;
  cin >> T;
  while (T--)
    solve();
  return 0;
}