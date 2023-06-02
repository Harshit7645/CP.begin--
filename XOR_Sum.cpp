#include <iostream>
using namespace std;
typedef long long ll;
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
    	int l,r;
    	cin>>l>>r;
    	ll ans = 0;
        if(l == 0) ans++;
        ll p = 1;
        while(p <= r){
            if(p >= l) ans += p - l;
            p *= 2;
        }
        cout<<ans<<endl;
	}
    return 0;
}
