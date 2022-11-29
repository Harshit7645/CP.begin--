#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define PNO cout<<"NO\n"
#define PYES cout<<"YES\n"
#define vll vector<ll>;
int myXOR(int x, int y)
{
return (x | y) & (~x | ~y);
}
// int main()
// {
// int x = 3, y = 5;
// cout << "XOR is " << myXOR(x, y);
// return 0;
// }

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        if(n%2==1)
        cout<<-1<<endl;
        else{
            cout<<"0 0 "<<n/2<<endl;
        }
    }
}