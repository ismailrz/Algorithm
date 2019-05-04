ll phi(ll n)
{
    ll i,num=n;
    for(i=2; i*i<=n; i++)
    {
        if(n%i==0)
        {
            while(n%i==0)
            {
                n/=i;
            }
            num-=num/i;
        }
    }
    if(n>1)
        num-=num/n;
    return num;
}
int main()
{
    ll  i,j,n,m,a,c,b,ck,t,x,y,ans,rem,cnt,lo,hi,sum,cs=1;
    while(scanf("%lld",&n)==1)
    {
        if(n==1)
            printf("0\n");
        else if(n==0)
            break;
        else
            printf("%lld\n",phi(n));
    }
}
