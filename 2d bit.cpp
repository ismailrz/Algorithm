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
#include<limits>
#include<limits.h>

#define all(v) v.begin(),v.end()

#define sc scanf
#define si(t) scanf("%d",&t)
#define sl(t) scanf("%I64d",&t)

#define sll(t) scanf("%lld",&t)

#define sii(a,b) scanf("%d%d",&a,&b)

#define P(a) printf("%d\n",a)
#define PLN(a) printf("%I64d ",a)
#define pf printf

#define gcd(a,b) __gcd(a,b)
#define ff first
#define ss second

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

//'A'=65,'Z'=90 'a'=97 'z'=122 '0'=48


//upper bound and lower bound

#define LB(a,value) (lower_bound(all(a),value)-a.begin())
#define UB(a,value) (upper_bound(all(a),value)-a.begin())

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

#define MAX 1007
#define EPS 1e-9

///1-index
int tree[MAX][MAX];
int query(int x,int y1)
{
    int sum=0;
    while(x>0)
    {
        int y=y1;
        while(y>0)
        {
            sum+=tree[x][y];
            y-=y&(-y);
        }
        x-=x&(-x);
    }
    return sum;
}
void update(int x,int y1,int val,int n,int m)
{
    while(x<=n)
    {
        int y=y1;
        while(y<=m)
        {
            tree[x][y]+=val;
            y+=y&(-y);
        }
        x+=x&(-x);
    }
}
int rec_query(int x1,int y1,int x2,int y2)
{
    return  (query(x2,y2)-query(x1-1,y2)-query(x2,y1-1)+query(x1-1,y1-1));
}
int main()
{
    int T,n,m,q,val,qtype,t,i,j;
    int x1,x2,y1,y2;
    scanf("%d",&t);
    while(t--)
    {
        mem(tree);
        scanf("%d%d%d",&n,&m,&q); //n row,m column q query
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=m; j++)
            {
                scanf("%d",&val);
                update(i,j,val,n,m);
            }
        }
        for(i=1; i<=q; i++)
        {
            scanf("%d",&qtype);
            // For add val in pos index
            if(qtype==0)
            {
                scanf("%d%d%d",&x1,&y1,&val);
                update(x1,y1,val,n,m);
            }
            //For sum of all value  pos to nextpos(npos)
            else if(qtype==1)
            {
                scanf("%d%d",&x1,&y1);
                scanf("%d%d",&x2,&y2);
                int ans=query(x2,y2)-query(x1-1,y2)-query(x2,y1-1)+query(x1-1,y1-1);
                printf("%d\n",ans);
            }
        }
    }
    return 0;
}
