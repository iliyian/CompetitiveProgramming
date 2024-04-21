//By:Luckyblock
//バカって言うなぁ
#include <cstdio>
#include <cstring>
#include <ctype.h>
#define max(a, b) (a > b ? a : b)
const int MARX = 2e5 + 10;
const int INF = 2e9;
//=============================================================
int N, L, R, A[MARX], ans, f[MARX];//设 f[i]: 到达位置 i 时最大的价值和
int que[MARX], head = 1, tail = 1;//单调队列, 内部元素为位置 
//=============================================================
inline int read()
{
    int s = 1, w = 0; char ch = getchar();
    for(; !isdigit(ch); ch = getchar()) if(ch == '-') s = -1;
    for(; isdigit(ch); ch = getchar()) w = (w << 1) + (w << 3) + (ch ^ '0');
    return s * w;
}
void Insert(int i)//插入操作 
{
	for(; f[i] >= f[que[tail]] && tail >= head; ) tail --;//弹出权值和较小的 队尾元素 
	que[++ tail] = i;//入队 
}
int query(int x)
{
	for(; que[head] + R < x; ) head ++;//弹出队首 不可到达x位置的 不合法元素 
	return que[head];//回答询问 
}
//=============================================================
int main()
{
  freopen("data.in", "r", stdin);
	memset(f, 128, sizeof(f));//初始化极小值 (每个字节赋128会导致自然溢出 
	f[0] = 0, ans = - INF; //初始化, 将0位置权值和 赋为0  
	N = read(), L = read(), R = read();
	for(int i = 0; i <= N; i ++) A[i] = read();
	
	for(int i = L; i <= N; i ++)
	{
	  Insert(i - L); //将最后一个 能够转移到i的位置 加入单调队列 
	  int from = query(i);//找到队首 权值和最大的位置 
	  f[i] = f[from] + A[i];//进行转移 
	  if(i + R > N) ans = max(ans, f[i]);//判断i能够跳到对岸, 计算答案 
	}
	printf("%d", ans);
	return 0;
}