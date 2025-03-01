#include<bits/stdc++.h>
using namespace std;
int R()//快读 
{
	char c;int sign=1,res=0;
	while((c=getchar())>'9'||c<'0') if(c=='-') sign=-1;
	res+=c-'0';
	while((c=getchar())>='0'&&c<='9') res=res*10+c-'0';
	return res*sign;	
}
const int dx[8]={1,-1,0,0,1,1,-1,-1};
const int dy[8]={0,0,1,-1,-1,1,1,-1};
struct point//用来排序的结构体 
{
	int x,y,h;	
}a[1010*1010];
bool cmp(point x,point y)
{
	return x.h>y.h; 
} 
int n,m,ans;
int q[1010][1010];//矩阵 
bool flag[1010][1010];//记录 
void dfs(int x,int y)
{
	if(x>n||y>m||!x||!y) return;//越界 
	flag[x][y]=1;//标记 
	for(int i=0;i<8;i++)//搜索 
		if(!flag[x+dx[i]][y+dy[i]]&&q[x+dx[i]][y+dy[i]]<=q[x][y])
			dfs(x+dx[i],y+dy[i]);
}
int main()
{
  freopen("data.in", "r", stdin);
	n=R();m=R();
	int o=0;
	for(int i=1;i<=n;i++)	
		for(int j=1;j<=m;j++)
		{
			q[i][j]=R();
			a[++o].h=q[i][j];
			a[o].x=i;a[o].y=j;
		}
//以上是读入 
	sort(a+1,a+1+o,cmp);
	for(int i=1;i<=o;i++)//从最大的开始搜 
	{
		int x=a[i].x,y=a[i].y;
		if(!flag[x][y])//如果没去过 
		{
			bool f=1;
			for(int p=0;p<8;p++)//判断是否可以作为山顶 
				if(q[x][y]<q[x+dx[p]][y+dy[p]])
					f=0;
			if(f)
				dfs(x,y),ans++;//搜索出整个山丘 
		}
	}
	cout<<ans;
}

