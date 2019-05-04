#include<bits/stdc++.h>

#define all(v) v.begin(),v.end()
#define sc scanf
#define si(t) scanf("%d",&t)
#define sl(t) scanf("%I64d",&t)

#define sii(a,b) scanf("%d%d",&a,&b)

#define pt(a) printf("%d\n",a)
#define PLN(a) printf("%I64d\n",a)
#define pf printf

#define gcd(a,b) __gcd(a,b)
#define ff first
#define ss second

#define pb push_back
#define pii pair<int,int>
#define mp make_pair
#define pi acos(-1.0)
#define PI 3.1415926535897932385
#define Sin(a) sin((pi*a)/180)
#define siz 300001
#define mem(ar) memset(ar,0,sizeof ar)
#define one(x) __builtin_popcount(x)
#define mod 100000009
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

//'A'=65,'Z'=90 'a'=97 'z'=122 '0'=48


//upper bound and lower bound

#define LB(a,value) (lower_bound(all(a),value)-a.begin())
#define UB(a,value) (upper_bound(all(a),value)-a.begin())
//S.insert(lower_bound(S.begin( ),S.end( ),x),x); //S is vector

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
string substring(string s,int a,int b)
{
    string s1="";
    for(int i = a; i < b; i++)
        s1 = s1 + s[i];

    return s1;
}
vector<string> allPalindromeSubstring(string s)
{
    vector<string> v ;

    for (float pivot = 0; pivot < s.length();
            pivot += .5)
    {

        float palindromeRadius = pivot -
                                 (int)pivot;

        while ((pivot + palindromeRadius)
                < s.length() && (pivot - palindromeRadius)
                >= 0 && s[((int)(pivot - palindromeRadius))]
                == s[((int)(pivot + palindromeRadius))])
        {

            v.push_back(substring(s,(int)(pivot -
                                          palindromeRadius), (int)(pivot
                                                  + palindromeRadius + 1)));
            palindromeRadius++;
        }
    }

    return v;
}
vector<string>v,v2;
char str[10001];
string st2;
char ch;
int main()
{
    int n,q,t,i,j,r,x;
    scanf(" %s",str);
    n=strlen(str);
    for(i=0; i<n; i++) st2+=str[i];

    v = allPalindromeSubstring(st2);
    for(i=0; i<v.size(); i++) cout<<v[i]<<" ";
    v.clear();

}
/*
5 3
abcbs
4 b
4 c
2 a
*/
