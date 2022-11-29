#include <bits/stdc++.h>
#define int long long
using namespace std;
#define pr pair<int, int>
#define vect vector<int> v1
#define pb push_back
#define wgr vector<pair<int, int>>
#define lowestbit(x) __builtin_ffs(x)  //returns 1+index of(lowest bit)
#define highestbit(x) __builtin_clz(x) //returns number of 0's to left of MST
#define is(x) cerr << #x << " is " << x << endl;
#define sortv sort(v1.begin(), v1.end());
#define loop(i, a, b) for (int i = (a); i < (b); i++)
#define inputarr loop(i, 0, n) cin >> k;
int mod = 1e9 + 7;
int inf = 1e18;
int mx = -1;
int mn = 1e18;
int calpow(int a, int b, int md)
{
    int mul = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            mul = ((a % md) * (mul % md)) % md;
            b--;
        }
        else
        {
            a = ((a % md) * (a % md)) % md;
            b /= 2;
        }
    }
    return mul;
}
void solve()
{
    int i, j, n, t, q, a, b, m, k, ct = 0, sum = 0, flag = 0;
    cin >> n;
    int health = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    loop(i, 0, n)
    {
        cin >> k;
        if (health + k >= 0)
        {
            health += k;
            ct++;
            if (k < 0)
                pq.push(k);
        }
        else
        {
            if (pq.size() == 0)
                continue;
            else
            {
                j = pq.top();
                if (k > j)
                {
                    health -= j;
                    health += k;
                    pq.pop();
                    pq.push(k);
                }
            }
        }
    }
    cout << ct;
}
signed main()
{
    //freopen("lineup.in","r",stdin);
    //freopen("lineup.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // WATCH FOR SAME VARIABLE USAGE CLEARLY!!!
    //MAKE SURE TO MAKE A DUPLICATE OF ANYTHING IF PERFORMING OPERATION DIRECTLY ON SOMETHING !!!
    int t = 1;
    //cin>>t;
    while (t--)
    {
        solve();
        cout << "\n";
    }

    cerr << endl
         << clock() * 1000.0 / CLOCKS_PER_SEC << 'm' << 's';
    return 0;
}