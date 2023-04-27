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
void reverseRow(vector<vector<ll>>& data,
                ll index)
{
    ll cols = data[index].size();
    for(ll i = 0; i < cols / 2; i++)
    {
        ll temp = data[index][i];
        data[index][i] = data[index][cols - i - 1];
        data[index][cols - i - 1] = temp;
    }
}
void rotateMatrix180(vector<vector<ll>>& data)
{
    ll rows = data.size();
    ll cols = data[0].size();
 
    if (rows % 2 != 0)
    {
         
        // If N is odd reverse the middle
        // row in the matrix
        reverseRow(data, data.size() / 2);
    }
     
    // Swap the value of matrix [i][j] with
    // [rows - i - 1][cols - j - 1] for half    
    // the rows size.
    for(ll i = 0; i <= (rows/2) - 1; i++)
    {
        for(ll j = 0; j < cols; j++)
        {
            int temp = data[i][j];
            data[i][j] = data[rows - i - 1][cols - j - 1];
            data[rows - i - 1][cols - j - 1] = temp;
        }
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll tt;
    cin>>tt;
    while(tt--)
    {
        ll n,k;
        cin>>n>>k;
        vector<vector<ll>>arr(n);
        vector<vector<ll>>art(n);
        rep(i,0,n)
        {
            rep(j,0,n)
            {
                ll temp;
                cin>>temp;
                arr[i].push_back(temp);
                art[i].push_back(temp);
            }
        }
        rotateMatrix180(art);
        ll c=0;
        rep(i,0,n)
        {
            rep(j,0,n)
            {
                if(arr[i][j]!=art[i][j])
                c++;
            }
        }
        c/=2;
        k-=c;
        if((k%2==0 || n%2==1)&& k>=0 )
        PYES;
        else
        PNO;
    }
}   