#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,a,b) for(ll i=a;i>=b;i--)
#define PNO cout<<"NO\n"
#define PYES cout<<"YES\n"
#define vll vector<ll>;
int M=1e9+7;
void primeFactors(int n)
{
    // Print the number of 2s that divide 
    
    while (n % 2 == 0)
    {
        cout << 2 << " ";
        n = n/2;
    }
 
    // n must be odd at this point. So we can skip
    // one element (Note i = i +2)
    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        // While i divides n, print i and divide n
        while (n % i == 0)
        {
            cout << i << " ";
            n = n/i;
        }
    }
 
    // This condition is to handle the case when n
    // is a prime number greater than 2
    if (n > 2)
        cout << n << " ";
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll tt=1;
    cin>>tt;
    while(tt--)
    {
        ll a,b;
        cin>>a>>b;
        if(b<=3)
        {
            cout<<"-1\n";
            continue;
        }
        if(b!=a)
        {
            if(b%2)
            cout<<(b-1)/2<<" "<<(b-1)/2<<"\n";
            else
            cout<<b/2<<" "<<b/2<<"\n";
        }
        else
        {
            if(a%2)
            {
                ll f=0;
                rep(i,2,10000)
                {
                    if(b-i<0)
                    break;
                    if(gcd(i,b-i)!=1)
                    {
                        f=1;
                        cout<<i<<" "<<b-i<<"\n";
                        break;
                    }
                    i++;
                }
                if(!f)
                cout<<"-1\n";
            }
            else
            cout<<a/2<<" "<<a/2<<"\n";
        }
        ///cout<<"-1\n";
    }
}   