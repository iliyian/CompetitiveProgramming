#include <bits/stdc++.h>
using namespace std;

struct Player {
  int s, w, i;
} players[200010], winners[100010], losers[100010];

bool operator < (const Player &a, const Player &b) {
  if (a.s == b.s) return a.i < b.i; return a.s > b.s;
}

int main() {
  int N, R, Q;
  cin >> N >> R >> Q;
  for (int i = 0; i < N * 2; i++) {
    cin >> players[i].s;
    players[i].i = i + 1;
  }
  for (int i = 0; i < N * 2; i++) {
    cin >> players[i].w;
  }
  int widx = 0, lidx = 0;
  sort(players, players + N * 2);
  for (int t = 0; t < R; t++) {
    for (int i = 0; i < N * 2; i += 2) {
      Player &a = players[i], &b = players[i + 1];
      if (a.w > b.w) a.s++, winners[widx++] = a, losers[lidx++] = b;
      else b.s++, winners[widx++] = b, losers[lidx++] = a;
    }
    merge(winners, winners + N, losers, losers + N, players);
    widx = lidx = 0;
  }
  // sort(players, players + N * 2);
  cout << players[Q - 1].i;
  return 0;
}