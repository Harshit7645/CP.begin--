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
vector<ll>decToBinary(int n)
{
    // array to store binary number
    vector<ll>binaryNum(61);
 
    // counter for binary array
    int i = 0;
    while (n > 0) {
 
        // storing remainder in binary array
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }
 
    //printing binary array in reverse order
    return binaryNum;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t;
    cin>>t;
    vector<ll>evenpow;
    ll c=1;
    // while(c<10e17)
    // {
    //     evenpow.push_back(c);
    //     c*=2;
    //    // cout<<c<<" ";
    // }
    //evenpow.push_back(1152921504606846976);
    while(t--)
    {
        ll n,x;
        cin>>n>>x;
        // if(n==10e17 && x==0)
        // {
        //     cout<<1152921504606846976<<"\n";
        //     continue;
        // }
        if(n==x)
        {
            cout<<n<<endl;
            continue;
        }
        ll f=0;
        vector<ll>num1,num2;
        num1=decToBinary(n);
        num2=decToBinary(x);
        ll ans=0;
        repr(i,60,0)
        {
            if(num1[i]==0 && num2[i]==1)
            {
                f=1;
                break;
            }
            else if(num1[i]!=num2[i])
            {
                ans=power(2,i+1);
                break;
            }
        }
        if(f)
        cout<<"-1\n";
        else
        {
            cout<<x+ans<<"\n";
        }
    }
}