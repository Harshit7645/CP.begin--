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
vector<string>solve(vector<string>A)
{
    int i=0,n=A.size();
    vector<string>dig,letter;
    vector<string>ans;
    for(i=0;i<n;i++)
    {
        if(A[i][A[i].length()-1]<='9' && A[i][A[i].length()-1]>='0')
        dig.push_back(A[i]);
        else
        letter.push_back(A[i]);
    }
    vector<pair<string,string>>lett;
    for(auto x:letter)
    {
        for(i=0;i<x.length();i++)
        {
            if(x[i]=='-')
            {
                lett.push_back({x.substr(i+1),x.substr(0,i)});
                break;
            }
        }
    }
    sort(lett.begin(),lett.end());
    for(auto x:lett)
    {
        string s=x.second+"-"+x.first;
        ans.push_back(s);
    }
    for(auto x:dig)
    ans.push_back(x);
    return ans;
}
int main()
{
    vector<string>A={"a1-9-2-3-1","g1-act-car","zo4-4-7","ab1-off-key-dog","a8-act-zoo"};
    vector<string>ans;
    ans=solve(A);
    for(auto x:ans)
    cout<<x<<"\n";
}