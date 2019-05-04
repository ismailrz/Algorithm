#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<string>
#include<cmath>
#include<cctype>
#include<stack>
#include<cstdlib>
#include<utility>
#include<vector>
#include<deque>
#include<queue>
#include<algorithm>

#define gcd(a,b) __gcd(a,b)
#define ff first
#define ss second
#define sc scanf
#define pf printf
#define sc1(a) cin>>a
#define sc2(a,b) cin>>a>>b
#define pr1(a) cout<<a<<endl
#define pr2(a,b) cout<<a<<" "<<b<<endl
#define endl '\n'
#define pii pair(int,int)
#define pi acos(-1.0)
#define Sin(a) sin((pi*a)/180);
#define siz 1000001
#define mem(ar) memset(ar,0,sizeof ar)
#define one(x) __builtin_popcount(x)
typedef long long li;

using namespace std;
#define mx 100001
li  n;
struct info
{
    li  prop,sum;
} tree[mx*3+1];
/*
li gcd(li a, li b)
{
    if(b == 0)return a;
    return gcd(b, a%b);
}
*/
void pushDown(int p, int beg, int end)
{
    if(tree[p].prop ==-1)return;

    int mid = (beg + end) >> 1;
    tree[2*p].sum = (mid-beg+1)*tree[p].prop;
    tree[2*p+1].sum = (end-mid)*tree[p].prop;
    tree[2*p].prop = tree[2*p+1].prop = tree[p].prop;
    tree[p].prop =-1;
}
li  query(li  node,li  b,li  e,li  i,li  j)
{
    li  Left,Right,mid,p1,p2;
    if (i > e || j < b) return 0;
    if(b>=i and e<=j)
        return tree[node].sum;
    pushDown(node,b,e);
    Left=node<<1;
    Right=(node<<1)+1;
    mid=(b+e)>>1;
    p1= query(Left, b,mid, i, j);
    p2= query(Right, mid+1, e, i, j);
    return p1+p2;
}
void update(li  node,li  b,li  e,li  i,li  j,li  x)
{
    li  Left,Right,mid;
    if (i > e || j < b) return;
    if (b >= i && e <= j)
    {
        tree[node].sum=((e-b+1)*x);
        tree[node].prop=x;
        return;
    }
    pushDown(node,b,e);
    Left=node*2;
    Right=(node*2)+1;
    mid=(b+e)/2;
    update(Left,b,mid,i,j,x);
    update(Right,mid+1,e,i,j,x);
    tree[node].sum=tree[Left].sum+tree[Right].sum;//e-b+1)*tree[node].prop;
}
int  main()
{
    li  i,x,hi,lo,m,v,t,sum,num,cg,cs=1;
    sc("%lld",&t);
    while(t--)
    {
        sc("%lld %lld",&n,&m);
        for(i=0; i<=3*n; i++)
        {
            tree[i].sum=0;
            tree[i].prop=-1;
        }
        pf("Case %lld:\n",cs++);
        for(i=1; i<=m; i++)
        {
            sc("%lld",&x);
            if(x==1)
            {
                sc("%lld%lld%lld",&lo,&hi,&v);
                update(1,1,n,lo+1,hi+1,v);
            }
            else
            {
                sc("%lld%lld",&lo,&hi);
                sum=query(1,1,n,lo+1,hi+1);
                num=hi-lo+1;
                cg=gcd(sum,num);
                sum=sum/cg;
                num=num/cg;
                if(num==1)
                    pf("%lld\n",sum);
                else
                {
                    pf("%lld",sum);
                    pf("/");
                    pf("%lld\n",num);
                }
            }
        }
    }
    return 0;
}
