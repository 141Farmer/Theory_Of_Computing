#include<vector>
#include<iostream>
using namespace std;
int main()
{
    int numState,numAlphas,i,j;
    cout<<"Enter number of states and number of alphabets\n";
    cin>>numState>>numAlphas;
    vector<char> states(numState),alphas(numAlphas);
    cout<<"Enter states\n";
    for(i=0;i<numState;++i) cin>>states[i];
    cout<<"Enter alphabets\n";
    for(i=0;i<numAlphas;++i) cin>>alphas[i];
    vector<vector<char>> transi(numState,vector<char>(numAlphas));
    for(i=0;i<numState;++i)
    {
        for(j=0;j<numAlphas;++j)
        {
            cout<<"From "<<states[i]<<" through "<<alphas[j]<<" enter where \n";
            cin>>transi[i][j];
        }
    }
    string str;
    char start,curr,last;
    cout<<"Enter start \n";
    cin>>start;
    cout<<"Enter final state\n";
    cin>>last;
    cout<<"Enter the string\n";
    cin>>str;
    curr=start;
    for(i=0;i<str.size();++i)
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
    cout<<endl;
    if(curr!=last) cout<<"Rejected\n";
    else cout<<"Accepted\n"; 
}