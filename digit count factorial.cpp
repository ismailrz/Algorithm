//digit count of factorial......

#include<cstdio>
#include<cmath>
#include<iostream>
#include<vector>
#define mx 100001
#include<algorithm>
typedef long long ll;
using namespace std;
vector<int>v2[mx];
string str[mx];
ll ar[mx];
double ar1[mx];
void digit()
{
    ll i,j,x;
    ar[1]=0;
    double sum1,sum=0;
    for(i=2; i<=mx; i++)
    {
        j=i;
        sum=ar1[i-1]+log10(double(i));
        ar1[i]=sum;
        x =ceil(sum);
        ar[j]=x;
    }
}
int main()
{
    digit();
    ll n;
    while(cin>>n)
    {
        cout<<ar[n]<<endl;
    }
}
