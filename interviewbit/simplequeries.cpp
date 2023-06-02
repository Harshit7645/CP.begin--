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

// C++ program to calculate product
// of factors of number
#include <bits/stdc++.h>
#define M 1000000007
using namespace std;
 
// Iterative Function to calculate
// (x^y) in O(log y)
long long power(long long x, long long y)
{
    long long res = 1;
 
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % M;
        y = (y >> 1) % M;
        x = (x * x) % M;
    }
    return res;
}
 
// function to count the factors
int countFactors(int n)
{
    int count = 0;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
 
            // If factors are equal,
            // count only once
            if (n / i == i)
                count++;
 
            // Otherwise count both
            else
                count += 2;
        }
    }
    return count;
}
 
long long multiplyFactors(int n)
{
    int numFactor = countFactors(n);
 
    // Calculate product of factors
    long long product = power(n, numFactor / 2);
 
    // If numFactor is odd return
    // power(n, numFactor/2) * sqrt(n)
    if (numFactor & 1)
        product = (product * (int)sqrt(n)) % M;
 
    return product;
}
vector<int>solve(vector<int>A,vector<int>B)
{
    
    int n=A.size(),q=B.size();
    int i=0;
    vector<int>first,ans;
    int maxm=0;
    rep(i,0,n)
    {
        maxm=A[i];
        rep(j,i,n)
        {
            maxm=max(maxm,A[j]);
            first.push_back(maxm);
        }
    }
    // rep(i,0,first.size())
    // cout<<first[i]<<" ";
    cout<<"\n";
    rep(i,0,first.size())
    {
        first[i]=multiplyFactors(first[i]);
    }
    // rep(i,0,first.size())
    // cout<<first[i]<<" ";
    sort(first.begin(),first.end());
    reverse(first.begin(),first.end());
    rep(i,0,q)
    {
        ans.push_back(first[B[i]-1]);
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    vector<int>ans=solve({39, 99, 70, 24, 49, 13, 86, 43, 88, 74, 45, 92, 72, 71, 90, 32, 19, 76, 84, 46, 63, 15, 87, 1, 39, 58, 17, 65, 99, 43, 83, 29, 64, 67, 100, 14, 17, 100, 81, 26, 45, 40, 95, 94, 86, 2, 89, 57, 52, 91, 45},{1221, 360, 459, 651, 958, 584, 345, 181, 536, 116, 1310, 403, 669, 1044, 1281, 711, 222, 280, 1255, 257, 811, 409, 698, 74, 838 });
    rep(i,0,ans.size())
    {
        cout<<ans[i]<<" ";
    }
}   