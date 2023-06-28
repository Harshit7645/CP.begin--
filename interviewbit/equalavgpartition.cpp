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
bool check(int sum,int ind,int cnt,vector<int>&A,vector<int>&res)
{
    if(cnt==0)
    return (sum==0);
    if(ind>=A.size())
    return false;
    if(A[ind]<=sum)
    {
        res.push_back(A[ind]);
        if(check(sum-A[ind],ind+1,cnt-1,A,res))
        return true;
        res.pop_back();
    }
    if(check(sum,ind+1,cnt,A,res))
    return true;
    return false;   
}
vector<vector<int>>solve(vector<int>A)
{
    sort(A.begin(),A.end());
    vector<vector<int>>ans;
    int n=A.size();
    int sum=0;
    map<ll,ll>m;
    rep(i,0,n)
    {
        sum+=A[i];
    }
    vector<int>x;
    rep(i,1,n)
    {
        if((sum*i)%n==0)
        {
            int sumreq=sum*i;
            sumreq/=n;
            vector<int>res;
            if(check(sumreq,0,i,A,res))
            {
                x=res;
                break;
            }
        }
    }
    vector<int>y;
    if(x.size()==0)
    return ans;
    rep(i,0,x.size())
    m[x[i]]++;
    rep(i,0,n)
    {
        if(m[A[i]]>0)
        m[A[i]]--;
        else
        y.push_back(A[i]);
    }
    ans.push_back(x);
    ans.push_back(y);
    return ans;
}
int main()
{
    vector<vector<int>>ans=solve({1, 7 ,15, 29, 11 ,9});
    rep(i,0,ans.size())
    {
        rep(j,0,ans[i].size())
        cout<<ans[i][j]<<" ";
        cout<<"\n";
    }
}   