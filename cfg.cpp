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
void check(string s,int begin,int end)
{
    if(begin>end) 
    {
        cout<<s<<endl;
        return;
    }
    for(int i=0;i<begin;++i)  cout<<s[i];
    if(begin!=end)  cout<<"P";
    for(int i=end;i<s.length();++i)  cout<<s[i];
    cout<<"-> ";
    check(s,begin+1,end-1);
}
void input(string &s)
{
    if(freopen("cfgInput.txt","r",stdin)==NULL)  cout<<"!F\n";
    while(cin>>s)
    {
        cout<<s<<endl;
        if(!isPlndrm(s))  cout<<"Not in this grammer\n";
        else if(isPlndrm(s))  check(s,0,s.length());
    }
}
int main()
{
    string s;
    input(s);
}