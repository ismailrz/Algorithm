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
#define endl '\n'
#define pii pair(int,int)
#define pi acos(-1.0)
#define Sin(a) sin((pi*a)/180);
#define siz 1000001
#define mem(ar) memset(ar,0,sizeof ar)
#define one(x) __builtin_popcount(x)
using namespace std;
typedef long long ll;
int mint[siz],maxt[siz];
int tree[1000001];
void build_tree(int node, int s, int e, int id, int value)
{
    if(id < s || id > e || s > e) return;
    if(s == e)
    {
        mint[node]=value;
        maxt[node]=value;
        return;
    }
    build_tree(node*2,s,(s+e)/2,id,value);
    build_tree(node*2+1,(s+e)/2+1,e,id,value);
    mint[node] = min(mint[node*2], mint[node*2+1]);
    maxt[node] = max(maxt[node*2],maxt[node*2+1]);
}

int query_min(int node, int a, int b, int i, int j)
{
    int q1,q2,res;
    if(a > b || a > j || b < i) return 99999999;
    if(a >= i && b <= j)
        return mint[node];
    q1 = query_min(node*2, a, (a+b)/2, i, j);
    q2 = query_min(1+node*2, 1+(a+b)/2, b, i, j);
    res  = min(q1, q2);
    return res;
}
int query_max(int node, int a, int b, int i, int j)
{
    int q1,q2,res;
    if(a > b || a > j || b < i) return -99999999;
    if(a >= i && b <= j)
        return maxt[node];
    q1 = query_max(node*2, a, (a+b)/2, i, j);
    q2 = query_max(1+node*2, 1+(a+b)/2, b, i, j);
    res  = max(q1, q2);
    return res;
}

int main()
{
    int i,j,n,x,y,m,t,d,cs=1;
    sc("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&d);
        for(i=0; i<n; i++)
        {
            scanf("%d",&x);
            build_tree(1, 0, n-1,i,x);
        }
        int ans = 0;
        for(int i = 1; i+d-1 <= n; i++ )
            ans = max(query_max(1, 1, n,  i, i+d-1) - query_min(1, 1, n,  i, i+d-1), ans);
        printf("Case %d: %d\n", cs++, ans);
    }
}
