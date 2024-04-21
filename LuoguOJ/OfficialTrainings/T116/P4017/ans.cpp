#include<bits/stdc++.h>
#include<cctype>
#pragma GCC optimize(2)
#define ll long long
#define rg register
#define New int
//上面这些花里胡哨的东西请忽略 
using namespace std;
inline New read()//快速读入
{
    New X = 0,w = 0;
	char ch = 0;
	while(!isdigit(ch))
	{
		w |= ch == '-';
		ch=getchar();
	}
    while(isdigit(ch))
	{
		X = (X << 3) + (X << 1) + (ch ^ 48);
		ch = getchar();
	}
    return w ? -X : X;
}
char F[200] ;
inline void write(New x) //快速输出
{
	if(x == 0)
	{
		putchar('0');
		return;
	}
	New tmp = x > 0 ? x : -x;
	int cnt = 0;
	if(x < 0)
		putchar( '-' );
	while(tmp > 0)
	{
		F[cnt++] = tmp % 10 + '0';
		tmp /= 10;
	}
	while(cnt > 0)
		putchar(F[--cnt]) ;
}
const int N = 5e3 + 2; //定义常量大小 
const int mod = 80112002; //定义最终答案mod的值 

int n, m; //n个点 m条边 
int in[N], out[N]; //每个点的入度和出度 
vector<int>nei[N]; //存图，即每个点相邻的点 
queue<int>q; //拓扑排序模板所需队列 
int ans; //答案 
int num[N]; //记录到这个点的类食物连的数量，可参考图 


signed main()
{
	n = read(), m = read();
	for(rg int i = 1; i <= m; ++i)
	{ //输入边 
		int x = read(), y = read();
		++in[y], ++out[x]; //右节点入度+1,左节点出度+1
		nei[x].push_back(y); //建立一条单向边
	}
	for(rg int i = 1; i <= n; ++i) //初次寻找入度为0的点(最佳生产者)
		if(!in[i])
		{ //是最佳生产者
			num[i] = 1; //初始化
			q.push(i); //压入队列 
		}
	while(!q.empty())
	{ //只要还可以继续Topo排序 
		int tot = q.front();//取出队首 
		q.pop();//弹出
		int len = nei[tot].size(); 
		for(rg int i = 0;i < len; ++i)
		{ //枚举这个点相邻的所有点
			int next = nei[tot][i]; //取出目前枚举到的点 
			--in[next];//将这个点的入度-1(因为目前要删除第tot个点) 
			num[next] = (num[next] + num[tot]) % mod;//更新到下一个点的路径数量 
			if(in[next] == 0)q.push(nei[tot][i]);//如果这个点的入度为0了,那么压入队列 
		}
	}
	for(rg int i = 1; i <= n; ++i) //寻找出度为0的点(最佳消费者) 
		if(!out[i]) //符合要求 
			ans = (ans + num[i]) % mod;//累加答案 
	write(ans);//输出 
	return 0;//end 
}