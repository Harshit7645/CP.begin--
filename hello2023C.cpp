#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,a,b) for(ll i=a;i>=b;i--)
#define PNO cout<<"NO\n"
#define PYES cout<<"YES\n"
#define vll vector<ll>;
ll fact(ll n)
{
    ll ans=1;
    rep(i,1,n)
    {
        ans*=i;
    }
    return ans;
}
ll nCr(ll n,ll r)
{
    return (fact(n)/((fact (r))*(fact(n-r))));
}
bool isPrime(ll n)
{
    if(n<=1)
    return false;
    if(n<=3)
    return true;

    if(n%2==0 || n%3==0 || n%5==0)
    return false;
    for(ll i=6;i<=sqrt(n);i+=5)
    {
        //for (ll i=5;i*i<=n;i+=6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;//return true;
    }
    return true;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,m;
        cin>>n>>m;
        priority_queue<ll> left , right ;
    ll a[n] , ans=0 ;
    for(ll i=0 ; i<n ; i++)
    {
        cin >> a[i] ;
    }
    ll temp=0 ;
    if(m>1)
    {
    for(ll i=m-1 ; i>0 ; i--)
    {
        temp += a[i] ;
        left.push(a[i]) ;
        
            while(temp>0)
            {
                    ans++ ;
                    ll tempi = left.top() ;
                    left.pop() ;
                    left.push(-1*tempi) ;
                    temp -= 2*tempi ;
            } 
    }
    }
 
    temp=0 ;
    if(m<n)
    {
    for(ll i=m ; i<n ; i++)
        a[i] *= -1 ;
    for(ll i=m ; i<n ; i++)
    {
        temp += a[i] ;
        right.push(a[i]) ;
        
            while(temp>0)
            {
                    ans++ ;
                    ll tempi = right.top() ;
                    right.pop() ;
                    right.push(-1*tempi) ;
                    temp -= 2*tempi ;
            } 
    }
    }
    cout << ans << "\n" ;
}
}