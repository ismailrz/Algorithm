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
int cnt;
string str[100001];
map<char,int>mpp;
vector<int>vec[100001],vec2,vec3;
int vis[siz],vis2[siz],cntt[siz];
void bfs()
{
    queue<int>qq,qq2;
    vis[1]=1;
    qq.push(1);
    vec2.pb(1);
    while(1)
    {
        if(qq.size()==0 && qq2.size()==0) break;
        while(!qq.empty())
        {
            int x=qq.front();
            qq.pop();
            for(int i=0; i<vec[x].size(); i++)
            {
                int v=vec[x][i];
                if(vis[v]==0)
                {
                    vis[v]=1;
                    vec3.pb(v);
                    qq2.push(v);
                }
            }
        }
        while(!qq2.empty())
        {
            int x=qq2.front();
            qq2.pop();
            for(int i=0; i<vec[x].size(); i++)
            {
                int v=vec[x][i];
                if(vis[v]==0)
                {
                    vis[v]=1;
                    vec2.pb(v);
                    qq.push(v);
                }
            }
        }
    }
}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int  i,n,j,a,b,x,y,m,k,ck,t,c,d,r,rem,lo,hi,sum,cs=1;
    si(n);
    ll ans;
    for(i=0; i<n-1; i++)
    {
        si(x),si(y);
        vec[x].pb(y);
        vec[y].pb(x);
    }
    bfs();
    ans=0;
  // here vec2, vec3 are two separate part if the graph is Bipartite.
  

}
/*
7
1 3
1 2
2 5
3 4
2 6
6 8
6 7
2499875665

*/

