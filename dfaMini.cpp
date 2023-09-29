<<<<<<< HEAD
#include<iostream>
#include<vector>
using namespace std;
int numState,numAlphas;
vector<string> states,alphas;
vector<vector<string> > transi;
void input()
{
      int i,j;
      cout<<"Enter number of states and number of alphabets\n";
      cin>>numState>>numAlphas;
      states.resize(numState),alphas.resize(numAlphas);
      cout<<"Enter states\n";
      for(i=0;i<numState;++i) cin>>states[i];
      cout<<"Enter alphabets\n";
      for(i=0;i<numAlphas;++i) cin>>alphas[i];
      transi.resize(numState,vector<string>(numAlphas));
      for(i=0;i<numState;++i)
      {
            for(j=0;j<numAlphas;++j)
            {
                cout<<"From "<<states[i]<<" through "<<alphas[j]<<" enter where \n";
                cin>>transi[i][j];
            }
      }

}
void minimize()
{
      int i,j,k;
      vector<vector<bool> > table(numState,vector<bool>(numState,0));
      for(i=0;i<numState;++i)
      {
            for(j=0;j<numAlphas;++j)
            {
                  for(k=0;k<numState;++k)
                  {
                        if(transi[i][j]==states[k] and i>k)
                        {
                              table[i][k]=1;
                        }
                  }
            }
      }
      for(vector<bool> it : table)
      {
            for(bool x : it)
            {
                  cout<<x<<" ";
            }
            cout<<endl;
      }
}
int main()
{
      freopen("dfaMini.txt","r",stdin);
      input();
      minimize();
=======
#include<iostream>
#include<vector>
using namespace std;
int numState,numAlphas;
vector<string> states,alphas;
vector<vector<string> > transi;
void input()
{
      int i,j;
      cout<<"Enter number of states and number of alphabets\n";
      cin>>numState>>numAlphas;
      states.resize(numState),alphas.resize(numAlphas);
      cout<<"Enter states\n";
      for(i=0;i<numState;++i) cin>>states[i];
      cout<<"Enter alphabets\n";
      for(i=0;i<numAlphas;++i) cin>>alphas[i];
      transi.resize(numState,vector<string>(numAlphas));
      for(i=0;i<numState;++i)
      {
            for(j=0;j<numAlphas;++j)
            {
                cout<<"From "<<states[i]<<" through "<<alphas[j]<<" enter where \n";
                cin>>transi[i][j];
            }
      }

}
void minimize()
{
      int i,j,k;
      vector<vector<bool> > table(numState,vector<bool>(numState,0));
      for(i=0;i<numState;++i)
      {
            for(j=0;j<numAlphas;++j)
            {
                  for(k=0;k<numState;++k)
                  {
                        if(transi[i][j]==states[k] and i>k)
                        {
                              table[i][k]=1;
                        }
                  }
            }
      }
      for(vector<bool> it : table)
      {
            for(bool x : it)
            {
                  cout<<x<<" ";
            }
            cout<<endl;
      }
}
int main()
{
      freopen("dfaMini.txt","r",stdin);
      input();
      minimize();
>>>>>>> ae40c67 (29 sep)
}