#include<iostream>
#include<vector>
using namespace std;
void generate() 
{ 
    char alphabet[]={'0','1'}; 
    for(int i=0;i<5;++i)
    {
        int len=rand()%10;
        string s="";
        for(int j=0;j<len;++j)
        {
            s+=alphabet[rand()%2];
        }
        cout<<"Random string is: "<<s<<" it's length is: "<<len<<endl;
    } 
}
bool check(string w)
{
    for(char c:w)
    {
        if(c!='1' and c!='0')    return false;
    }
    return true;
}
void epsilonK(int k,string str)
{
    if(k==0)    cout<<str<<endl;
    else
    {
        epsilonK(k-1,str+"0");
        epsilonK(k-1,str+"1");
    }


}
bool palindrome(string s)
{
    int l=s.length();
    for(int i=0;i<l/2;++i)
    {
        if(s[i]!=s[l-i-1]) return false;
    }
    return true;
}
int main()
{
    generate();
    string w,x,y,s;
    int k;
    if(freopen("1Input.txt","r",stdin)==NULL) cout<<"!F\n";
    cin>>w>>x>>y>>k>>s;
    (check(w)) ? cout<<w<<" is in the language\n" : cout<<w<<" is not in the language\n";
    cout<<"Concated string of "<<x<<" and "<<y<<" is "<<x+y<<endl;
    cout<<"All permuation of "<<k<<" is \n";
    epsilonK(k,"");
    (check(s)) ? cout<<s<<" is palindrome\n":cout<<s<<" is not palindrome\n";
}