#include <bits/stdc++.h>
using namespace std;

const int N=110;
const double eps=1e-6;//double精度

int n;
double a[N][N];

int gauss()
{
	int c,r;//c表示在枚举哪一列，r表示在枚举哪一行
	for(c=0,r=0;c<n;c++)
	{
		int t=r;
		for(int i=r;i<n;i++)
		{
			if(fabs(a[i][c])>fabs(a[t][c]))//定位到当前列主元的最大系数所在行 
				t=i;
		}
		
		if(fabs(a[t][c])<eps) continue;
		
		for(int i=c;i<=n;i++)	swap(a[t][i],a[r][i]);//交换这两行 
		for(int i=n;i>=c;i--)	a[r][i]/=a[r][c];//同除，系数化一 
		for(int i=r+1;i<n;i++)
		{
			if(fabs(a[i][c])>eps)
			{
				for(int j=n;j>=c;j--)
					a[i][j]-=a[r][j]*a[i][c];//相加减，消去列下面的系数 
			}
		}
		r++;
	}
	
	for(int i=n-1;i>=0;i--)//向后回代求解
	{
		for(int j=i+1;j<n;j++)
		{
			a[i][n]-=a[i][j]*a[j][n];
		}
	}
	
	if(r<n)
	{
		for(int i=r;i<n;i++)
		{
			if(fabs(a[i][n])>eps)
				return 2;//无解
		}
		return 1;//有无穷多组解
	}
	
	return 0;//有唯一解
}

int main()
{
  freopen("main.in", "r", stdin);
  freopen("ans.out", "w", stdout);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n+1;j++)
		{
			cin>>a[i][j];
		}
	}
	int t=gauss();
	if(t==0)//有唯一解
	{
		for(int i=0;i<n;i++) printf("x%d=%.2lf\n",i+1,a[i][n]);
	}
	else if(t==1)puts("0");
	else puts("-1");
	
	return 0; 
}