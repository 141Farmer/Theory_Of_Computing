#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

vector<vector<vector<char>>> nfaTransi;
vector<char>nfaStates,symbols;
char nfaLast,nfaFirst;
int nfaNumStates,numSymbols,i,j;

vector<vector<string>> dfaTransi;
vector<string>dfaStates;
string dfaLast,dfaFirst;
int dfaNumStates;

void readInput()
{
    cout<<"Enter number of nfaStates and number of alphabets\n";
    cin>>nfaNumStates>>numSymbols;

    nfaStates=vector<char>(nfaNumStates);
    symbols=vector<char>(numSymbols);
    cout<<"Enter nfaStates\n";
    for(i=0;i<nfaNumStates;++i) cin>>nfaStates[i];
    cout<<"Enter alphabets\n";
    for(i=0;i<numSymbols;++i) cin>>symbols[i];

    nfaTransi=vector<vector<vector<char>>>(nfaNumStates,vector<vector<char>>(numSymbols));
    for(i=0;i<nfaNumStates;++i)
    {
        for(j=0;j<numSymbols;++j)
        {
            cout<<"From "<<nfaStates[i]<<" through "<<symbols[j]<<" enter where \n";
            char tempNfaStates;
            while(cin>>tempNfaStates and tempNfaStates!='0')
            {
                  nfaTransi[i][j].push_back(tempNfaStates);
            }
        }
    }

    cout<<"Enter start \n";
    cin>>nfaFirst;
    cout<<"Enter final state\n";
    cin>>nfaLast;

} 
void dfa()
{
    dfaNumStates=nfaNumStates;
    dfaTransi=vector<vector<string>>(dfaNumStates);
    dfaFirst=nfaFirst;
    cout<<nfaFirst<<endl;
    dfaStates.push_back(dfaFirst);
    cout<<dfaStates[0]<<endl;
    for(i=0;i<nfaNumStates;++i)
    {
        for(j=0;j<numSymbols;++j)
        {
            string str;
            for(auto it: nfaTransi[i][j])
            {
                str+=it;
            }
            if(find(dfaStates.begin(),dfaStates.end(),str)==dfaStates.end())
                dfaStates.push_back(str);
            dfaTransi[i].push_back(str);
        }
    }
}
void printDfa()
{
    //cout<<"First state of dfa is : "<<dfaFirst<<endl;
    cout<<"States of dfa are\n";
    for(auto it: dfaStates) cout<<it<<" ";
    cout<<endl;
    for(i=0;i<dfaNumStates;++i)
    {
        for(j=0;j<numSymbols;++j)
        {
            cout<<"From "<<dfaStates[i]<<" through "<<symbols[i]<<" to "<<dfaTransi[i][j]<<endl;

        }
    }


}
int main()
{
    freopen("INPUT.TXT","r",stdin);
    readInput();
    dfa();
    printDfa();
}