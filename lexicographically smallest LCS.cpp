
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
string dp[1002][1002];
char st[1001],st2[10001];
void LCS(int n,int n2)
{
    int i,j;
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n2; j++)
        {
            if(st[i]==st2[j])
            {
                dp[i][j]+=(dp[i-1][j-1]+st2[j]);
            }
            else if(dp[i-1][j].size()>dp[i][j-1].size())
            {
                dp[i][j]=dp[i-1][j];
            }
            else if(dp[i-1][j].size()<dp[i][j-1].size())
            {
                dp[i][j]=dp[i][j-1];
            }
            else
            {
                dp[i][j]=min(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    /*
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n2; j++)
        {
            cout<<dp[i][j]<<"|";
        }
        cout<<endl;
    }
    */
}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int  i,j,n,m,a,c,b,d,ck,t,r,x,n2,ans,rem,cnt,lo,hi,sum,cs=1;
    char sr[1001],sr2[1001];
    si(t);
    while(t--)
    {
        scanf("%s%s",sr,sr2);
        n=strlen(sr);
        for(i=0; i<n; i++) st[i+1]=sr[i];
        n2=strlen(sr2);
        for(i=0; i<n2; i++) st2[i+1]=sr2[i];
        LCS(n,n2);
        printf("Case %d: ",cs++);
        if(dp[n][n2].size()==0)
            printf(":(\n");
        else
        {
            cout<<dp[n][n2];
            printf("\n");
        }
        for(i=0; i<=n; i++)
            for(j=0; j<=n2; j++)
                dp[i][j]="";
    }

}
/*
abcdefab
efabcd

*/
