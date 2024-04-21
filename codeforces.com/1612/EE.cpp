#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e5+1;
int k[MAXN],m[MAXN];
struct BucketNode {
	//统计每一个m[i]对应的k[i]之和的桶 
	int val,id;
	//val记录k[i]之和的值，id记录m[i]的值 
	inline friend bool operator <(const BucketNode &x,const BucketNode &y) {
		//按k[i]的和降序排序 
		return x.val>y.val;
	}
}	b[MAXN];
inline BucketNode mp(int val,int id) {
	//用val值和id值构造一个BucketNode 
	BucketNode ans;
	ans.val=val,ans.id=id;
	return ans;
}
struct DataNode {
	//记录答案 
	vector <int> vec; //vec记录置顶了哪些 
	double val; //val记录所求期望 
	inline void clear() {
		val=0;vec.clear();
	}
}	ans,tmp; //ans是答案,tmp是临时记录 
signed main() {
  freopen("E.in", "r", stdin);
	int n;
	scanf("%d",&n);
	for(register int i=1;i<=n;++i) scanf("%d%d",&m[i],&k[i]);
	for(register int t=1;t<=20;++t) {
		//枚举1~20中的每一个t值 
		for(register int i=0;i<MAXN;++i) b[i]=mp(0,i); //初始化 
		for(register int i=1;i<=n;++i) b[m[i]].val+=min(t,k[i]); //放进桶 
		sort(b+1,b+MAXN+1); //排序 
		tmp.clear();
		for(register int i=1;i<=t;++i) {
			//贪心，选和最大的 
			tmp.val+=b[i].val;
			tmp.vec.push_back(b[i].id);
		}
		tmp.val/=t;
		if(tmp.val>ans.val) ans=tmp; //更新答案 
	}
	//输出 
	printf("%d\n",ans.vec.size());
	for(register int i:ans.vec) printf("%d ",i);
	putchar('\n');
	return 0;
}