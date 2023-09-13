#include<bits/stdc++.h>
using namespace std;

int n, k, m, Min = 0x7fffffff;
int f[501][501];
//f[i][l]：以i作末尾，选了l本书时的最小花费

struct info
{
	int h, w;
}a[1001];

bool cmp(const info & x, const info & y)
{
	return x.h < y.h;
}

int main()
{
  freopen("data.in", "r", stdin);
	cin >> n >> k;
	m = n - k;//选取m本书 
	for(int i = 1; i <= n; i++)
		scanf("%d %d", &a[i].h, &a[i].w);
		
	sort(a+1, a+n+1, cmp);//高度决定顺序
	
	memset(f, 20, sizeof(f));//初始极大，能缩小就缩小
	
	for(int i = 1; i <= n; i++)
		f[i][1] = 0;
	//单独选择任何书都不会有花费
	 
	for(int i = 2; i <= n; i++)//试着放第i本的时候 
		for(int j = 1; j <= i-1; j++)//尝试与前面第j本相邻
			for(int l = 2; l <= min(i, m); l++)//放下第i本时，能从之前长1的队列继承为长2的队列，也能从之前长2的队列继承为长3的队列……l表示放下后的长度
            //显然试到第i本时，长度不会超过i，也不会超过m，m是最终需要的长度
				 
				f[i][l] = min(f[i][l], f[j][l-1] + abs(a[i].w - a[j].w/*这是尝试相邻的书本*/));//放第i本继承到长度为l，总花费越小越好
		
	for(int i = m; i <= n; i++)
		Min = min(Min, f[i][m]);//i的循环的意思是：以m结尾的队列，可能最小，以m+1结尾的队列也可能的……以n结尾的队列也可能。
	
	printf("%d\n", Min);
	return 0;
}

