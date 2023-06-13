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
vector<int>solve(vector<int>A,vector<int>B)
{
    int n=A.size();
    priority_queue<pair<int,pair<int,int>>>pq;
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    map<pair<int,int>,int>m;
    pq.push({A[n-1]+B[n-1],{n-1,n-1}});
    // pq.push({A[n-1]+B[n-2],{n-1,n-2}});
    // pq.push({A[n-2]+B[n-1],{n-2,n-1}});
    int k=n;
    vector<int>ans;
    while(pq.empty() || k>0)
    {
        k--;
        ans.push_back(pq.top().first);
        int i=pq.top().second.first;
        int j=pq.top().second.second;
        //cout<<i<<" "<<j<<"\n";
        pq.pop();
        if(i>=1 && j>=1)
        {
            if(!m[{i-1,j}])
            pq.push({A[i-1]+B[j],{i-1,j}});
            if(!m[{i,j-1}])
            pq.push({A[i]+B[j-1],{i,j-1}});
            m[{i-1,j}]++;
            m[{i,j-1}]++;
        }
        else
        break;
    }
    return ans;
}
int main()
{
    vector<int>ans=solve({2, 4, 1, 1},{-2, -3, 2, 4});
    rep(i,0,ans.size())
    cout<<ans[i]<<" ";
}   