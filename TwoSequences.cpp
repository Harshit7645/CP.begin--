#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(i=a;i<b;i++)
#define PNO cout<<"NO\n"
#define PYES cout<<"YES\n"
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, m; string a, b;
		cin >> n >> m >> a >> b;
		string b_b = b.substr(1, m - 1);
		string a_a = a.substr(n - m + 1, m - 1);
		if (a_a != b_b)
			PNO;
		else {
			bool ok = false;
			for (int i = 0; i < n - m + 1; ++i) {
				if (a[i] == b[0])
					ok = true;
			}
			if (!ok) PNO;
			else PYES;
		}
	}
	return 0;
}