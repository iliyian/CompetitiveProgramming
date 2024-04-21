#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  char trump;
  cin >> n >> trump;
  vector<string> a(n * 2 + 1);
  map<char, int> cnt;
  vector<vector<int>> cards(4, vector<int>());
  string card = "CDSH";
  auto id = [&](const char &c) -> int {
    if (c == 'C') return 0;
    else if (c == 'D') return 1;
    else if (c == 'S') return 2;
    else if (c == 'H') return 3;
  };
  for (int i = 1; i <= n * 2; i++) {
    cin >> a[i];
    int x = a[i][0] - '0';
    char c = a[i][1];
    cnt[c]++;
    cards[id(c)].push_back(x);
  }

  int tcnt = cnt[trump];
  vector<pair<char, char>> ans;
  for (int i = 0; i < 4; i++) {
    if (card[i] == trump) continue;
    if (cnt[card[i]] % 2) {
      if (!tcnt) {
        cout << "IMPOSSIBLE\n";
        return;
      } else {
        ans.push_back({trump, card[i]});
        tcnt--;
        cnt[card[i]]--;
      }
    }
    for (int j = 0; j < (card[i] == trump ? tcnt : cnt[card[i]]); j += 2) {
      ans.push_back({card[i], card[i]});
    }
  }
  if (tcnt % 2) {
    cout << "IMPOSSIBLE\n";
    return;
  }
  for (int i = 0; i < tcnt; i += 2) {
    ans.push_back({trump, trump});
  }
  for (auto [l, r] : ans) {
    cout << cards[id(l)].back() << card[id(l)] << ' ';
    cards[id(l)].pop_back();
    cout << cards[id(r)].back() << card[id(r)] << '\n';
    cards[id(r)].pop_back();
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("D.in", "r", stdin);
  freopen("D.out", "w", stdout);

  int t;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}