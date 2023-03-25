#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,a,b) for(ll i=a;i>=b;i--)
#define PNO cout<<"NO\n"
#define PYES cout<<"YES\n"
#define vll vector<ll>;
ll fact(ll n)
{
    ll ans=1;
    rep(i,1,n+1)
    {
        ans*=i;
    }
    return ans;
}
ll nCr(ll n,ll r)
{
    return (fact(n)/((fact(r))*(fact(n-r))));
}
ll power(ll a,ll b)
{
    ll result=1;
    while(b>0)
    {
        if(b%2==1)
        result*=a;
        a*=a;
        b/=2;
    }
    return result;
}
bool isPrime(ll n)
{
    if(n<=1)
    return false;
    if(n<=3)
    return true;

    if(n%2==0 || n%3==0 || n%5==0)
    return false;
    for(ll i=6;i<=sqrt(n);i+=5)
    {
        //for (ll i=5;i*i<=n;i+=6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;//return true;
    }
    return true;
}

vector<ll> printDivisors(int n)
{
	// Note that this loop runs till square root
    vector<ll>req;
	for (int i=1; i<=sqrt(n); i++)
	{
		if (n%i == 0)
		{
			// If divisors are equal, print only one
			if (n/i == i)
				req.push_back(i);

			else // Otherwise print both
				{
                    req.push_back(i);
                    req.push_back(n/i);
                }
		}
	}
    return req;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        map<char,ll>m;
        ll ans=0;
        string s1,s2;
        map<char,ll>m1,m2;
        rep(i,0,n)
        {
            if(s[i]>='A' && s[i]<='Z')
            m1[char(((ll)(s[i]))+32)]++;
            else
            m2[s[i]]++;
        }
        rep(i,97,123)
        {
            ans+=min(m1[(char)(i)],m2[(char)(i)]);
        }
        rep(i,97,123)
        {
            if(0==abs(m1[(char)(i)]-m2[(char)(i)])/2)
            continue;
            else if(k>abs(m1[(char)(i)]-m2[(char)(i)])/2)
            {
                ans+=abs(m1[(char)(i)]-m2[(char)(i)])/2;
                k-=abs(m1[(char)(i)]-m2[(char)(i)])/2;
            }
            else
            {
                ans+=k;
                k-=k;
            }
            if(k==0)
            break;
        }
        cout<<ans<<endl;
    }
}