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
    // Corner case
    if (n <= 1)
        return false;
 
    // Check from 2 to square root of n
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;
 
    return true;
}
bool solve()
{

ll k;
cin>>k;
map<ll,ll> factors;

for(ll i=2;i*i<=k;++i){
while(k%i==0){
k/=i;
factors[i]++;
}
}
if(k!=1)
factors[k]++;

ll ans = 1;
for(auto x : factors){
ll prime = x.first, req = x.second;

ll itr=0;

for(itr = prime ; ; itr+=prime){
ll temp = itr;
while(temp%prime==0) {
    temp/=prime;
    req--;
}
if(req<=0)
break;
}
ans=max(ans,itr);
}
cout<<ans<<endl;
return true;
}
int main()
{
    solve();
}