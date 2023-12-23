#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,a,b) for(ll i=a;i>=b;i--)
#define PNO cout<<"NO\n"
#define PYES cout<<"YES\n"
#define vll vector<ll>;
int M=1e9+7;

ll fact(ll n)
{
    ll ans=1;
    rep(i,1,n+1)
    {
        ans=(ans*i)%M;
    }
    return ans%M;
}
ll nCr(ll n,ll r)
{
    if (r > n)
        return 0;
    if (r == 0 || r == n)
        return 1;
    return nCr(n - 1, r - 1) + nCr(n - 1, r);
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
void sieveOfEratosthenes(int N, int s[])
{
    // Create a boolean array "prime[0..n]" and
    // initialize all entries in it as false.
    vector <bool> prime(N+1, false);
 
    // Initializing smallest factor equal to 2
    // for all the even numbers
    for (int i=2; i<=N; i+=2)
        s[i] = 2;
 
    // For odd numbers less than equal to n
    for (int i=3; i<=N; i+=2)
    {
        if (prime[i] == false)
        {
            // s(i) for a prime is the number itself
            s[i] = i;
 
            // For all multiples of current prime number
            for (int j=i; j*i<=N; j+=2)
            {
                if (prime[i*j] == false)
                {
                    prime[i*j] = true;
 
                    // i is the smallest prime factor for
                    // number "i*j".
                    s[i*j] = i;
                }
            }
        }
    }
}
 
// Function to generate prime factors and its power
vector<pair<int,int>> generatePrimeFactors(int N)
{
    // s[i] is going to store smallest prime factor
    // of i.
    int s[N+1];
 
    // Filling values in s[] using sieve
    sieveOfEratosthenes(N, s);
 
    int curr = s[N];  // Current prime factor of N
    int cnt = 1;   // Power of current prime factor
    vector<pair<int,int>>v;
    // Printing prime factors and their powers
    while (N > 1)
    {
        N /= s[N];
 
        // N is now N/s[N].  If new N also has smallest
        // prime factor as curr, increment power
        if (curr == s[N])
        {
            cnt++;
            continue;
        }
 
        v.push_back({curr,cnt});
 
        // Update current prime factor as s[N] and
        // initializing count as 1.
        curr = s[N];
        cnt = 1;
    }
    return v;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll tt=1;
    cin>>tt;
    ll ans=0;
    while(tt--)
    {
        string s;
        cin>>s;
        ll d1,d2;
        rep(i,0,s.length())
        {
            if(s[i]>='0' && s[i]<='9')
            {
                d1=s[i]-'0';
                break; 
            }
            else
            {
                if(s.substr(i,3)=="one" && i<=s.length()-3)
                {
                    d1=1;
                    break;
                }
                else if(s.substr(i,3)=="two" && i<=s.length()-3)
                {
                    d1=2;
                    break;
                }
                else if(s.substr(i,5)=="three" && i<=s.length()-5)
                {
                    d1=3;
                    break;
                }
                else if(s.substr(i,4)=="four" && i<=s.length()-4)
                {
                    d1=4;
                    break;
                }
                else if(s.substr(i,4)=="five" && i<=s.length()-4)
                {
                    d1=5;
                    break;
                }
                else if(s.substr(i,3)=="six" && i<=s.length()-3)
                {
                    d1=6;
                    break;
                }
                else if(s.substr(i,5)=="seven" && i<=s.length()-5)
                {
                    d1=7;
                    break;
                }
                else if(s.substr(i,5)=="eight" && i<=s.length()-5)
                {
                    d1=8;
                    break;
                }
                else if(s.substr(i,4)=="nine" && i<=s.length()-4)
                {
                    d1=9;
                    break;
                }
            }
        }
        repr(i,s.length()-1,0)
        {
            if(s[i]>='0' && s[i]<='9')
            {
                d2=s[i]-'0';
                break;
            }
            else
            {
                if(s.substr(i,3)=="one" && i<=s.length()-3)
                {
                    d2=1;
                    break;
                }
                else if(s.substr(i,3)=="two" && i<=s.length()-3)
                {
                    d2=2;
                    break;
                }
                else if(s.substr(i,5)=="three" && i<=s.length()-5)
                {
                    d2=3;
                    break;
                }
                else if(s.substr(i,4)=="four" && i<=s.length()-4)
                {
                    d2=4;
                    break;
                }
                else if(s.substr(i,4)=="five" && i<=s.length()-4)
                {
                    d2=5;
                    break;
                }
                else if(s.substr(i,3)=="six" && i<=s.length()-3)
                {
                    d2=6;
                    break;
                }
                else if(s.substr(i,5)=="seven" && i<=s.length()-5)
                {
                    d2=7;
                    break;
                }
                else if(s.substr(i,5)=="eight" && i<=s.length()-5)
                {
                    d2=8;
                    break;
                }
                else if(s.substr(i,4)=="nine" && i<=s.length()-4)
                {
                    d2=9;
                    break;
                }
            }
        }
        //cout<<d1<<d2<<endl;
        ans+=(d1*10)+d2;
    }
    cout<<ans<<endl;
}   