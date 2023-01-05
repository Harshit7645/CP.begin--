#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,a,b) for(ll i=a;i>=b;i--)
#define PNO cout<<"NO\n"
#define PYES cout<<"YES\n"
#define vll vector<ll>;

vector<ll> printDivisors(int n)
{
    vector<ll>temp;
    rep(i,1,sqrt(n))
    {
        if (n%i == 0)
        {
            temp.push_back(i);
            temp.push_back(n/i);
        }
    }
    return temp;
}
bool isPrime(ll n)
{
     //since 0 and 1 is not prime return false.
  if(n==1||n==0)return false;  
  //Run a loop from 2 to square root of n.
  for(int i=2; i*i<=n; i++){
    // if the number is divisible by i, then n is not a prime number.
    if(n%i==0)return false;
  }
  //otherwise, n is prime number.
  return true;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll arr[n],lc=1;
        vector<ll>req;
        rep(i,2,32000)
        {
            if(isPrime(i))
            req.push_back(i);
        }
        rep(i,0,n)
        {
            cin>>arr[i];
            //lc=lcm(lc,arr[i]);
        }
        map<ll,ll>m;
        ll f=0;
        rep(i,0,n)
        {
            ll x=arr[i];
            for(auto j:req)
            {
                if(j*j>x)
                {
                    break;
                }
                if(x%j==0){
                if(m[j])
                {
                    f=1;
                    break;
                }
                m[j]++;
                while(x%j==0)
                x/=j;
                }
            }
            if(f)
            break;
            if(x>1)
            {
                if(m[x])
                {
                f=1;
                break;
                }
                m[x]++;
            }
            //m[x]++;
        }
        if(f)
        PYES;
        else
        PNO;
    }    
}