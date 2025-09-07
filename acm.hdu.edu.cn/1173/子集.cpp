#include<bits/stdc++.h>
#define ll long long
#define N 51
#define MAX_SIZE 20
using namespace std;

// 手写冒泡排序：对数组arr的前len个元素进行排序
void bubble_sort(ll* arr, int len) {
    for (int i = 0; i < len - 1; i++) {
        for (int j = 0; j < len - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]); // 交换元素
            }
        }
    }
}

// 手写unique函数：移除相邻重复元素，返回新的有效长度
int my_unique(ll* arr, int len) {
    if (len <= 1) return len;
    int k = 0;
    for (int i = 1; i < len; i++) {
        if (arr[i] != arr[k]) {
            arr[++k] = arr[i];
        }
    }
    return k + 1;
}

int n;
ll a[N], ans;
ll b0[MAX_SIZE], b1[MAX_SIZE], b2[MAX_SIZE], b3[MAX_SIZE];
int b0_size, b1_size, b2_size, b3_size;

void solve() {
    b0_size = 0;
    b1_size = 0;
    b2_size = 0;
    b3_size = 0;
    ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int len1 = n / 4, len2 = n / 4, len3 = n / 4, len4 = n - len1 - len2 - len3;
    bool flag;
    ll x = 0;

    // 处理第一部分
    for (int i = 0; i < (1 << len1); i++) {
        flag = 1;
        for (int j = 0; j < len1 - 1; j++) {
            if ((i & (1 << j)) && (i & (1 << (j + 1)))) {
                flag = 0;
                break;
            }
        }
        x = 0;
        for (int j = 1; j <= len1; j++) {
            if ((i >> (j - 1)) & 1) x ^= a[j];
        }
        if (flag) {
            if (i & (1 << (len1 - 1))) b1[b1_size++] = x;
            else b0[b0_size++] = x;
        }
    }
    bubble_sort(b0, b0_size); // 替换为冒泡排序
    bubble_sort(b1, b1_size);
    b0_size = my_unique(b0, b0_size);
    b1_size = my_unique(b1, b1_size);

    // 处理第二部分
    for (int i = 0; i < (1 << len2); i++) {
        flag = 1;
        for (int j = 0; j < len2 - 1; j++) {
            if ((i & (1 << j)) && (i & (1 << (j + 1)))) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            x = 0;
            for (int j = 1; j <= len2; j++) {
                if ((i >> (j - 1)) & 1) x ^= a[len1 + j];
            }
            if (i & 1) {
                for (int k = 0; k < b0_size; k++) b3[b3_size++] = x ^ b0[k];
            } else {
                for (int k = 0; k < b0_size; k++) b2[b2_size++] = x ^ b0[k];
                for (int k = 0; k < b1_size; k++) b2[b2_size++] = x ^ b1[k];
            }
        }
    }
    b0_size = 0;
    b1_size = 0;
    bubble_sort(b2, b2_size);
    bubble_sort(b3, b3_size);
    b2_size = my_unique(b2, b2_size);
    b3_size = my_unique(b3, b3_size);

    // 处理第三部分
    for (int i = 0; i < (1 << len3); i++) {
        flag = 1;
        for (int j = 0; j < len3 - 1; j++) {
            if ((i & (1 << j)) && (i & (1 << (j + 1)))) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            x = 0;
            for (int j = 1; j <= len3; j++) {
                if ((i >> (j - 1)) & 1) x ^= a[len1 + len2 + j];
            }
            if (i & 1) {
                for (int k = 0; k < b2_size; k++) b1[b1_size++] = x ^ b2[k];
            } else {
                for (int k = 0; k < b2_size; k++) b0[b0_size++] = x ^ b2[k];
                for (int k = 0; k < b3_size; k++) b0[b0_size++] = x ^ b3[k];
            }
        }
    }
    b2_size = 0;
    b3_size = 0;
    bubble_sort(b0, b0_size);
    bubble_sort(b1, b1_size);
    b0_size = my_unique(b0, b0_size);
    b1_size = my_unique(b1, b1_size);

    // 处理第四部分
    for (int i = 0; i < (1 << len4); i++) {
        flag = 1;
        for (int j = 0; j < len4 - 1; j++) {
            if ((i & (1 << j)) && (i & (1 << (j + 1)))) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            x = 0;
            for (int j = 1; j <= len4; j++) {
                if ((i >> (j - 1)) & 1) x ^= a[len1 + len2 + len3 + j];
            }
            if (i & 1) {
                for (int k = 0; k < b0_size; k++) ans = max(ans, x ^ b0[k]);
            } else {
                for (int k = 0; k < b0_size; k++) ans = max(ans, x ^ b0[k]);
                for (int k = 0; k < b1_size; k++) ans = max(ans, x ^ b1[k]);
            }
        }
    }
    cout << ans << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}