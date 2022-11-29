#include <iostream>
using namespace std;
int main()
{
    long long int n,k;
    cin>>n>>k;
    int ans=1;
    while((k%2)!=1)
    {
        k=k/2;
        ans++;
    }
    cout<<ans;
    return 0;
}