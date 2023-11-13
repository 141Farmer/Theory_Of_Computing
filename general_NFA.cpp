#include<vector>
#include<iostream>
using namespace std;
vector<vector<vector<char>>> transi;
vector<char>states,alphas;
char last;

bool traverseNFA(char state,string &str,int Index)
{
    if(Index==str.size())
    {
      cout<<state<<" ";
       return state==last;
    }
    vector<char>nextStates;
    for(int j=0;j<alphas.size();++j)
    {
        if(str[Index]==alphas[j])
        {
            for(char nextState:transi[state-'0'][j])
            {
                nextStates.push_back(nextState);
            }
        }
    }
    for(char nextState:nextStates)
    {
        if(traverseNFA(nextState,str,Index + 1))
        {
            cout<<nextState<<" ";
            return true;
        }
            
    }
    return false;
}

int main()
{
    int numState,numAlphas,i,j;
    cout<<"Enter number of states and number of alphabets\n";
    cin>>numState>>numAlphas;

    states=vector<char>(numState);
    alphas=vector<char>(numAlphas);
    cout<<"Enter states\n";
    for(i=0;i<numState;++i) cin>>states[i];
    cout<<"Enter alphabets\n";
    for(i=0;i<numAlphas;++i) cin>>alphas[i];

    transi=vector<vector<vector<char>>>(numState,vector<vector<char>>(numAlphas));
    for(i=0;i<numState;++i)
    {
        for(j=0;j<numAlphas;++j)
        {
            cout<<"From "<<states[i]<<" through "<<alphas[j]<<" enter where \n";
            char tempStates;
            while(cin>>tempStates and tempStates!='0')
            {
                  transi[i][j].push_back(tempStates);
            }
        }
    }

    string str;
    char start;
    cout<<"Enter start \n";
    cin>>start;
    cout<<"Enter final state\n";
    cin>>last;
    cout<<"Enter the string\n";
    cin>>str;
    /*for(i=0;i<str.size();++i)
    {
        for(j=0;j<numAlphas;++j)
        {
            if(str[i]==alphas[j])
            {
                curr=transi[curr-start][j];
                break;
            }
        }
        cout<<curr<<" ->";
    }

    for(unsigned long long k=0;k<str.size();++k)
    {
      curr.clear();
      for(j=0;j<numAlphas;++j)
      {
            if(str[k]==alphas[j])
            {
                  for(auto stt: transi[k][j])
                  {
                        curr.push_back(stt);
                  }
            }
      }
    }*/
    /*for(int k=0;i<str.size();++i)
    {
         curr.clear();
        for(char state: curr)
        {
            for(j=0;j<numAlphas;++j)
            {
                  if(str[k]==alphas[j])
                  {
                        for(auto stt: transi[state-states[0]][j])
                        {
                              curr.push_back(stt);
                        }
                  }
            }
        }
    }
    next=curr;
    for(char stt: next)
    {
      cout<<stt<<" ";
      if(stt==last)
      {
            cout<<"\nAccepted\n ";
            return 0;
      }
    }
    cout<<"\nRejected\n";
    */
    if(traverseNFA(start,str,0)) cout<<"\nAccepted\n";
    else cout<<"\nRejected\n";
}
