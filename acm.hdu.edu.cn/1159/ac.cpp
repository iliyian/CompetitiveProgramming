#include <bits/stdc++.h>
#define N 100005
#define M 1000005
using namespace std;
int min_prime[M];
vector<int> primes;
uint64_t prime_hash[M];

void sieve() {
	memset(min_prime, 0, sizeof(min_prime));
	for (int i = 2; i < M; ++i) {
		if (!min_prime[i]) {
			min_prime[i] = i;
			primes.push_back(i);
			for (int j = 2 * i; j < M; j += i) {
				if (!min_prime[j]) {
					min_prime[j] = i;
				}
			}
		}
	}
	mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
	for (int p : primes) {
		prime_hash[p] = rng();
	}
}

uint64_t calc(int x)
{
	uint64_t state = 0;
	while (x > 1)
	{
		int p = min_prime[x],cnt = 0;
		while (x % p == 0)x /= p,cnt++;
		if (cnt % 2 == 1)state ^= prime_hash[p];
	}
	return state;
}
int n,a[N];
void solve()
{
	cin>>n;
	for (int i=0;i<n;i++)cin>>a[i];
	unordered_map<uint64_t,int> hx;
	hx[0] = -1;
	uint64_t c = 0;
	int maxn = 0, L = -1, R = -1;
	for (int i=0;i<n;i++)
	{
		c ^= calc(a[i]);
		if (hx.find(c) != hx.end())
		{
			int j = hx[c],len = i - j;
			if (len > maxn || (len == maxn && (j + 1) < L))maxn = len,L = j + 2,R = i + 1;
		}
		else hx[c] = i;
	}
	if (maxn == 0)cout << "-1 -1"<<endl;
	else cout<<L<<" "<<R<<endl;
}
int main() {
	ios::sync_with_stdio(false);
	sieve(); 
	int T;
	cin>>T;
	while(T--)solve();
	return 0;
}
