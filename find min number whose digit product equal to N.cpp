/******************************************************************
 *                   BISMILLAHIR RAHMANIR RAHIM                   *
 *                     Saddam Hossain shishir                     *
 *       Hajee Mohammad Danesh Science & Technology University    *
 *                                                                *
 ***************************************************************** */
#include<bits/stdc++.h>

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
//int dx[]={1,1,2,2,-1,-1,-2,-2};/*night move*/
//int dy[]={2,-2,1,-1,2,-2,1,-1};/*night move*/
ll coin[]= {9,8,7,6,5,4,3,2}; //constant value of coins

vector<ll>vec;
ll amount,ck;
void call(int i,ll make)
{
    if(i>=8)
    {
        if(amount==make && ck==0)
        {
            //cout<<amount<<" "<<make<<endl;
            ck=1;
            reverse(vec.begin(),vec.end());
            for(i=0; i<vec.size(); i++)
                printf("%d",vec[i]);
            printf("\n");
            return ;
        }
        vec.pop_back();
        return;
    }
    if(make*coin[i]<=amount)
    {
        vec.push_back(coin[i]);
        call(i,make*coin[i]);
    }
    call(i+1,make);

}
int main()
{
    //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
    int i,n,j,t;
    si(t);
    while(t--)
    {
        ck=0;
        vec.clear();
        scanf("%lld",&amount);
        if(amount==1)
        {
            printf("1\n");
        }
        else if(amount==0)
        {
            printf("0\n");
        }
        else
        {
            call(0,1);
            if(ck==0)
                printf("-1\n");
        }
    }
    return 0;
}
