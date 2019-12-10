#include <iostream>
using namespace std;

int main() {
	// your code goes here
	 int i,j,t,n,shift;
	 string msg;
	 cout<<"Enter key value";
	 cout<<endl;
	 cin>>shift;
	 cout<<"Enter your message"<<endl;
	 cin>>msg; 
	string cipher="";
	for(int i=0;i<msg.length();i++)
	{
	    int new_char=msg[i]+shift;
	    if(msg[i]>='a' && msg[i]<='z')
	    {
    	    if(new_char>122)
    	    {
    	        new_char=new_char-122-1 + (int)'a';
    	        cipher=cipher + (char)new_char;
    	    }
    	    else
    	    cipher=cipher + (char)new_char;
	    }
	    else if(msg[i]>='A' && msg[i]<='Z')
	    {
    	    if(new_char>90)
    	    {
    	        new_char=new_char-90-1 + (int)'A';
    	        cipher=cipher + (char)new_char;
    	    }
    	    else
    	    cipher=cipher + (char)new_char;
	    }
	}
	cout<<cipher<<endl;
	return 0;
}
