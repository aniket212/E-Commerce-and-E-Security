
/*Created by Aniket
				Rajani
*/

#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int i,j,t,n,m;
	string key;
	string plain_text;
	cout<<"Enter the value of key";
	cin>>key;
	
	bool present[26]={false};
	string key_no_dup="";
	for(int i=0;i<key.length();i++)
	{
	    if(!present[key[i]-'a'])
	    {
	        key_no_dup=key_no_dup+key[i];
	        present[key[i]-'a']=true;
	    }
	}
	int length_no_dup=key_no_dup.length();
	int k=0;
	int key_len=key.length();
	char key_mat[5][5];
	for(int i=0;i<5;i++)
	{
	    for(int j=0;j<5;j++)
	    {
	        if(k<length_no_dup)
	        {
	            key_mat[i][j]=key_no_dup[k];
	            k++;
	        }
	        else
	        {
	            char ch;
	            for(int l=0;l<26;l++)
	            {
	                if(!present[l] and l!=9)
	                {
	                    present[l]=true;
	                    ch=(char)l+'a';
	                    break;
	                }
	            }
	            key_mat[i][j]=ch;
	        }
	    }
	}
	printf("Key Matrix");
	printf("\n");
	for(int i=0;i<5;i++)
	{
	    for(int j=0;j<5;j++)
	    cout<<key_mat[i][j]<<" ";
	    cout<<endl;
	}
	cout<<"Enter plain text"<<endl;
	cin>>plain_text;
	
	int len_plain=plain_text.length();
	if(len_plain%2!=0)
	plain_text=plain_text+'z';
	
	len_plain+=1;
	int row,row1,column,column1;
	string cipher_text="";
	for(int i=0;i<plain_text.length();i+=2)
	{
	    for(int j=0;j<5;j++)
	    {
	        for(int k=0;k<5;k++)
	        {
	            if(key_mat[j][k]==plain_text[i])
	            {
	                row=j;
	                column=k;
	            }
	            if(key_mat[j][k]==plain_text[i+1])
	            {
	                row1=j;
	                column1=k;
	            }
	        }
	    }
	    if(row==row1)
	    cipher_text=cipher_text+key_mat[row][(column+1)%5]+key_mat[row1][(column1+1)%5]+' ';
	    else if(column==column1)
	    cipher_text=cipher_text+key_mat[(row+1)%5][column]+key_mat[(row1+1)%5][column1]+' ';
	    else
	    {
	        int max_row=max(row,row1);
	        int min_row=min(row,row1);
	        int min_column=min(column,column1);
	        int max_column=max(column,column1);
	        cipher_text=cipher_text+ key_mat[row][column1]+key_mat[row1][column]+' ';
	    }
	}
	cout<<"Encrypted Text: ";
	cout<<cipher_text<<endl;
}