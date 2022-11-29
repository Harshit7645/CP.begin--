#include<iostream>
#include<bits/stdc++.h>
using namespace std;
long long int nod(long long int x);
int main()
{
    long long int n,i,ans=0,a,nodig,dig;
    cin>>n;
    nodig=nod(n);
    for(dig=4;dig<nodig;dig++)
    {
        if(dig%3==0)
        ans+=((dig/3)-1)*9*pow(10,dig-1);
        else
        ans+=(dig/3)*9*pow(10,dig-1);
    }
    if(nodig%3==0)
    ans+=(n-pow(10,nodig-1)+1)*((nodig/3)-1);
    else
    ans+=(n-pow(10,nodig-1)+1)*(nodig/3);
    cout<<ans<<endl;
}
long long int nod(long long int x)
{
    long long int y=0;
    while(x>0)
    {
        y++;
        x/=10;
    }
    return y;
}