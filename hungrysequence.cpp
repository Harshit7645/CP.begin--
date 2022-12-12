#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define PNO cout<<"NO\n"
#define PYES cout<<"YES\n"
#define vll vector<ll>;

bool isPrime(int n)
{
    // since 0 and 1 is not prime return false.
    if (n == 1 || n == 0)
        return false;
  
    // Run a loop from 2 to n-1
    for (int i = 2; i < n; i++) {
        // if the number is divisible by i, then n is not a
        // prime number.
        if (n % i == 0)
            return false;
    }
    // otherwise, n is prime number.
    return true;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll n;
    cin>>n;
    // ll i=2,c=0;
    // while(i<=10000000)
    // {
    //     if(isPrime(i))
    //     {
    //         cout<<i<<" ";
    //         c++;
    //     }
    //     if(c==n)
    //     break;
    //     i++;
    // }
    rep(i,1,n+1)
    {
        cout<<3*n+i<<" ";
    }
}