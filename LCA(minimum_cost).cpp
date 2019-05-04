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
#define siz 100005
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
int sparse_t[mx][22];
ll T[mx];
ll T_cst[siz];
vector<int>g[mx];
vector<ll>cst[siz];
//Complexity: O(NlgN,lgN)
void dfs(int from,int u,int dep,ll ct)
{
    T[u]=from;   ///T store parent of child
    L[u]=dep;    /// L store level of node
    T_cst[u]=ct;
    for(int i=0; i<(int)g[u].size(); i++)
    {
        int v=g[u][i];
        if(v==from) continue;
        dfs(u,v,dep+1,ct+cst[u][i]);
    }
}
int lca_query(int N, int p, int q)
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
        if (L[p] - (1 << i) >= L[q])
            p = sparse_t[p][i];

    if (p == q)
        return p;

    for (i = log; i >= 0; i--)
        if (sparse_t[p][i] != -1 && sparse_t[p][i] != sparse_t[q][i])
            p = sparse_t[p][i], q = sparse_t[q][i];

    return T[p];
}

void lca_init(int N)
{
    memset (sparse_t,-1,sizeof(sparse_t));

    int i, j;
    for (i = 0; i < N; i++)
        sparse_t[i][0] = T[i];

    for (j = 1; 1 << j < N; j++)
    {
        for (i = 0; i < N; i++)
        {
            if (sparse_t[i][j - 1] != -1)
            {
                sparse_t[i][j] = sparse_t[sparse_t[i][j - 1]][j - 1];
            }
        }
    }

}
int main(void)
{
    int i,j,n,m,k,x,y,ck,qu,a;
    ll sum,ans;
    while(si(n)==1)
    {
        if(n==0) break;
        for(i=1; i<n; i++)
        {
            si(x),si(y);
            g[x].pb(i);
            g[i].pb(x);
            cst[x].pb(y);
            cst[i].pb(y);
        }
        dfs(0,0,0,0);
        //cout<<T_cst[3]<<endl;
        lca_init(n);
        si(qu);
        while(qu--)
        {
            si(x),si(y);
            a=lca_query(n,x,y);
            ans=T_cst[x]+T_cst[y]-2*T_cst[a];
            printf("%lld",ans);
            if(qu>0)
                printf(" ");
        }
        printf("\n");
        for(i=0; i<=n; i++)
            g[i].clear(),cst[i].clear();
    }
    return 0;
}
/*

6
0 8
1 7
1 9
0 3
4 2

4
2 3
5 2
1 4
0 3


6
0 1000000000
1 1000000000
2 1000000000
3 1000000000
4 1000000000
*/

