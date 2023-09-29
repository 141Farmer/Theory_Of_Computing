<<<<<<< HEAD
#include<iostream>
#include<vector>
using namespace std;
int numState=3;
int numSymbol=2;
vector<string> states={"q1","q2","q3"};
vector<vector<string>> table={
    {"q1","q2","q3"},
    {"q2","q3","q3"},
    {"q3","q3","q2"}
};
vector<vector<string>>transi={
    {"e + 1","0","e"},
    {"1","e","0"},
    {"e","1","e + 0"}
};
vector<vector<vector<string>>> memo;
string rE(int i,int j,int k)
{
    if(k==0) return memo[i][j][k]=transi[i][j];
    if(memo[i][j][k]!="") return memo[i][j][k];
    return memo[i][j][k]=rE(i,j,k-1)+" + "+rE(i,k,k-1)+" ("+rE(k,k,k-1)+")* "+rE(k,j,k-1);
}

int main()
{
    memo.resize(numState,vector<vector<string>>(numState,vector<string>(numState,"")));
    for(int k=0;k<3;++k)
    {
        for(int i=0;i<numState;++i)
        {
            for(int j=0;j<numState;++j)
            {
                cout<<"R"<<i+1<<j+1<<"("<<k<<") = "<<rE(i,j,k)<<endl;
            }
            cout<<endl;
        }
        cout<<endl;
    } 
=======
#include<iostream>
#include<vector>
using namespace std;
int numState=3;
int numSymbol=2;
vector<string> states={"q1","q2","q3"};
vector<vector<string>> table={
    {"q1","q2","q3"},
    {"q2","q3","q3"},
    {"q3","q3","q2"}
};
vector<vector<string>>transi={
    {"e + 1","0","e"},
    {"1","e","0"},
    {"e","1","e + 0"}
};
vector<vector<vector<string>>> memo;
string rE(int i,int j,int k)
{
    if(k==0) return memo[i][j][k]=transi[i][j];
    if(memo[i][j][k]!="") return memo[i][j][k];
    return memo[i][j][k]=rE(i,j,k-1)+" + "+rE(i,k,k-1)+" ("+rE(k,k,k-1)+")* "+rE(k,j,k-1);
}

int main()
{
    memo.resize(numState,vector<vector<string>>(numState,vector<string>(numState,"")));
    for(int k=0;k<3;++k)
    {
        for(int i=0;i<numState;++i)
        {
            for(int j=0;j<numState;++j)
            {
                cout<<"R"<<i+1<<j+1<<"("<<k<<") = "<<rE(i,j,k)<<endl;
            }
            cout<<endl;
        }
        cout<<endl;
    } 
>>>>>>> ae40c67 (29 sep)
}