// date: 2024-06-29 21:19:38
// tag: 贪心。模拟

#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("C.in", "r", stdin);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int asum = 0, bsum = 0, c = 0;
		vector<int> a(n), b(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> b[i];
		}
		for (int i = 0; i < n; i++) {
			if (a[i] > b[i]) {
				asum += a[i];
			} else if (a[i] < b[i]) {
				bsum += b[i];
			} else if (a[i] == 1) {
				c++;
			} else if (a[i] == -1) {
				c++;
				asum--, bsum--;
			}
		}
		cout << min({asum + c, bsum + c, (asum + bsum + c) >> 1}) << '\n';
	}
}