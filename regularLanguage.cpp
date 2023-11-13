#include<iostream>
#include<string>
using namespace std;
char a,b;
int n,m;
long l;
string x,y,z,s;
void input()
{
    cout<<"Enter the language\n";
    //cin>>a>>n>>b>>m;
    a='0',b='1',n=2,m=2;
    cout<<"language is\n";
    char arr[n+m];
    for(int i=0;i<n;++i)
    {
        arr[i]=a;
    }
    for(int i=0;i<m;++i)
    {
        arr[i+n]=b;
    }
    s=arr;
    cout<<s;
    l=n+m;
}
void generate()
{
    for(int s1=1;s1<=l-2;++s1) 
    {
        for (int s2=s1+1;s2<=l-1;++s2) 
        {
            x=s.substr(0,s1);
            y=s.substr(s1,s2-s1);
            z=s.substr(s2);
            cout << "Part 1: " << x << endl;
            cout << "Part 2: " << y << endl;
            cout << "Part 3: " << z << endl;
            cout << "----------------------" << endl;
        }
    }

}
void check()
{

}
int main()
{
    input();
    generate();
}