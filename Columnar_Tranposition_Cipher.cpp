#include<bits/stdc++.h>
using namespace std;
int main(void)
{
    int i,j,t,n,m,l;
    cout<<"Enter your key"<<endl;
    string key,plaintext;
    cin>>key;
    cout<<"Enter your plaintext"<<endl;
    cin>>plaintext;
    int hash[26];
    for(int i=0;i<key.length();i++)
    hash[key[i]-'a']=i ;
    int columns=key.length();
    int length_pt=plaintext.length();
    int rows=ceil((float)length_pt/columns);  
    char mat[rows+1][columns+1];
    int k=0;
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<columns;j++)
        {
            if(k<length_pt)
            mat[i][j]=plaintext[k++];
            else
            mat[i][j]='_';
                
        }
    }
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<columns;j++)
        cout<<mat[i][j]<<" ";
        cout<<"\n";
    }
    sort(key.begin(),key.end());
    string cipher="";
    for(int i=0;i<key.length();i++)
    {
        string temp="";
        int index=hash[key[i]-'a'];
        for(int j=0;j<rows;j++)
        temp=temp+mat[j][index];       
        cipher=cipher + temp;
    }
    cout<<cipher<<endl;
}