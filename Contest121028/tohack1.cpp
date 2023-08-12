#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, k;
    cin >> n >> k;
	if (k == n || k == 0) {
		cout << "0 0" << endl;
		return 0;
	}
	cout << "1 ";
	if (k * 3 <= n)
        cout << 2 * k << endl;
	else
        cout << n - k << endl;
	return 0;
}