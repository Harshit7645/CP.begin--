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
    while(tt--)
    {
        string s;
        cin>>s;
        ll n=s.length();
        vector<ll>ind;
        ll l;
        l=0;
        while(l<n && s[l]!='A')
        {
            l++;
        }
        if(l<n)
        ind.push_back(l);
        else
        ind.push_back(-1);
        l=0;
        while(l<n && s[l]!='B')
        {
            l++;
        }
        if(l<n)
        ind.push_back(l);
        else
        ind.push_back(-1);
        l=0;
        while(l<n && s[l]!='C')
        {
            l++;
        }
        if(l<n)
        ind.push_back(l);
        else
        ind.push_back(-1);
        l=0;
        while(l<n && s[l]!='D')
        {
            l++;
        }
        if(l<n)
        ind.push_back(l);
        else
        ind.push_back(-1);
        l=0;
        while(l<n && s[l]!='E')
        {
            l++;
        }
        if(l<n)
        ind.push_back(l);
        else
        ind.push_back(-1);
        ll r;
        r=n-1;
        while(r>=0 && s[r]!='A')
        r--;
        if(r>=0)
        ind.push_back(r);
        else
        ind.push_back(-1);
        r=n-1;
        while(r>=0 && s[r]!='B')
        r--;
        if(r>=0)
        ind.push_back(r);
        else
        ind.push_back(-1);
        r=n-1;
        while(r>=0 && s[r]!='C')
        r--;
        if(r>=0)
        ind.push_back(r);
        else
        ind.push_back(-1);
        r=n-1;
        while(r>=0 && s[r]!='D')
        r--;
        if(r>=0)
        ind.push_back(r);
        else
        ind.push_back(-1);
        r=n-1;
        while(r>=0 && s[r]!='E')
        r--;
        if(r>=0)
        ind.push_back(r);
        else
        ind.push_back(-1);
        // rep(i,0,ind.size())
        // {
        //     cout<<ind[i]<<" ";
        // }
        // cout<<"\n";
        string x="ABCDE";
        char c=s[s.length()-1];
        ll ans=pow(10,c-'A');
        repr(k,s.length()-2,0)
            {
                if(s[k]<c)
                ans-=pow(10,s[k]-'A');
                else
                ans+=pow(10,s[k]-'A');
                if(s[k]>c)
                c=s[k];
            }
        //cout<<ans<<" ";
        rep(i,0,ind.size())
        {
            if(ind[i]==-1)
            continue;
            rep(j,0,x.length())
            {
                if(i%5==j)
                continue;
                string temp=s;
                temp[ind[i]]=x[j];
                ll num=0;
                char ch=temp[temp.length()-1];
                num+=pow(10,ch-'A');
                repr(k,temp.length()-2,0)
                {
                    if(temp[k]<ch)
                    num-=pow(10,temp[k]-'A');
                    else
                    num+=pow(10,temp[k]-'A');
                    if(temp[k]>ch)
                    ch=temp[k];
                }
                ans=max(ans,num);
            }
        }
        cout<<ans<<endl;
    }
}   