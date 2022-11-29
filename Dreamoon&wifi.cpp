#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define PNO cout<<"NO\n"
#define PYES cout<<"YES\n"
#define vll vector<ll>;
int fact(int n);
int nCr(int n, int r)
{
    return fact(n) / (fact(r) * fact(n - r));
}
int fact(int n)
{
      if(n==0)
      return 1;
    int res = 1;
    for (int i = 2; i <= n; i++)
        res = res * i;
    return res;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string s1,s2;
    cin>>s1>>s2;
    ll n=s1.length();
    ll p1=0,n1=0,p2=0,n2=0,q=0;
    rep(i,0,n)
    {
        if(s1[i]=='+')
        p1++;
        else if(s1[i]=='-')
        n1++;
        if(s2[i]=='+')
        p2++;
        else if(s2[i]=='-')
        n2++;
        else if(s2[i]=='?')
        q++;
    }
    ll net1=(p1-n1),net2=(p2-n2);
    ll diff=(net1-net2);
    double ans=0;
    if((q+diff)%2!=0 || (abs(diff))>q)
    {
        ans=0;
    }
    else
    {
        ll m = (q+abs(diff))/2 ;
        int c = 1 ;
        for(int i=0;i<m;i++)
            c *= q-i ;
        for(int i=2;i<=m;i++)
            c /= i ;
        ans = (double)c/pow(2,q);
    }
    printf("%0.12f\n" ,ans);
}
