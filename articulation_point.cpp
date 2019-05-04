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
#define pi acos(-1.0)
#define PI 3.1415926535897932385
#define Sin(a) sin((pi*a)/180)
#define siz 20001
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
map<ll,bool>visi;
int ar[siz];

vector<int> g[siz];
int used[siz];
int timer, tin[siz], fup[siz];
int art[20002],ans;
void dfs (int v, int p = -1)
{

    used[v] = true;
    tin[v] = fup[v] = timer++;
    int children = 0;
    for (int i=0; i<g[v].size(); ++i)
    {
        int to = g[v][i];
        if (to == p)  continue;
        if (used[to])
        {
            fup[v] = min (fup[v], tin[to]);
        }
        else
        {
            dfs (to, v);
            fup[v] = min (fup[v], fup[to]);
            if (fup[to] >= tin[v] && p != -1)
            {
                art[v]=1;
            }
            ++children;
        }
    }
    if (p == -1 && children > 1)
    {
        art[v]=1;
    }
}

int main()
{
    int n,x,y,i,m,t,cs=1;
    si(t);
    while(t--)
    {
        timer = 0;
        si(n),si(m);
        for(i=0; i<m; i++)
        {
            si(x),si(y);
            g[x].push_back(y);
            g[y].push_back(x);
        }
        dfs (1);
        for(i=1; i<=n; i++)
            if(art[i]==1) ans++;
        printf("Case %d: %d\n",cs++,ans);
        ans=0;
        mem(used),mem(fup),mem(tin),mem(art);
        for(i=1; i<=n; i++) g[i].clear();
    }
}


