#include<bits/stdc++.h>//万能头文件 
using namespace std;
const int N=305;//养成好习惯，用常量开数组，多开几位 
int n,m,k,sum[N][N];//sum[i][j]为S(i，j)
char a[N][N];//图 
bool v[N][N];//标记数组 
int dx[4]={-1,0,0,1},dy[4]={0,-1,1,0};//方向数组，具体方向依次为：上，左，右，下 
struct node//定义结构体：当前时间，小明身材，x坐标，y坐标 
{
	int t,now,x,y;
}s;
void bfs()//BFS广度优先搜索 
{
	queue<node>q;//定义node型队列 
	q.push((node){0,3,3,3});//放入初始信息 
	v[3][3]=1;
	while(q.size())
	{
		s=q.front();q.pop();
		if(s.x==n-2&&s.y==n-2)
		{
			cout<<s.t;//访问到了终点(n-2,n-2)就输出当前时间，即答案 
			exit(0);//结束程序，等价于return和break; 
		}
		if(s.t==k||s.t==2*k)s.now--;//到时间身材会发生变化 
		int noww=s.now;
		for(int i=0;i<4;i++)
		{
			int xx=s.x+dx[i],yy=s.y+dy[i];//xx，yy为下一步的走向 
			if(xx-noww+1<1||xx+noww-1>n||yy-noww+1<1||yy+noww-1>n)continue;//判断小明是否越界 
			if(sum[xx+noww-1][yy+noww-1]-sum[xx+noww-1][yy-noww]-sum[xx-noww][yy+noww-1]+sum[xx-noww][yy-noww])continue;//如果小明这一个块中的和不为0，即存在障碍物，需跳过 
			if(v[xx][yy])continue;//访问过的点就不再访问了 
			v[xx][yy]=1;//标记此点已访问 
			q.push((node){s.t+1,noww,xx,yy});
		}
		if(noww>1)q.push((node){s.t+1,noww,s.x,s.y});//别忘了也可以原地不动 
	}
}
int main()
{
	ios::sync_with_stdio(false);//关闭流同步，优化时间复杂度 
  freopen("data.in", "r", stdin);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
			if(a[i][j]=='*')sum[i][j]=1;
			sum[i][j]=sum[i][j]+sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];//预处理前缀和 
		}
	bfs();
	return 0;
}