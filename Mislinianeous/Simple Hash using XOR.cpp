//simple hash using 8 bit XOR (^)
#include<iostream>
#include <string>
using namespace std;
int main()
{
	string PlainText, KeyText;
	cout<<"Enter your plaint text in bits(8)\n";
	cin>>PlainText;
	cout<<"Enter the key (8 bits)\n";
	cin>>KeyText;
	
	int i;
	char ch;
	
	for(i=0;i<8;i++)
	{
		ch=PlainText[i]^KeyText[i];
		cout<<int(ch);
	}	
}