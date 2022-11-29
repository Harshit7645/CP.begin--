#include <iostream>
using namespace std;
int main()
{
    int n,i,x=0;
    cin>>n;
    string s;
    for(i=0;i<n;i++)
    {
        cin>>s;
        if(s[1]=='+')
        x++;
        else
        x--;
    }
    cout<<x;
}