mt19937 R(chrono::steady_clock::now().time_since_epoch().count());
struct info{unsigned p;int v,l,r,sz;info(int v):v(v),p(R()),l(0),r(0),sz(1){}info(){}}tr[1100005];int tot,rt;
void pushup(int x){tr[x].sz=1+tr[tr[x].l].sz+tr[tr[x].r].sz;}
void split_v(int x,int &l,int &r,int v){if(!x)return void(l=r=0);if(tr[x].v<=v)l=x,split_v(tr[x].r,tr[l].r,r,v),pushup(l);else r=x,split_v(tr[x].l,l,tr[r].l,v),pushup(r);}
void split_s(int x,int &l,int &r,int s){if(!x)return void(l=r=0);if(1+tr[tr[x].l].sz<=s)l=x,split_s(tr[x].r,tr[l].r,r,s-1-tr[tr[x].l].sz),pushup(l);else r=x,split_s(tr[x].l,l,tr[r].l,s),pushup(r);}
void merge(int &x,int l,int r){if(!l)return void(x=r);if(!r)return void(x=l);if(tr[l].p>=tr[r].p)x=l,merge(tr[x].r,tr[l].r,r);else x=r,merge(tr[x].l,l,tr[r].l);pushup(x);}
void ins(int x){int p;split_v(rt,p,rt,x),tr[++tot]=info(x),merge(p,p,tot),merge(rt,p,rt);}
void del(int x){int p,q;split_v(rt,p,rt,x),split_v(p,p,q,x-1),merge(q,tr[q].l,tr[q].r),merge(p,p,q),merge(rt,p,rt);}
int rnk(int x){int p,r;split_v(rt,p,rt,x-1);r=1+tr[p].sz;merge(rt,p,rt);return r;}
int kth(int x){int p,q,r;split_s(rt,rt,p,x-1);split_s(p,q,p,1);r=tr[q].v;merge(p,q,p);merge(rt,rt,p);return r;}
int pre(int x){int p,q,r;split_v(rt,p,rt,x-1);split_s(p,p,q,tr[p].sz-1);r=tr[q].v;merge(p,p,q);merge(rt,p,rt);return r;}
int nxt(int x){int p,q,r;split_v(rt,rt,p,x);split_s(p,q,p,1);r=tr[q].v;merge(p,q,p);merge(rt,rt,p);return r;}