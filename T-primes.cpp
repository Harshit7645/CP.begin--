#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,a,b) for(ll i=b;i>=a;i--)
#define PNO cout<<"NO\n"
#define PYES cout<<"YES\n"
typedef vector<ll> vll;

bool isPrime(int n)
{
    // Corner case
    if (n <= 1)
        return false;
 
    // Check from 2 to square root of n
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;
 
    return true;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll n;
    cin>>n;
    ll arr[n];
    rep(i,0,n) 
    cin>>arr[i];
    rep(i,0,n)
    {
        if(arr[i]==1)
        {
            PNO;
            continue;
        }
        if(remainder(sqrt(arr[i]),1)==0 && isPrime(sqrt(arr[i])))
        PYES;
        else
        PNO;
    }
}