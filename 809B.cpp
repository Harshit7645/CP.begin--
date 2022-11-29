#include <bits/stdc++.h> 
typedef long long ll;
using namespace std;
int gcd(int a, int b)
{
    if (a == 0)
    return b;
    return gcd(b % a, a);
}
vector <int> vcreate(int n){
    vector <int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    return v;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    { 
        int n; 
        cin>>n;
        vector<int> ans(n+1,0);
        map <int,int> m;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin>>x;
            if(m[x]==0) {
                m[x]=i+1;
                ans[x]=1;
            }
            else{
                if((m[x]-(i+1))%2){
                    ans[x]++;
                    m[x]=i+1;
                }
            }
        }
        for (int i = 1; i < n+1; i++)
        {
            cout<<ans[i]<<" ";
        }
        cout<<endl;        
    }
    return 0;
}