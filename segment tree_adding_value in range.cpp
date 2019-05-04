#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <cstring>
#include <climits>
#include <iostream>
#include <iomanip>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <sstream>
#include <algorithm>

using  namespace  std;

#define pf printf
#define sc scanf
#define PI acos(-1.0)
#define MAX 10000007
#define EPS 1e-9
#define mem(a,b) memset(a,b,sizeof(a))
#define gcd(a,b) __gcd(a,b)
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define Sort(x) sort(x.begin(),x.end())
#define FOR(i, b, e) for(int i = b; i <= e; i++)
#define pr(x) cout<<x<<"\n"
#define pr2(x,y) cout<<x<<" "<<y<<"\n"
#define pr3(x,y,z) cout<<x<<" "<<y<<" "<<z<<"\n";
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)

typedef  long long ll;
typedef  pair <int, int> pii;
typedef  pair <double , double> pdd;
typedef  pair <ll , ll > pll;
typedef  vector <int> vi;
typedef  vector <pii> vpii;
typedef  vector <ll > vl;
using namespace std;
#define mx 500001
int n;
struct info
{
    int prop,sum;
} tree[mx*3];
int query(int node,int b,int e,int i,int j,int carry=0)
{
    int Left,Right,mid,p1,p2;
    if (i > e || j < b) return 0;
    if(b>=i && e<=j) return tree[node].sum+carry*(e-b+1);
    Left=node<<1;
    Right=(node<<1)+1;
    mid=(b+e)>>1;

    p1 = query(Left, b,mid, i, j, carry+tree[node].prop);
    p2 = query(Right, mid+1, e, i, j,carry+tree[node].prop);
    return p1+p2;
}
void update(int node,int b,int e,int i,int j,int x)
{
    int Left,Right,mid;
    if (i > e || j < b) return;
    if (b >= i && e <= j)
    {
        tree[node].sum+=((e-b+1)*x);
        tree[node].prop+=x;
        return;
    }
    Left=node*2;
    Right=(node*2)+1;
    mid=(b+e)/2;
    update(Left,b,mid,i,j,x);
    update(Right,mid+1,e,i,j,x);
    tree[node].sum=tree[Left].sum+tree[Right].sum+(e-b+1)*tree[node].prop;
}
int main()
{
    int i,x,hi,lo,m,v,t,cs=1;
    sc("%d",&t);
    while(t--)
    {
        mem(tree,0);
        sc("%d %d",&n,&m);
        pf("Case %d:\n",cs++);
        for(i=1; i<=m; i++)
        {
            sc("%d",&x);
            if(x==0)
            {
                sc("%d%d%d",&lo,&hi,&v);
                update(1,1,n,lo+1,hi+1,v);
            }
            else
            {
                sc("%d%d",&lo,&hi);
                pf("%d\n",query(1,1,n,lo+1,hi+1));
            }
        }
    }
    return 0;
}

