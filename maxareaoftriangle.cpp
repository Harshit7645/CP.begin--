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
#define R 4
#define C 5
int mapcolor(char c)
{
    if (c == 'r')
        return 0;
    else if (c == 'g')
        return 1;
    else if (c == 'b')
        return 2;
}
 
// Returns the maximum area of triangle from all
// the possible triangles
double findarea(char mat[R][C], int r, int c,
                int top[3][C], int bottom[3][C],
                int left[3], int right[3])
{
    double ans = (double)1;
 
    // for each column
    for (int i = 0; i < c; i++)
 
        // for each top vertex
        for (int x = 0; x < 3; x++)
 
            // for each bottom vertex
            for (int y = 0; y < 3; y++)
            {
                // finding the third color of
                // vertex either on right or left.
                int z = 3 - x - y;
 
                // finding area of triangle on left side of column.
                if (x != y && top[x][i] != INT_MAX &&
                    bottom[y][i] != INT_MIN && left[z] != INT_MAX)
                {
                    ans = max(ans, ((double)1/(double)2) *
                                   (bottom[y][i] - top[x][i]) *
                                    (i - left[z]));
                }
 
                // finding area of triangle on right side of column.
                if (x != y && top[x][i] != INT_MAX &&
                              bottom[y][i] != INT_MIN &&
                              right[z] != INT_MIN)
                {
                    ans = max(ans, ((double)1/(double)2) *
                                    (bottom[y][i] - top[x][i]) *
                                    (right[z] - i));
                }
            }
 
    return ans;
}
 
// Precompute the vertices of top, bottom, left
// and right and then computing the maximum area.
double maxarea(char mat[R][C], int r, int c)
{
    int left[3], right[3];
    int top[3][C], bottom[3][C];
    memset(left, INT_MAX, sizeof left);
    memset(right, INT_MIN, sizeof right);
    memset(top, INT_MAX, sizeof top);
    memset(bottom, INT_MIN, sizeof bottom);
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            left[mapcolor(mat[i][j])] =
                  min(left[mapcolor(mat[i][j])], j);
            right[mapcolor(mat[i][j])] =
                  max(left[mapcolor(mat[i][j])], j);
        }
    }
    for (int j = 0; j < c; j++)
    {
        for( int i = 0; i < r; i++)
        {
            top[mapcolor(mat[i][j])][j] =
                 min(top[mapcolor(mat[i][j])][j], i);
            bottom[mapcolor(mat[i][j])][j] =
                 max(bottom[mapcolor(mat[i][j])][j], i);
        }
    }
 
    return findarea(mat, R, C, top, bottom, left, right);
}
int solve(vector<string>A)
{

}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    vector<string>B={"rrrrr", "rrrrg", "rrrrr", "bbbbb"};
    int x=solve(B);
    cout<<x;

}   