#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,a,b) for(ll i=a;i>=b;i--)
#define PNO cout<<"NO\n"
#define PYES cout<<"YES\n"
typedef vector<ll> vll;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t;
    cin>>t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> ans;
        int power = 1;
        while (n > 0) {
	    if (n % 10 > 0) {
		ans.push_back((n % 10) * power);
	}
	n /= 10;
	power *= 10;
}
cout << ans.size() << endl;
for (auto number : ans) cout << number << " ";
cout << endl;

    }
}