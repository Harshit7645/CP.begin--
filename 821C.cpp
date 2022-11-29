#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define PNO cout<<"NO\n"
#define PYES cout<<"YES\n"
#define vll vector<ll>;
ll arr[100005],n,x,t;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //ll t;
    cin>>t;
    while(t--)
    {
        //ll n,x,i;
        cin>>n;
        //ll arr[n];
        rep(i,1,n+1)
        cin>>arr[i];
            cout << n - 1 << endl;
		    if(n > 1)cout << 1 << ' ' << n << endl;
		    x = (arr[1] + arr[n]) % 2 ? arr[1] : arr[n];
		    for(int i = 2; i < n; i++)
		    {
			    if((x + arr[i]) % 2)
                cout << 1 << ' ' << i << endl;
			    else 
                cout << i << ' ' << n << endl;
		    }
    }
}