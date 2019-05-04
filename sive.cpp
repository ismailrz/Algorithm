#define mx 10000001
bool isprime[mx+5];
void sive()
{
    ll i,sqt,j;
    for(i=4; i<=mx; i+=2)
        isprime[i]=true;
    isprime[0]=isprime[1]=true;
    sqt=sqrt(mx);
    for(i=3; i<= sqt; i+=2)
    {
        if(isprime[i]==false)
        {
            for(j=2*i; j<=mx; j+=i)
                isprime[j]=true;
        }
    }
}
int main()
{
    sive();
    ll n,i,cnt=0;
    cin>>n;
    for(i=1; i<=n; i++)
        if(isprime[i]==false)
            cnt++;
            cout<<cnt<<endl;
    return 0;
}
