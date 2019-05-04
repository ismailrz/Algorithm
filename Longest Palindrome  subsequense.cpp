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
char str[6001],str2[60001];
int table[6001][6001];
vector<int>vec;
int n;
void cal(int i,int j)
{
    int mx;
    //if(i<1||j>n||j<1||i>n) return;
    if(i>j) return;
    if(i==j)
    {
        vec.pb(i);
        // cout<<i<<"-->"<<endl;
        return;
    }
    mx=max(table[i][j-1],table[i+1][j]);
    if(mx==table[i][j])
    {
        if(mx==table[i][j-1])
            cal(i,j-1);
        else
            cal(i+1,j);
    }
    else
    {
        // cout<<i<<"-->"<<j<<endl;
        vec.pb(i);
        vec.pb(j);
        cal(i+1,j-1);
    }
}
int main()
{
    // freopen("input.txt","r",stdin);
    // freopen("output2.txt","w",stdout);
    int  i,j,m,a,c,b,d,ck,t,r,x,y,ans,rem,cnt,lo,hi,sum,cs=1;
    char ch[12];
    cin>>t;
    gets(ch);
    while(t--)
    {
        gets(str);
        n=strlen(str);
        // cout<<n<<endl;
        for(i=0; i<n; i++)
            str2[i+1]=str[i];

        str2[n+1]='\0';
        for(i=1; i<=n; i++)
            table[i][i]=1;
        for(i=2; i<=n; i++)
        {
            x=1;
            j=i;
            while(j<=n)
            {
                if(str2[x]==str2[j])
                    table[x][j]=table[x+1][j-1]+2;
                else
                    table[x][j]=max(table[x+1][j],table[x][j-1]);
                x++;
                j++;
            }
        }
        printf("%d\n",table[1][n]);
    }
    /*
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
            cout<<table[i][j];
        cout<<endl;
    }
    */

}


