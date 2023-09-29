#include<iostream>
#include<algorithm>
using namespace std;
bool isPlndrm(string s)
{
    int l=s.length(),c1=count(s.begin(),s.end(),'0'),c2=count(s.begin(),s.end(),'1');
    if((c1+c2)!=l)  return 0;
    for(int i=0;i<l/2;++i)  if(s[i]!=s[l-i-1])  return 0;
    return 1;
}
void check(string s)
{
    int l=s.length();
    if(s=="") cout<<"P -> epsilon -> "<<endl;
    else if(l>1 and s[0]=='0' and s[l-1]=='0') cout<<"P-> 0P0 -> "<<s<<endl;
    else if(l>1 and s[0]=='1' and s[l-1]=='1') cout<<"P -> 1P1 -> "<<s<<endl;
    else if(l==1 and s[0]=='0')  cout<<"P -> 0 -> "<<s<<endl;
    else cout<<"P -> 1 -> "<<s<<endl;
}
void input(string &s)
{
    if(freopen("cfgInput.txt","r",stdin)==NULL) cout<<"!F\n";
    while(cin>>s)
    {
        cout<<s<<endl;
        if(!isPlndrm(s)) cout<<"Not in this grammer\n";
        else if(isPlndrm(s))  check(s);
    }
}
int main()
{
    string s;
    input(s);
}