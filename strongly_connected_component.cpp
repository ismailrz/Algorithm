/******************************************************************
 *                   BISMILLAHIR RAHMANIR RAHIM                   *
 *                     Saddam Hossain shishir                     *
 *       Hajee Mohammad Danesh Science & Technology University    *
 *                                                                *
 ***************************************************************** */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<string>
#include<set>
#include<cmath>
#include<cctype>
#include<stack>
#include<cstdlib>
#include<utility>
#include<vector>
#include<deque>
#include<queue>
#include<algorithm>

#define sc scanf
#define si(t) scanf("%d",&t)
#define sl(t) scanf("%I64d",&t)
#define sii(a,b) scanf("%d%d",&a,&b)

#define P(a) printf("%d\n",a)
#define PLN(a) printf("%I64d ",a)
#define pf printf

#define gcd(a,b) __gcd(a,b)
#define ff first
#define ss second
#define pr1(a) cout<<a<<endl
#define pr2(a,b) cout<<a<<" "<<b<<endl

#define pii pair<int,int>
#define pi acos(-1.0)
#define PI 3.1415926535897932385
#define Sin(a) sin((pi*a)/180)
#define siz 1000001
#define mem(ar) memset(ar,0,sizeof ar)
#define one(x) __builtin_popcount(x)
typedef long long ll;
using namespace std;
vector<int>ve[siz],ve2[siz];
int vis[siz];
stack<int>stk;
int cnt,in[siz],out[siz];
int ar[siz],indi[siz];
void dfs(int src)
{
    if(vis[src]==1) return;
    vis[src]=1;
    for(int i=0; i<ve[src].size(); i++)
    {
        int v=ve[src][i];
        dfs(v);
    }
    stk.push(src);
}
void dfs2(int src)
{
    if(vis[src]==1) return;
    vis[src]=1;
    for(int i=0; i<ve2[src].size(); i++)
        dfs2(ve2[src][i]);
    ar[src]=cnt;
    cout<<src;
}
void SCC()
{
    while(!stk.empty())
    {
        int u=stk.top();
        stk.pop();
        if(vis[u]==0)
        {
            dfs2(u);
            cnt++;
            cout<<endl;
        }
    }
}
int main()
{
    int i,j,n,m,x,y,r,t,cs=1;        /// only needed for directed graph.
    scanf("%d%d",&n,&m);
    mem(vis);
    for(i=1; i<=n; i++)
    {
        ve[i].clear();
        ve2[i].clear();
    }
    for(i=0; i<m; i++)
    {
        scanf("%d%d",&x,&y);
        ve[x].push_back(y);
        ve2[y].push_back(x);           /// all guise
    }
    mem(vis);
    for(i=1; i<=n; i++)
    {
        if(vis[i]==0)
            dfs(i);
    }
    mem(vis);
    SCC();
    cout<<endl<<cnt;// cnt is how many ssc are exit in directed graph.
}
/*
7
8
2 3
3 1
1 2
3 5
5 6
6 4
4 5
7 6


10 13
1 2
1 3
2 4
4 5
2 5
3 6
7 6
7 3
8 1
5 9
9 10
10 5
5 8
*/
