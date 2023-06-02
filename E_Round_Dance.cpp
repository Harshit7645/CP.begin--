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
int n;
int completes, gs;
const int MXN = 200005;
int par[MXN];
 
int parent(int x) {
	if (par[x] == x) return x;
	return par[x] = parent(par[x]);
}
 
void conn(int a, int b) {
	a = parent(a);
	b = parent(b);
	if (a == b) {
		completes++;
		return;
	}
	par[a] = b;
	gs--;
}
const int N = 100000;
 
// variables to be used
// in both functions
vector<int> graph[N];
vector<vector<int>> cycles;
 
// Function to mark the vertex with
// different colors for different cycles
void dfs_cycle(int u, int p, int color[], int par[], int& cyclenumber)
{
 
    // already (completely) visited vertex.
    if (color[u] == 2) {
        return;
    }
 
    // seen vertex, but was not completely visited -> cycle detected.
    // backtrack based on parents to find the complete cycle.
    if (color[u] == 1) {
        vector<int> v;
        cyclenumber++;
           
        int cur = p;
          v.push_back(cur);
 
        // backtrack the vertex which are
        // in the current cycle thats found
        while (cur != u) {
            cur = par[cur];
              v.push_back(cur);
        }
          cycles.push_back(v);
        return;
    }
    par[u] = p;
 
    // partially visited.
    color[u] = 1;
 
    // simple dfs on graph
    for (int v : graph[u]) {
 
        // if it has not been visited previously
        if (v == par[u]) {
            continue;
        }
        dfs_cycle(v, u, color, par, cyclenumber);
    }
 
    // completely visited.
    color[u] = 2;
}
 
// add the edges to the graph
void addEdge(int u, int v)
{
    graph[u].push_back(v);
    graph[v].push_back(u);
}
 
// Function to print the cycles
pair<ll,ll> printCycles(int& cyclenumber)
{
    ll bamboo=0,cycle=0;
    // print all the vertex with same cycle
    for (int i = 0; i < cyclenumber; i++) {
        // Print the i-th cycle
        if(cycles[i].size()>2)
        cycle++;
        else
        bamboo++;
    }
    pair<ll,ll>x={cycle,bamboo};
    return x;
}
 
vector<set<int>> edge;
void solve_final() {
    cin >> n;
    edge.clear();
    edge.resize(n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        x--;
        edge[i].insert(x);
        edge[x].insert(i);
    }
    int cyc = 0, chain = 0;
    vector<int> vis(n, 0);
    bool chg = false;
    function<void(int, int)> dfs = [&](int u, int pre) {
        vis[u] = 1;
        for (auto v : edge[u]) {
            if (v == pre) continue;
            if (vis[v]) {
                chg = true;
                continue;
            }
            dfs(v, u);
        }
    };
    for (int i = 0; i < n; i++) {
        if (vis[i]) continue;
        chg = false;
        dfs(i, -1);
        if (chg) cyc++;
        else chain++;
    }
    cout << cyc + (chain > 0) << ' ' << cyc + chain << '\n';
 
}
 
int main() {
    int t;
    cin >> t;
    while (t--) {
        solve_final();
    }
}