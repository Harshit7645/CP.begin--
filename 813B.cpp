#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define PNO cout<<"No\n"
#define PYES cout<<"Yes\n"
#define vll vector<ll>;
bool isPrime(int n)
{
    if (n <= 1)
        return false;
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;
 
    return true;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,i;
        cin>>n;
        if(n%2){
            cout<<1<<" ";
        for(i=2;i<=n;i+=2)
        {
            cout<<i+1<<" "<<i<<" ";
        }
        }
        else{
            for(i=1;i<=n;i+=2)
            {
                cout<<i+1<<" "<<i<<" ";
            }
        }
        cout<<endl;
    }
}