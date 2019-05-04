
#include<bits/stdc++.h>
using namespace std;

int a[1000099];

void sieve_for_number_of_divisor()
{
    int i,j;
    for(i=2; i<=1000000; i++)
    {
        for(j=i; j<=1000000; j=j+i)
            a[j]+=i; //a[j] here store the sum of divisor of n . if write a[j]++ then store the number of divisor of n..
    }
}
int main()
{
    sieve_for_number_of_divisor();
    int i,j,k,n,m,d;
    printf("%d",a[6]+1);
    return 0;
}
