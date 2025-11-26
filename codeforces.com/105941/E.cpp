#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 2e5 + 7;
int ch[MAXN][27],cnt[MAXN],idx = 0;
map<char,int> mp;

void init() {
  int id = 0;
  for(char c = 'a'; c <= 'z'; c++) mp[c] = ++id;
}

void insert(string s) {
  int u = 0;
  for(int i = 0; i < s.size(); i++) {
    int v = mp[s[i]];
    if(!ch[u][v]) ch[u][v] = ++idx;
    u = ch[u][v];
    cnt[u]++;
  }
}

int query(string s) {
  int u = 0;
  int tem = 0;
  for(int i = 0; i < s.size(); i++) {
    int v = mp[s[i]];
    if(!ch[u][v]) return tem;
    u = ch[u][v];
    tem += cnt[u];
  }
  return tem;
}
int ans = 0;
void solve() {
    int n;
    cin >> n;
    vector<string> a(n<<1);
    for(int i = 0; i < 2 * n; i++) cin >> a[i];
    sort(a.begin(),a.end());
    vector<string> b;
    for(int i = 1; i < 2 * n; i += 2) b.push_back(a[i]);
    for(int i = 0; i < b.size(); i++) insert(b[i]);
    for(int i = 0; i < 2 * n; i += 2) ans += query(a[i]);
    cout << ans << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int t = 1;
  // std::cin >> t;
  init();
  while (t--) {
    solve();
  }

  return 0;
}