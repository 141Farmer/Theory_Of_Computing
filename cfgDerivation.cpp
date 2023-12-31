#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int numSymbol;
vector<string> symbols;
vector<vector<string>> grammer;
string s;

void input()
{
    if(freopen("cfgDerivation.txt","r",stdin)==NULL) 
        cout<<"!F\n";
    cout<<"Enter number of symbols\n";
    cin>>numSymbol;
    int i;
    string temp;
    cout<<"Enter symbols\n";
    for(i=0;i<numSymbol;++i) 
    {
        cin>>temp;
        symbols.push_back(temp);
    }
    grammer.resize(numSymbol);
    cout<<"Enter grammer\n";
    for(i=0;i<numSymbol;++i)
    {
        while(cin>>temp and temp!="0")
        {
            grammer[i].push_back(temp);
        }
    }
    cout<<"Enter string\n";
    cin>>s;
}

bool check(string current,int index)
{
    if(index>=current.length()) 
        return false;
    for(int i=0;i<index;++i)
    {
        if(current[i]!=s[i]) 
            return false;
    }
    return true;
}

string derivation(string temp)
{
    string current=temp;
    int l=current.length();
    vector<string>derivations(numSymbol,current);
    for(int i=1;i<numSymbol;++i)
    {
        string str=symbols[i];
        int idx=derivations[i].find(str);
        while(idx!=string::npos)
        {
            for(string rule: grammer[i])
            {
                string newStr=derivations[i];
                newStr.replace(idx,idx,rule);
                derivations[i]=newStr;
                if(check(newStr,idx+str.length()))
                {
                    return newStr;
                }
            }
            idx=derivations[i].find(str,idx+1);
            //current.replace(current.find(symbols[i]),symbols[i].length(),"");
            //erase(current,symbols[i][0]);
            current.erase(remove(current.begin(),current.end(),symbols[i][0]),current.end());
            return current;
        }
    }
    return temp;
}

void leftDerivation()
{
    string temp=grammer[0][0];
    cout<<temp<<endl;
    while(temp!=s)
    {
        string next=derivation(temp);
        if(next==temp)
        {
            cout<<"Not possible\n";
            return;
        }
        temp=next;
        cout<<temp<<endl;
    }
}

void rightDerivation()
{
    string temp=grammer[0][0];
    cout<<temp<<endl;
    string revTemp=string(temp.rbegin(),temp.rend());
    while(temp!=s)
    {
        
    }
}

int main()
{
    input();
    leftDerivation();
    rightDerivation();
}