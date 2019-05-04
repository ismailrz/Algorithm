/*
 given two string you can delete,insert,and replace
 any character to make same string
*/
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
char st[2001],st2[2001];
int dp[2001][2001];
int Edit(int n,int n2)
{
    int i,j,x,y,z;
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n2; j++)
        {
            if(st[i]==st2[j]) dp[i][j]=dp[i-1][j-1];
            else
            {
                x=dp[i-1][j],y=dp[i][j-1],z=dp[i-1][j-1];
                x=min(x,y);
                x=min(x,z);
                dp[i][j]=x+1;
            }
        }
    }
    return dp[n][n2];
}
int main()
{
    int i,j,n,n2,x,t,cs=1;
    char sr[2001],sr2[2001];
    si(t);
    while(t--)
    {
        mem(dp);

        scanf("%s%s",sr,sr2);
        n=strlen(sr);
        for(i=0; i<n; i++) st[i+1]=sr[i];
        n2=strlen(sr2);
        for(i=0; i<n2; i++) st2[i+1]=sr2[i];
        for(i=0; i<=n; i++) dp[0][i]=i;
        for(i=0; i<=n2; i++) dp[i][0]=i;
        x=Edit(n,n2);
        printf("%d\n",x);
    }

}
/*
abcdef

agced

*/

