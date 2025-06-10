#include <bits/stdc++.h>
using namespace std;

void computeHeightMap(vector<int> &a, vector<vector<int>> &id, vector<vector<int>> &block, int n)
{
    for (int i = 0; i < 2 * n - 1; ++ i)
    {
        int y = i, height = n;
        int bx = max(0, n - i - 1), by = max(0, i - n + 1);
        for (int x = abs(n - i - 1); x < 4 * n - 1 - abs(n - i - 1); x += 2)
        {
            if (a[id[x][y]] == id[x][y+1])
            {
                block[bx][by] = height;
                bx ++; by ++;
            }
            else
                height --;
        }
    }
}

void solve()
{

    int n; cin >> n;
    vector<vector<int>> id(4 * n - 1, vector<int>(2 * n, 0));
    
    int index = 1;
    for (int i = 0; i < n; ++ i)
    {
        int x = i, y = n - i - 1, tag = 0;
        for (int j = 0; j < 2 * (n + i) + 1; ++ j)
        {
            id[x][y] = index ++;
            x += tag;
            y += 1 - tag;
            tag = 1 - tag;
        }
    }
    for (int i = n - 1; i >= 0; -- i)
    {
        int x = n + 2 * (n - i - 1), y = 0, tag = 1;
        for (int j = 0; j < 2 * (n + i) + 1; ++ j)
        {
            id[x][y] = index ++;
            x += tag;
            y += 1 - tag;
            tag = 1 - tag;
        }
    }

    // for (int i = 0; i < 4 * n - 1; ++ i)
    // {
    //     for (int j = 0; j < 2 * n; ++ j)
    //         cout << id[i][j] << " ";
    //     cout << endl;
    // }

    vector<int> a(6 * n * n + 1);
    for (int i = 1; i <= 6 * n * n; ++ i)
        cin >> a[i];

    vector<vector<int>> block1(n, vector<int>(n, 0));
    computeHeightMap(a, id, block1, n);

    // for (int i = 0; i < n; ++ i)
    // {
    //     for (int j = 0; j < n; ++ j)
    //         cout << block1[i][j] << " ";
    //     cout << endl;
    // }

    int sum1 = 0;
    for (int i = 0; i < n; ++ i)
        for (int j = 0; j < n; ++ j)
            sum1 += block1[i][j];

    for (int i = 1; i <= 6 * n * n; ++ i)
        cin >> a[i];

    vector<vector<int>> block2(n, vector<int>(n, 0));
    computeHeightMap(a, id, block2, n);

    // for (int i = 0; i < n; ++ i)
    // {
    //     for (int j = 0; j < n; ++ j)
    //         cout << block2[i][j] << " ";
    //     cout << endl;
    // }

    int sum2 = 0;
    for (int i = 0; i < n; ++ i)
        for (int j = 0; j < n; ++ j)
            sum2 += block2[i][j];

    int same = 0;
    for (int i = 0; i < n; ++ i)
        for (int j = 0; j < n; ++ j)
            same += min(block1[i][j], block2[i][j]);

    cout << (sum1 - same) + (sum2 - same) << "\n";

}

int main()
{

    // freopen("../2_.in", "r", stdin);
    // freopen("../2_std.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T = 1; cin >> T;
    while (T --) solve();
    return 0;
}

/*
1
2
2 1 4 3 11 13 8 7 10 9 5 19 6 15 14 22 18 17 12 21 20 16 24 23
2 1 9 5 4 13 8 7 3 11 10 19 6 15 14 17 16 24 12 21 20 23 22 18

*/
