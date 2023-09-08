#include<cstdio>
using namespace std;
const int MAXN=200010,MAXM=1000010;//注意边数要乘2
int h[MAXN],color[MAXN],tot=0;//h为邻接表中的head，tot为总边数
bool vis[MAXN];//记录是否有连接
struct Edge{//边的结构体
	int v;
	int next;//next记录这条边在邻接表中指向同端点的另一条边
}e[MAXM];
void addEdge(int u,int v){//建边
	tot++;
	e[tot].v=v;
	e[tot].next=h[u],h[u]=tot;
}
void dfs(int u){//深搜，u为原节点，保证已染色
	for(int k=h[u];k;k=e[k].next){//邻接表查找
		int v=e[k].v;
		color[v]=color[u]%2+1;//公式
	}
}
int main(){
  freopen("data.in", "r", stdin);
	int n,m;
	scanf("%d%d",&n,&m);
	while(m--){
		int uu,vv;
		scanf("%d%d",&uu,&vv);
		vis[uu]=1,vis[vv]=1;//记录
		addEdge(uu,vv);addEdge(vv,uu);//建边
	}
	for(int i=1;i<=n;i++)//判断是否不行
	    if(!vis[i]){
	    	printf("NIE\n");//输出
	    	return 0;//返回
		}
	printf("TAK\n");//直接输出
	for(int i=1;i<=n;i++)//每个点都搜一遍
		if(!color[i]){//没搜过
			color[i]=1;//先设为白点
			dfs(i);//开搜
		}
	for(int i=1;i<=n;i++){//输出
		if(color[i]==1) printf("K\n");
		else printf("S\n");
	}
	return 0;//华丽结束
}