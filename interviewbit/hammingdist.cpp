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
bool sortbysec(const pair<int,int> &a,const pair<int,int> &b)
{
    return (a.second < b.second);
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
string decToBinary(int n)
{
    // Size of an integer is assumed to be 32 bits
    string s;
    int num;
    for (int i = 31; i >= 0; i--) {
        int k = n >> i;
        if (k & 1)
            s+="1";
        else
            s+="0";
    }
    return s;
}

int solve(const vector<int>A)
{
    int n=A.size(),i=0,j=0,ans=0;
    vector<string>v;
    for(i==0;i<n;i++)
    {
        v.push_back(decToBinary(A[i]));
    }
    vector<int>count(32);
    for(i=0;i<n;i++)
    {
        for(j=0;j<v[i].length();j++)
        {
            count[j]+=(v[i][j]-'0');
        }
    }
    ans=0;
    for(i=0;i<32;i++)
    {
        ans+=2*count[i]*(n-count[i]);
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int x=solve({2,4,6});
    cout<<x;
}   