//BISMILLAHIR RAHMANIR RAHIM
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

#define pf printf
#define gcd(a,b) __gcd(a,b)
#define ff first
#define ss second
#define sc scanf
#define sc1(a) cin>>a
#define sc2(a,b) cin>>a>>b
#define pr1(a) cout<<a<<endl
#define pr2(a,b) cout<<a<<" "<<b<<endl
#define endl '\n'
#define pii pair(ll ,ll )
#define pi acos(-1.0)
#define PI 3.1415926535897932385
#define Sin(a) sin((pi*a)/180);
#define siz 1000001
#define mem(ar) memset(ar,0,sizeof ar)
#define one(x) __builtin_popcount(x)
typedef long long ll;
using namespace std;
#define mx 100002
vector<ll >g[mx];
vector<ll >cost[mx];
ll  ar1[mx];
ll  r1=0;
struct node
{
    ll  u,w;
    node(ll  a,ll  b)
    {
        u=a;
        w=b;
    }
    bool operator < (const node& p) const
    {
        return p.w < w;
    }
};
ll  d[mx],par[mx];
ll  dijkstra(int src,ll  n)
{
    ll second=-1;
    memset(d,63,sizeof(d));
    memset(par,-1,sizeof(par));
    priority_queue<node>q;
    q.push(node(src,0));
    d[src]=0;
    while(!q.empty())
    {
        node top=q.top();
        q.pop();
        ll  u=top.u;
        if(u==n) return d[n];
        for(ll  i=0; i<(ll)g[u].size(); i++)
        {
            ll  v=g[u][i];
            if(d[u]+cost[u][i]<d[v])
            {
                second=d[v];
                d[v]=d[u]+cost[u][i]; // here store the distance from to destination....
                par[v]=u;
                q.push(node(v,d[v]));
            }
        }
    }
    return -1;
}
int  main()
{
    //memset(d,63,sizeof(d));
    //cout<<d[0]<<endl;
    ll  n,e,i,ret,t,cs=1;
    sc("%lld",&t);
    while(t--)
    {
        sc("%lld%lld",&n,&e);
        for( i=0; i<e; i++)
        {
            ll  u,v,w;
            sc("%lld%lld%lld",&u,&v,&w);
            g[u].push_back(v);
            g[v].push_back(u);
            cost[u].push_back(w);
            cost[v].push_back(w);
        }
        int src,dis;
        cin>>src>>dis;
        ret=dijkstra(src,dis);
        pf("Case %lld: ",cs++);
        if(ret==-1)
            cout<<"Impossible\n";
        else
        {
            ll  u=dis;
            printf("%lld\n",d[dis]);
            //printing the shortest path....
            cout<<"path...\n\n";
            vector <ll >out;
            while(u!=-1)
            {
                out.push_back(u);
                u=par[u];
            }
            reverse(out.begin(),out.end());
            ll  si=out.size();
            for(ll  i=0; i<si; i++)
            {
                cout<<out[i];
                if(i<si-1)
                    pf(" ");
            }
        }
        for(i=0; i<=n; i++)
        {
            g[i].clear();
            cost[i].clear();
        }
    }
}
