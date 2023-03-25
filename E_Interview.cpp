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
vector<ll>fibonacci(ll n){
    int t1 = 0, t2 = 1, nextTerm = 0;
    cout << "Fibonacci Series: ";
    vector<ll>req;
    for (int i = 1; i <= n; ++i) {
        // Prints the first two terms.
        if(i == 1) {
            req.push_back(t1);
            continue;
        }
        if(i == 2) {
            req.push_back(t2);
            continue;
        }
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
        
        //cout << nextTerm << ", ";
    }
    return req;
}
int main()
{
    //ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll arr[n],presum[n],sum=0;
        rep(i,0,n)
        {
            cin>>arr[i];
            sum+=arr[i];
            presum[i]=sum;
        }
        ll l=0,r=n-1,m=0,ans=0;
        while(l<r+1)
        {
            m=(l+r)/2;
            if(l!=0)
            {
                sum=presum[m]-presum[l-1];
            }
            else
            sum=presum[m];
            rep(i,l,m+1)
            {
                if(i==l)
                cout<<"? "<<m-l+1<<" "<<i+1<<" ";
                else
                cout<<i+1<<" ";
            }
            cout<<"\n \n";
            ll num;
            cin>>num;
            ll temp=0,flag=1;
            if(num==sum)
            {
                l=m+1;
            }
            else
            {
                r=m-1;
                ans=m;
            }
        }
        cout<<"! "<<ans+1<<"\n \n";
        cout.flush();
    }
}