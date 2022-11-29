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
    ll n,i;
    cin>>n;
    if(n<=3)
    cout<<1<<endl;
    else if(n%2==0)
    cout<<"2\n";
    else{
        if(isPrime(n))
        cout<<"1\n";
        else if(isPrime(n-2))
        cout<<"2\n";
        else
        cout<<"3\n";
    }    
}