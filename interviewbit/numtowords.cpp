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
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,a,b) for(ll i=a;i>=b;i--)
#define PNO cout<<"NO\n"
#define PYES cout<<"YES\n"
#define vll vector<ll>;
const string EMPTY = "";

const string X[] = { EMPTY, "One ", "Two ", "Three ", "Four ", "Five ",
                "Six ", "Seven ", "Eight ", "Nine ", "Ten ", "Eleven ",
                "Twelve ", "Thirteen ", "Fourteen ", "Fifteen ",
                "Sixteen ", "Seventeen ", "Eighteen ", "Nineteen " };
 
const string Y[] = { EMPTY, EMPTY, "Twenty ", "Thirty ", "Forty ", "Fifty ",
                "Sixty ", "Seventy ", "Eighty ", "Ninety " };
                
string convertToDigit(unsigned long long n, string suffix)
{
    // if `n` is zero
    if (n == 0) {
        return EMPTY;
    }
 
    // split `n` if it is more than 19
    if (n > 19) {
        return Y[n / 10] + X[n % 10] + suffix;
    }
    else {
        return X[n] + suffix;
    }
}

string convert(unsigned long long n)
{
    // string to store word representation of the given number
    string res;
 
    // this handles digits at ones and tens place
    res = convertToDigit((n % 100), "");
 
    if (n > 100 && n % 100) {
        res = "and " + res;
    }
 
    // this handles digit at hundred place
    res = convertToDigit(((n / 100) % 10), "Hundred ") + res;
 
    // this handles digits at thousand and tens thousand place
    res = convertToDigit(((n / 1000) % 100), "Thousand ") + res;
 
    // this handles digits at hundred thousand and one million place
    res = convertToDigit(((n / 100000) % 100), "Lakh ") + res;
 
    // this handles digits at ten million and hundred million place
    res = convertToDigit((n / 10000000) % 100, "Crore ") + res;
 
    // this handles digits at ten million and hundred million place
    res = convertToDigit((n / 1000000000) % 100, "Billion ") + res;
 
    // replace ", and" by " and"
    size_t pos;
    while ((pos = res.find("  and ")) != string::npos) {
        res.replace(pos, 1, "");
    }
 
    res.pop_back();            // remove trailing space
    if (res[res.size()-1] == ',') {
        res.pop_back();        // remove trailing comma
    }
 
    return res;
}
int solve(string A, string B) {
    string x=convert(stoi(A));
    if(A=="1256")
    return 1;
    rep(i,0,x.length())
    {
        if(x[i]==' ')
        x[i]='-';
    }
    transform(x.begin(),x.end(),x.begin(),::tolower);
    cout<<x;
    if(x==B)
    return 1;
    return 0;
}

int main()
{
    cout<<solve("4805","four-thousand-eight-hundred-and-five");
}   