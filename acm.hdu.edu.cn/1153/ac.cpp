#include<bits/stdc++.h>
typedef long long LL;
typedef unsigned long long ULL;
#define rep(i, a, b) for(int i = (a); i <= (b); i ++)
#define per(i, a, b) for(int i = (a); i >= (b); i --)
#define Ede(i, u) for(int i = head[u]; i; i = e[i].nxt)
using namespace std;

inline LL read() {
	LL x = 0, f = 1; char c = getchar();
	while(c < '0' || c > '9') f = (c == '-') ? - 1 : 1, c = getchar();
	while(c >= '0' && c <= '9') x = x * 10 + c - 48, c = getchar();
	return x * f;
}

LL find(int o, LL k, LL b, LL L, LL R) {
	while(L < R) {
		LL x = (L + R + 1) >> 1;
		if((k * x + b) >> o & 1) R = x - 1; else L = x;
	}
	return L;
}

void solve() {
	LL k = read(), b = read(), c = read(), v = read();
	LL L = 0, R = ((1LL << 62) - 1 - b) / k;
	LL ans = 0;
	per(o, 61, 0) {
		if(L > R) break;
		LL m = find(o, k, b, L - 1, R);
		// cerr << "now " << o << ' ' << m << endl;
		if(v >> o & 1) {
			if(c >> o & 1) ans += R - m, R = m;
			else ans += m - L + 1, L = m + 1;
		} else {
			if(c >> o & 1) L = m + 1; else R = m;
		}
	}
	if(L <= R) ans += R - L + 1;
	printf("%lld\n", ans);
}

int main() {
	int T = read(); while(T --) solve(); return 0;
}
