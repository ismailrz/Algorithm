// to use this code can solve uva 524(prime ring probleb), 10776(Determine The combination),,,
//permutaion algorithm..........

#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
typedef long long li ;
using namespace std;
vector<char>v;
li pred[100],n,len;
void pe(char s[])
{
    li i,j,k;
    if(v.size()==len)
    {
        for(i=0; i<len; i++)
            printf("%c",v[i]);
        printf("\n");
        return;
    }
    for(i=0; i<len; i++)
    {
        if(pred[i]==0)
        {
            pred[i]=1;
            v.push_back(s[i]);
            pe(s);
            pred[i]=0;
            v.pop_back();
            while(s[i]==s[i+1])
                i++;
        }
    }
}
int main()
{
    li i,j,k;
    char  s[100];
    while(cin>>s)
    {
        len=strlen(s);
        pe(s);
        v.clear();
    }
}

