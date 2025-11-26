#include<iostream>
#include<string>
#include<cstring>
#define MAXN 205
using namespace std;

int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}}; //N E S W
bool adj[4][4];

bool check_cir() {
	bool vis[4] = {0}, onPath[4] = {0};
	bool res = false;
	auto dfs = [&](auto dfs, int u) -> void {
		vis[u] = true;
		onPath[u] = true;
		for (int v = 0; v < 4; v++) {
			if (!adj[u][v]) continue;
			if (onPath[v]) res = true;
			if (!vis[v]) dfs(dfs, v);
		}
		onPath[u] = false;
	};
	for (int u = 0; u < 4; u++)
		if (!vis[u])
			dfs(dfs, u);
	return res;
}

string mp[MAXN];

void solve() {
	int r, c;
	cin >> r >> c;
	for (int i = 0; i < r; i++) cin >> mp[i];
	string mov;
	cin >> mov;
	
	int x = 0, y = 0;
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			if (mp[i][j] == 'S') {
				x = i;
				y = j;
				break;
			}
	
	int ans = 0;
  int tot = 0;
	for (char ch : mov) {
//		cerr<<"** "<<x<<' '<<y<<endl;
		int d;
		if (ch == 'N') d = 0;
		else if (ch == 'E') d = 1;
		else if (ch == 'S') d = 2;
		else d = 3;
		
		auto get_adj = [&]() {
			for (int i = 0; i < 4; i++) {
				if (i == d) continue;
				auto [dx, dy] = dir[i];
				int nx = x + dx, ny = y + dy;
				if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
				if (mp[nx][ny] == '#') continue;
				adj[d][i] = 1;
//				cerr<<"# "<<d<<' '<<i<<endl;
			}
		};
		
		get_adj();
		
		if (check_cir()) {
      std::cerr << ch << ' ' << tot << '\n';
			ans++;
			memset(adj, 0, sizeof(adj));
			get_adj();
		}
		
    tot++;
		x += dir[d][0];
		y += dir[d][1];
	}
	
	cout << ans;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	solve();
	return 0;
}
/*
5 3
#..
...
...
...
.S.
NNEN
*/