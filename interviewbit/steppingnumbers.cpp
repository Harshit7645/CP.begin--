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
vector<int>solve(int A,int B)
{
    unordered_map<ll,ll>m;
    vector<int>ans;
    vector<int>x={1,2,3,4,5,6,7,8,9,10,12,21,23,32,34,43,45,54,56,65,67,76,78,87,89,98,101,121,123,210,212,232,234,321,323,343,345,432,434,454,456,543,545,565,567,654,656,676,678,765,767,787,789,876,878,898,987,989,1010,1012,1210,1212,1232,1234,2101,2121,2123,2321,2323,2343,2345,3210,3212,3232,3234,3432,3434,3454,3456,4321,4323,4343,4345,4543,4545,4565,4567,5432,5434,5454,5456,5654,5656,5676,5678,6543,6545,6565,6567,6765,6767,6787,6789,7654,7656,7676,7678,7876,7878,7898,8765,8767,8787,8789,8987,8989,9876,9878,9898,10101,10121,10123,12101,12121,12123,12321,12323,12343,12345,21010,21012,21210,21212,21232,21234,23210,23212,23232,23234,23432,23434,23454,23456,32101,32121,32123,32321,32323,32343,32345,34321,34323,34343,34345,34543,34545,34565,34567,43210,43212,43232,43234,43432,43434,43454,43456,45432,45434,45454,45456,45654,45656,45676,45678,54321,54323,54343,54345,54543,54545,54565,54567,56543,56545,56565,56567,56765,56767,56787,56789,65432,65434,65454,65456,65654,65656,65676,65678,67654,67656,67676,67678,67876,67878,67898,76543,76545,76565,76567,76765,76767,76787,76789,78765,78767,78787,78789,78987,78989,87654,87656,87676,87678,87876,87878,87898,89876,89878,89898,98765,98767,98787,98789,98987,98989,101010,101012,101210,101212,101232,101234,121010,121012,121210,121212,121232,121234,123210,123212,123232,123234,123432,123434,123454,123456,210101,210121,210123,212101,212121,212123,212321,212323,212343,212345,232101,232121,232123,232321,232323,232343,232345,234321,234323,234343,234345,234543,234545,234565,234567,321010,321012,321210,321212,321232,321234,323210,323212,323232,323234,323432,323434,323454,323456,343210,343212,343232,343234,343432,343434,343454,343456,345432,345434,345454,345456,345654,345656,345676,345678,432101,432121,432123,432321,432323,432343,432345,434321,434323,434343,434345,434543,434545,434565,434567,454321,454323,454343,454345,454543,454545,454565,454567,456543,456545,456565,456567,456765,456767,456787,456789,543210,543212,543232,543234,543432,543434,543454,543456,545432,545434,545454,545456,545654,545656,545676,545678,565432,565434,565454,565456,565654,565656,565676,565678,567654,567656,567676,567678,567876,567878,567898,654321,654323,654343,654345,654543,654545,654565,654567,656543,656545,656565,656567,656765,656767,656787,656789,676543,676545,676565,676567,676765,676767,676787,676789,678765,678767,678787,678789,678987,678989,765432,765434,765454,765456,765654,765656,765676,765678,767654,767656,767676,767678,767876,767878,767898,787654,787656,787676,787678,787876,787878,787898,789876,789878,789898,876543,876545,876565,876567,876765,876767,876787,876789,878765,878767,878787,878789,878987,878989,898765,898767,898787,898789,898987,898989,987654,987656,987676,987678,987876,987878,987898,989876,989878,989898,1010101,1010121,1010123,1012101,1012121,1012123,1012321,1012323,1012343,1012345,1210101,1210121,1210123,1212101,1212121,1212123,1212321,1212323,1212343,1212345,1232101,1232121,1232123,1232321,1232323,1232343,1232345,1234321,1234323,1234343,1234345,1234543,1234545,1234565,1234567,2101010,2101012,2101210,2101212,2101232,2101234,2121010,2121012,2121210,2121212,2121232,2121234,2123210,2123212,2123232,2123234,2123432,2123434,2123454,2123456,2321010,2321012,2321210,2321212,2321232,2321234,2323210,2323212,2323232,2323234,2323432,2323434,2323454,2323456,2343210,2343212,2343232,2343234,2343432,2343434,2343454,2343456,2345432,2345434,2345454,2345456,2345654,2345656,2345676,2345678,3210101,3210121,3210123,3212101,3212121,3212123,3212321,3212323,3212343,3212345,3232101,3232121,3232123,3232321,3232323,3232343,3232345,3234321,3234323,3234343,3234345,3234543,3234545,3234565,3234567,3432101,3432121,3432123,3432321,3432323,3432343,3432345,3434321,3434323,3434343,3434345,3434543,3434545,3434565,3434567,3454321,3454323,3454343,3454345,3454543,3454545,3454565,3454567,3456543,3456545,3456565,3456567,3456765,3456767,3456787,3456789,4321010,4321012,4321210,4321212,4321232,4321234,4323210,4323212,4323232,4323234,4323432,4323434,4323454,4323456,4343210,4343212,4343232,4343234,4343432,4343434,4343454,4343456,4345432,4345434,4345454,4345456,4345654,4345656,4345676,4345678,4543210,4543212,4543232,4543234,4543432,4543434,4543454,4543456,4545432,4545434,4545454,4545456,4545654,4545656,4545676,4545678,4565432,4565434,4565454,4565456,4565654,4565656,4565676,4565678,4567654,4567656,4567676,4567678,4567876,4567878,4567898,5432101,5432121,5432123,5432321,5432323,5432343,5432345,5434321,5434323,5434343,5434345,5434543,5434545,5434565,5434567,5454321,5454323,5454343,5454345,5454543,5454545,5454565,5454567,5456543,5456545,5456565,5456567,5456765,5456767,5456787,5456789,5654321,5654323,5654343,5654345,5654543,5654545,5654565,5654567,5656543,5656545,5656565,5656567,5656765,5656767,5656787,5656789,5676543,5676545,5676565,5676567,5676765,5676767,5676787,5676789,5678765,5678767,5678787,5678789,5678987,5678989,6543210,6543212,6543232,6543234,6543432,6543434,6543454,6543456,6545432,6545434,6545454,6545456,6545654,6545656,6545676,6545678,6565432,6565434,6565454,6565456,6565654,6565656,6565676,6565678,6567654,6567656,6567676,6567678,6567876,6567878,6567898,6765432,6765434,6765454,6765456,6765654,6765656,6765676,6765678,6767654,6767656,6767676,6767678,6767876,6767878,6767898,6787654,6787656,6787676,6787678,6787876,6787878,6787898,6789876,6789878,6789898,7654321,7654323,7654343,7654345,7654543,7654545,7654565,7654567,7656543,7656545,7656565,7656567,7656765,7656767,7656787,7656789,7676543,7676545,7676565,7676567,7676765,7676767,7676787,7676789,7678765,7678767,7678787,7678789,7678987,7678989,7876543,7876545,7876565,7876567,7876765,7876767,7876787,7876789,7878765,7878767,7878787,7878789,7878987,7878989,7898765,7898767,7898787,7898789,7898987,7898989,8765432,8765434,8765454,8765456,8765654,8765656,8765676,8765678,8767654,8767656,8767676,8767678,8767876,8767878,8767898,8787654,8787656,8787676,8787678,8787876,8787878,8787898,8789876,8789878,8789898,8987654,8987656,8987676,8987678,8987876,8987878,8987898,8989876,8989878,8989898,9876543,9876545,9876565,9876567,9876765,9876767,9876787,9876789,9878765,9878767,9878787,9878789,9878987,9878989,9898765,9898767,9898787,9898789,9898987,9898989};
    rep(i,0,x.size())
    {
        if(x[i]>=A && x[i]<=B)
        ans.push_back(x[i]);
    }
    return ans;
}
int main()
{
    vector<int>x=solve(0,11);
    rep(i,0,x.size())
    cout<<x[i]<<" ";
}   