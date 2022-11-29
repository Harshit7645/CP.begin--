//this is the code for Question 5 of Lab 5 multiply 2 numbers.
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define PNO cout<<"No\n"
#define PYES cout<<"Yes\n"
#define vll vector<ll>;
string multiply(string num1, string num2)
{
    int len1 = num1.size();
    int len2 = num2.size();
    if (len1 == 0 || len2 == 0)
    return "0";
    vector<int> result(len1 + len2, 0);
    int i_n1 = 0;
    int i_n2 = 0;
    for (int i=len1-1; i>=0; i--)
    {
        int carry = 0;
        int n1 = num1[i] - '0';
        i_n2 = 0;          
        for (int j=len2-1; j>=0; j--)
        {
            int n2 = num2[j] - '0';
            int sum = n1*n2 + result[i_n1 + i_n2] + carry;
            carry = sum/10;
            result[i_n1 + i_n2] = sum % 10; 
            i_n2++;
        }
        if (carry > 0)
            result[i_n1 + i_n2] += carry;
        i_n1++;
    }
    int i = result.size() - 1;
    while (i>=0 && result[i] == 0)
    i--;
    if (i == -1)
    return "0";
    string s = "";    
    while (i >= 0)
        s += std::to_string(result[i--]);
 
    return s;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string str1="\0",str2="\0";
    ll n,m;
    cin>>n>>m;
    rep(i,0,n)
    {
        char ch;
        cin>>ch;
        str1+=ch;
    }
    rep(i,0,m)
    {
        char ch;
        cin>>ch;
        str2+=ch;
    }
    cout<<multiply(str1,str2);
}
