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
#define pb push_back
#define pii pair<int,int>
#define mk make_pair
#define pi acos(-1.0)
#define PI 3.1415926535897932385
#define Sin(a) sin((pi*a)/180)
#define siz 1000001
#define mem(ar) memset(ar,0,sizeof ar)
#define one(x) __builtin_popcount(x)
typedef long long ll;
using namespace std;

//int dx[]= {-1,-1,0,0,1,1};
//int dy[]= {-1,0,-1,1,0,1};
//int dx[]= {0,0,1,-1};/*4 side move*/
//int dy[]= {-1,1,0,0};/*4 side move*/
//int dx[]= {1,1,0,-1,-1,-1,0,1};/*8 side move*/
//int dy[]= {0,1,1,1,0,-1,-1,-1};/*8 side move*/
//int dx[]={1,1,2,2,-1,-1,-2,-2};/*knight move*/
//int dy[]={2,-2,1,-1,2,-2,1,-1};/*knight move*/

//'A'=65, 'a'=97 '0'=48


map<ll,bool>visi;
int ar[siz];
int Set(int N,int pos)
{
    return N=N | (1<<pos);
}
int reset(int N,int pos)
{
    return N= N & ~(1<<pos);
}
bool check(int N,int pos)
{
    return (bool)(N & (1<<pos));
}
#define mx 100002
int L[mx];
int sparse_t[mx][22],sparse_t_max[mx][22],ct[mx],sparse_t_mn[mx][22];
vector<int>cost[100001];
int T[mx];
vector<int>g[mx];
//Complexity: O(NlgN,lgN)
int mxxx,mnnn,vis[siz];
void dfs(int from,int u,int dep,int cst)
{

    T[u]=from;   ///T store parent of child
    L[u]=dep;    /// L store level of node
    ct[u]=cst;
    if(vis[u]==1) return;
    vis[u]=1;
    for(int i=0; i<(int)g[u].size(); i++)
    {
        int v=g[u][i];
        if(v==from) continue;
        dfs(u,v,dep+1,cost[u][i]);
    }
}

void lca_query(int N, int p, int q)
{
    int tmp, log, i;
    if (L[p] < L[q])
        tmp = p, p = q, q = tmp;

    log=1;
    while(1)
    {
        int next=log+1;
        if((1<<next)>L[p])break;
        log++;
    }
    for (i = log; i >= 0; i--)
    {
        if (L[p] - (1 << i) >= L[q])
        {
            mxxx=max(mxxx,sparse_t_max[p][i]);
            mnnn=min(mnnn,sparse_t_mn[p][i]);
            p = sparse_t[p][i];
        }
    }
    if (p == q)
    {
        return;
    }
    for (i = log; i >= 0; i--)
    {
        if (sparse_t[p][i] != -1 && sparse_t[p][i] != sparse_t[q][i])
        {
            mxxx=max(mxxx,sparse_t_max[p][i]);
            mxxx=max(mxxx,sparse_t_max[q][i]);
            mnnn=min(mnnn,sparse_t_mn[p][i]);
            mnnn=min(mnnn,sparse_t_mn[q][i]);
            p = sparse_t[p][i], q = sparse_t[q][i];
        }
    }
    mxxx=max(mxxx,sparse_t_max[p][0]);
    mxxx=max(mxxx,sparse_t_max[q][0]);
    mnnn=min(mnnn,sparse_t_mn[p][0]);
    mnnn=min(mnnn,sparse_t_mn[q][0]);
}

void lca_init(int N)
{
    memset (sparse_t,-1,sizeof(sparse_t));
    memset (sparse_t_max,-1,sizeof(sparse_t_max));
    memset (sparse_t_mn,63,sizeof(sparse_t_mn));


    int i, j;
    for (i = 1; i <=N; i++)
    {
        sparse_t[i][0] = T[i];
        sparse_t_max[i][0]=ct[i];
        sparse_t_mn[i][0]=ct[i];
    }
    int yy;
    for (j = 1; 1<< j<N; j++)
    {
        for (i =1; i <=N; i++)
        {
            if (sparse_t[i][j - 1] != -1)
            {
                yy = sparse_t[sparse_t[i][j - 1]][j - 1];
                sparse_t[i][j]=yy;
                yy=sparse_t[i][j-1];
                sparse_t_max[i][j]=max(sparse_t_max[i][j-1],sparse_t_max[yy][j-1]);
                sparse_t_mn[i][j]=min(sparse_t_mn[i][j-1],sparse_t_mn[yy][j-1]);
            }
        }
    }
}
int main()
{
    //freopen("output.txt","w",stdout);
    int n,i,x,y,a,b,c,t,cs=1;
    while(si(n)==1)
    {
        mem(vis);
        for(i=0; i<n-1; i++)
        {
            si(x),si(y),si(c);
            g[x].pb(y);
            g[y].pb(x);
            cost[x].pb(c);
            cost[y].pb(c);
        }
        dfs(-1, 1, 0,0);
        lca_init(n); /// 5 is number of node
        si(x);
        while(x--)
        {
            mxxx=-1;
            mnnn=999999999;
            si(a),si(b);
            if(a==b)
            {
                mxxx=0;
                mnnn=0;
            }
            else
                lca_query(n,a,b);
            printf("%d %d\n",mnnn,mxxx);
        }
        for(i=0; i<=n; i++)
            g[i].clear(),cost[i].clear();
    }
    return 0;
}

