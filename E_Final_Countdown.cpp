#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,a,b) for(ll i=a;i>=b;i--)
#define PNO cout<<"NO\n"
#define PYES cout<<"YES\n"
#define vll vector<ll>;
#define all(x) x.begin(),x.end()
int M=1e9+7;

string findSum(string str1, string str2) 
{ 
    // Remove leading zeros from both strings
    str1.erase(0, min(str1.find_first_not_of('0'), str1.size()-1));
    str2.erase(0, min(str2.find_first_not_of('0'), str2.size()-1));
 
    // If both strings become empty, return "0"
    if (str1.empty() && str2.empty()) 
        return "0";
 
    // Before proceeding further, make sure length 
    // of str2 is larger. 
    if (str1.length() > str2.length()) 
        swap(str1, str2); 
 
    // Take an empty string for storing result 
    string str = ""; 
 
    // Calculate length of both string 
    int n1 = str1.length(), n2 = str2.length(); 
    int diff = n2 - n1; 
 
    // Initially take carry zero 
    int carry = 0; 
 
    // Traverse from end of both strings 
    for (int i=n1-1; i>=0; i--) 
    { 
        // Do school mathematics, compute sum of 
        // current digits and carry 
        int sum = ((str1[i]-'0') + 
                (str2[i+diff]-'0') + 
                carry); 
        str.push_back(sum%10 + '0'); 
        carry = sum/10; 
    } 
 
    // Add remaining digits of str2[] 
    for (int i=n2-n1-1; i>=0; i--) 
    { 
        int sum = ((str2[i]-'0')+carry); 
        str.push_back(sum%10 + '0'); 
        carry = sum/10; 
    } 
 
    // Add remaining carry 
    if (carry) 
        str.push_back(carry+'0'); 
 
    // reverse resultant string 
    reverse(str.begin(), str.end()); 
 
    return str; 
} 

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll tt=1;
    cin>>tt;
    while(tt--)
    {
        ll n;
        cin>>n;
        string s;
        cin>>s;
        reverse(s.begin(),s.end());
        string ans="";
        ll carry=0,sum=0;
        rep(i,0,n)
        {
            sum+=(s[i]-'0');
        }           
        rep(i,0,n)
        {
            ans.push_back((char)('0'+((sum+carry)%10)));
            carry=(sum+carry)/10;
            sum-=(s[i]-'0');
        }
        while(carry>0)
        {
            ans.push_back((char)('0'+carry%10));
            carry/=10;
        }
        reverse(ans.begin(),ans.end());
        ll ind=0;
        while(ans[ind]=='0')
        ind++;
        ans=ans.substr(ind);
        cout<<ans<<"\n";
    }
}   