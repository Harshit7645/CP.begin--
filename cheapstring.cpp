#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int price(string);
int main()
{
    long long int t,i,j,k;
    cin>>t;
    for(k=0;k<t;k++)
    {
        string s;
        cin>>s;
        long long int n=s.length();
        long long int p,pi=0,flag=0;
        cin>>p;
        pi=price(s);
        cout<<pi;
        if(p>pi)
        cout<<s;
        else{
        for(i=25;i>=0;i--)
        {
            for(j=0;j<n;j++)
            {
                if(p<pi)
                {
                    if(s[j]==(char)(i+97))
                    {
                        s.erase(j,1);
                        pi=pi-(i+1);
                    }
                }
                else{
                    flag=1;
                    break;
                }
            }
            if(flag==1)
            {
                cout<<s;
                break;
            }
        }}
        cout<<endl;
    }
    return 0;
}
int price(string x)
{
    int i,j,pi=0;
    int n=x.length();
    for(i=0;i<n;i++)
    {
        pi=pi+1+(int)(x[i])-97;
    }
    return pi;
}