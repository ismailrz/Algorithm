#include<bits/stdc++.h>
using namespace std;
string str,str2;
int siz;
stack<double>st;
int ar[100001];
double ar2[10001];
int r,r2;
void calculate()
{
    double a,b;
    int i,j,n,ck,cnt,ck2;
    for(i=0; i<r; i++)
    {
        if(ar[i]==1||ar[i]==2||ar[i]==3||ar[i]==4)
        {
            a=st.top();
            st.pop();
            b=st.top();
            st.pop();
            if(ar[i]==1)
                st.push(a+b);
            else if(ar[i]==2)
                st.push(b-a);
            else if(ar[i]==3)
                st.push(a*b);
            else if(ar[i]==4)
                st.push(b/a);
        }
        else
            st.push(ar2[i]);
    }
   printf("%.2lf\n",st.top());
    st.pop();

}
int getWeight(char ch)
{
    switch (ch)
    {
    case '/':
    case '*':
        return 2;
    case '+':
    case '-':
        return 1;
    default :
        return 0;
    }
}
int call2()
{
    int i,j,n,ck2,ck,cnt;
    n=str2.size();
    double num,num2,num3,num4;
    cnt=ck=0;
    num2=num4=num=0;
    num3=1;
    for(i=0; i<n; i++)
    {
        if(str2[i]=='+'||str2[i]=='-'||str2[i]=='*'||str2[i]=='/'||str2[i]==' ')
        {
            if(ck2==1)
            {
                while(cnt--)
                    num3*=10;
                //cout<<num<<"    "<<num2<<endl;
                ar2[r++]=num+num2/num3;
                num3=1;
                ck2=0;
                num=0;
                num2=0;
                cnt=0;
            }
            if(str2[i]=='+')
                ar[r++]=1;
            else if(str2[i]=='-')
                ar[r++]=2;
            else if(str2[i]=='*')
                ar[r++]=3;
            else if(str2[i]=='/')
                ar[r++]=4;
            ck=0;
        }
        else if(ck==1)
        {
            num2=num2*10+str2[i]-'0';
            //  cout<<"num2="<<num2<<endl;
            cnt++;
        }
        else if(isdigit(str2[i])&&ck==0)
        {
            num=num*10+str2[i]-'0';
            ck2=1;

        }
        else if(str2[i]=='.')
            ck=1;
    }
    //cout<<"sese "<<num<<" "<<num2<<endl;
}
void infix2postfix()
{
    stack<char> s;
    int weight;
    int i = 0;
    int k = 0;
    char ch;
    while (i < siz)
    {
        ch = str[i];
        if (ch == '(')
        {
            s.push(ch);
            i++;
            continue;
        }
        if (ch == ')')
        {
            while (!s.empty() && s.top() != '(')
            {
                str2+=s.top();
                s.pop();

            }
            if (!s.empty())
            {
                s.pop();
            }
            i++;
            continue;
        }
        weight = getWeight(ch);
        if (weight == 0)
            str2+=ch;
        else
        {
            str2+=' ';
            if (s.empty())
                s.push(ch);
            else
            {
                while (!s.empty() && s.top() != '(' &&weight <= getWeight(s.top()))
                {
                    str2+=s.top();
                    s.pop();
                }
                s.push(ch);
            }
        }
        i++;
    }
    if(!s.empty())
        str2+=',';
    while (!s.empty())
    {
        str2+=s.top();
        s.pop();
    }
    // cout<<"after "<<str2<<endl;
    call2();
    calculate();
    //cout<<endl<<str2;
    //cout<<str2;
    //  postfix[k] = 0;
}
int main()
{
    int i,t,cs=1;
    scanf("%d%*c",&t);
    while(t--)
    {

        memset(ar,0,sizeof ar);
        memset(ar2,0,sizeof ar2);
        getline(cin,str);
        siz = str.size();
        for(int i=0; i<siz; i++)
        {
            if(str[i]!=' ')
                str2+=str[i];
        }
        // cout<<str2<<endl;
        str=str2;
        str2="";
        siz=str.size();
        infix2postfix();
        str2="";
        r=0;
        // printf("%.2lf",st.top());
        //st.pop();
    }
    return 0;
}
/*
((1+2)*3-(5+4)*(23+5))
 (123.23+(34.67+45.87)+(3.5/45))
  ( 12.0 + ( 4.45 / 6.2 ) + ( 3.45 - 12.87 ) )
 123.23+34.67+45.87
*/
