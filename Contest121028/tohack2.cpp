#include <bits/stdc++.h>
using namespace std;

char str[5005];
int i, n, A, B, C;

int main() {
	cin >> str;
	n = strlen(str);
	if (str[0] != 'a') {
		cout << "NO" << endl;
		return 0;
	}
	for (i = 0; i < n; ++i) 
        if (str[i] != 'a') break;
	A = i;
	for (; i < n; ++i)
		if (str[i] != 'b') break;
	if (i == n || str[i] != 'c') {
		cout << "NO" << endl;
		return 0;
	}
	B = i - A;
	for (; i < n; ++i)
		if (str[i] != 'c') break;
	if (i != n) {
		cout << "NO" << endl;
		return 0;
	}
	C = n - B - A;
	if (C != A && C != B) 
        cout << "NO" << endl;
	else 
        cout << "YES" << endl;
	return 0;
}