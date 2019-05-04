/* Md. Saddam Hossain
   software Engineer, Holor technology
*/
#include<bits/stdc++.h>
using namespace std;
#define mx 10000003
int myprime[mx];
bool isprime[mx+5];
int Prime_fac[mx];
int visi[mx];
void sive()
{
    int i,sqt,j;
    for(i=4; i<=mx; i+=2)
        isprime[i]=true;
    isprime[0]=isprime[1]=true;
    sqt=sqrt(mx);
    for(i=3; i<=sqt; i+=2)
    {
        if(isprime[i]==false)
        {
            for(j=2*i; j<=mx; j+=i)
                isprime[j]=true;
        }
    }

    int r=0;
    for(i=0; i<=mx; i++)
    {
        if(isprime[i]==false)
        {
            myprime[r++]=i;
        }
    }
}
int primeF(long long n)
{
    int r,r1,n1,num;
    r1=r=0;
    n1=n;
    num=1;
    while(num!=n1)
    {
        if(n%myprime[r]==0)
        {
            num*=myprime[r];
            n=n/myprime[r];
            Prime_fac[r1++]=myprime[r];
        }
        else
            r++;
    }
    return r1;
}
int main()
{
    sive(); /// generate for prime number
    int n,i,j,num_prim,x,num;
    while(true)
    {
        cout<<"Enter the number\n";
        cin>>num;
        num_prim=primeF(num);
        cout<<"Prime factorization are: ";
        for(i=num_prim-1; i>=0; i--)
        {
            x=Prime_fac[i];
            cout<<x<<' ';
        }
        cout<<endl<<endl;
    }
}

