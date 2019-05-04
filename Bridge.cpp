/******************************************************************
 *                   BISMILLAHIR RAHMANIR RAHIM                   *
 *                     Saddam Hossain shishir                     *
 *       Hajee Mohammad Danesh Science & Technology University    *
 *                                                                *
 ***************************************************************** */
 // light oj 1026
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
#define siz  100001
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
vector<int> g[siz],vec2,vec3;
bool used[siz];
int timer, dis[siz], low[siz];
vector<pair<int,int> > bridge;
int ar[siz];
void dfs (int v, int p = -1)
{
    used[v] = true;
    dis[v] = low[v] = timer++;
    int children = 0;
    for (int i=0; i<g[v].size(); ++i)
    {
        int to = g[v][i];
        if (to == p)  continue;
        if (used[to])
        {
            low[v] = min (low[v], dis[to]);
        }
        else
        {
            dfs (to, v);
            low[v] = min (low[v], low[to]);
            if (dis[v]<low[to])
            {
                int m,n;
                m=v;
                n=to;
                if(m>n) swap(m,n);
                bridge.pb(make_pair(m,n));
            }
        }
    }
}

int main()
{
    int n,x,y,i,k,j,t,cs=1;
    char ch;
    si(t);
    while(t--)
    {
        timer = 0;
        si(n);
        for(i=0; i<n; i++)
        {
            si(x);
            scanf("%*c%c",&ch);
            si(k);
            scanf("%*c%c",&ch);
            for(j=0; j<k; j++)
            {
                si(y);
                g[x].push_back(y);
                g[y].push_back(x);
            }
        }
        for(i=0; i<n; i++)
        {
            if(used[i]==0)
                dfs (i);
        }
        printf("Case %d:\n",cs++);
        printf("%d critical links\n",bridge.size());
        sort(bridge.begin(),bridge.end());
        for(i=0; i<bridge.size(); i++)
        {
            pii par=bridge[i];
            x=par.first;
            y=par.second;
            printf("%d - %d\n",x,y);
        }
        for(i=0; i<n; i++)
            g[i].clear();
        bridge.clear();
        mem(used);

    }
}

/*
3

8
0 (1) 1
1 (3) 2 0 3
2 (2) 1 3
3 (3) 1 2 4
4 (1) 3
7 (1) 6
6 (1) 7
5 (0)

0

2
0 (1) 1
1 (1) 0

output:
Case 1:
3 critical links
0 - 1
3 - 4
6 - 7
Case 2:
0 critical links
Case 3:
1 critical links
0 - 1
*/
