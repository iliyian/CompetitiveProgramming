#include<bits/stdc++.h>
#define ll long long
#define N 421
using namespace std;
const ll INF = (1LL << 63)-1;
ll n, a[N], sum[N], f[N];
vector<pair<ll, ll> > dp[N][N];

ll read() {
	ll s = 0, f = 1; char ch = getchar();
	while (!isdigit(ch)) { if (ch == '-') f = -1; ch = getchar(); }
	while (isdigit(ch)) { s = s * 10 + ch - '0'; ch = getchar(); }
	return s * f;
}

ll ceil_log2(ll x) {
	if (x <= 1) return 0;
	ll c = 0, tmp = 1;
	while (tmp < x) {
		c++;
		tmp <<= 1;
	}
	return c;
}

ll val(ll l, ll r, ll m) {
	ll l1 = sum[m] - sum[l - 1];
	ll l2 = sum[r] - sum[m];
	return min(l1, l2) * ceil_log2(l1 + l2);
}

ll find(ll L, ll R, ll x) {
	ll l = 0, r = dp[L][R].size() - 1, ans = -1;
	while (l <= r) {
		ll mid = (l + r) >> 1;
		if (dp[L][R][mid].first <= x) {
			ans = mid;
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	return ans;
}

void solve() {
	n = read();
	sum[0] = 0;
	for (int i = 1; i <= n; i++) {
		a[i] = read();
		sum[i] = sum[i - 1] + a[i];
		f[i]=INF;
	}
	for (int l = 1; l <= n; l++) {
		for (int r = l; r <= n; r++) {
			dp[l][r].clear();
		}
		dp[l][l].push_back(make_pair(0, 0));
	}
	for (ll len = 2; len <= n; len++) {
		for (ll l = 1; l + len - 1 <= n; l++) {
			ll r = l + len - 1;
			for (ll m = l; m < r; m++) {
				ll w0 = abs(2 * (sum[m] - sum[l - 1]) - (sum[r] - sum[l - 1]));
				ll minl = find(l, m, w0);
				ll minr = find(m + 1, r, w0);
				if (minl != -1 && minr != -1)
				{
					dp[l][r].push_back(make_pair(w0, dp[l][m][minl].second + dp[m + 1][r][minr].second + val(l, r, m)));
					if (len==n)f[m]=dp[l][m][minl].second + dp[m + 1][r][minr].second + val(l, r, m);
				}
					
			}
			sort(dp[l][r].begin(), dp[l][r].end());
			for (int i = 1; i < dp[l][r].size(); i++) {
				dp[l][r][i].second = min(dp[l][r][i].second, dp[l][r][i - 1].second);
			}
		}
	}
	for (ll i = 1; i < n; i++) {
		if (f[i] >= INF) {
			printf("-1 ");
		} else {
			printf("%lld ", f[i]);
		}
	}
	printf("\n");
}

int main() {
	ios::sync_with_stdio(false);
	int T = read();
	while (T--) {
		solve();
	}
	return 0;
}