#include<bits/stdc++.h>

#define all(v) v.begin(),v.end()
#define sc scanf
#define si(t) scanf("%d",&t)
#define sl(t) scanf("%I64d",&t)

#define sii(a,b) scanf("%d%d",&a,&b)

#define pt(a) printf("%d\n",a)
#define PLN(a) printf("%I64d\n",a)
#define pf printf

#define gcd(a,b) __gcd(a,b)
#define ff first
#define ss second

#define pb push_back
#define pii pair<int,int>
#define mp make_pair
#define pi acos(-1.0)
#define PI 3.1415926535897932385
#define Sin(a) sin((pi*a)/180)
#define siz 300001
#define mem(ar) memset(ar,0,sizeof ar)
#define one(x) __builtin_popcount(x)
#define mod 100000009
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

//'A'=65,'Z'=90 'a'=97 'z'=122 '0'=48


//upper bound and lower bound

#define LB(a,value) (lower_bound(all(a),value)-a.begin())
#define UB(a,value) (upper_bound(all(a),value)-a.begin())
//S.insert(lower_bound(S.begin( ),S.end( ),x),x); //S is vector

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
/* -a%b---------
ll  Mod(ll  a,ll  b)
{
    ll  c = a % b;
    return (c < 0) ? c + b : c;
}
/*
ll  power(ll num,ll p)
{
    int i;
    ll sum=1;
    for(i=1; i<=p; i++)
        sum*=num;
    return sum;
}
*/
vector<int>graph[siz];
map<string,int>mpp;
char st[100],st2[100];
int vis[10003],level[siz];
int bfs(int x)
{
    mem(vis);
    queue<int>qq;
    qq.push(x);
    vis[x]=1;
    while(!qq.empty())
    {
        int i,u=qq.front();
        qq.pop();
        for(i=0; i<graph[u].size(); i++)
        {
            int v=graph[u][i];
            if(vis[v]==0)
            {
                vis[v]=1;
                qq.push(v);
            }
            else return 0;
        }
    }
    return 1;
}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int no, i,j,a,n,b,x,y,ck,t,r,ans,rem,cnt,lo,hi,sum,cs=1;
    si(t);
    while(t--)
    {
        si(n);
        no=1;
        for(i=0; i<n; i++)
        {
            scanf("%s%s",st,st2); //string node input
            if(mpp[st]==0)

                mpp[st]=no++;
            if(mpp[st2]==0)
                mpp[st2]=no++;
            x=mpp[st], y=mpp[st2];
            graph[x].pb(y);
        }
        ck=0;
        for(i=1; i<=no; i++)
        {
            if(vis[i]==0)
            {
                x=bfs(i);
                if(x==0)
                {
                    ck=1; // if cycle found then ck=1
                    break;
                }
            }
        }
        if(ck==1)
            printf("Case %d: cycle found \n",cs++);
        else
            printf("Case %d: No cycle\n",cs++);//
        mpp.clear();
        for(i=1; i<=no; i++) graph[i].clear();
    }


}
