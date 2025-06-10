#include <iostream>
#include <vector>
using namespace std;

long long xor_to(long long k) {
    if (k == 0) return 0;
    long long mod = k % 4;
    if (mod == 0) return k;
    else if (mod == 1) return 1;
    else if (mod == 2) return k + 1;
    else return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int total = n + m;
        if (total % 4 != 3) {
            cout << -1 << '\n';
            continue;
        }
        
        vector<vector<long long>> mat(n, vector<long long>(m, 0));
        
        // 设置最后一列的前n-1行
        for (int i = 0; i < n - 1; i++) {
            mat[i][m - 1] = i + 1;
        }
        
        // 设置最后一行的前m-1列
        for (int j = 0; j < m - 1; j++) {
            mat[n - 1][j] = (long long)n + j + 1;
        }
        
        // 计算右下角元素
        long long L = n + 1;
        long long R = n + m - 1;
        long long x = 0;
        if (L <= R) {
            x = xor_to(R) ^ xor_to(L - 1);
        }
        mat[n - 1][m - 1] = x ^ n;
        
        // 输出矩阵
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << mat[i][j];
                if (j < m - 1) cout << ' ';
            }
            cout << '\n';
        }
    }
    return 0;
}