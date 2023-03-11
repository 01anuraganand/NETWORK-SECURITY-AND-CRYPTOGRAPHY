#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	char I[] = "11000110";
	char leftI[4];
	char rightI[4];
	for(int i = 0; i<4; i++)
		leftI[i] = I[i];
	for(int i = 4; i<8; i++)
		rightI[i-4] = I[i];
	
	char key[] = "1011";
	char halfXOR[4];
	
	for(int i = 0; i<4; i++)
	{
		if (key[i] == rightI[i])
			halfXOR[i] = '0';
		else	
			halfXOR[i] = '1';
		
	}
	
	for(int i = 0; i<8 ;i++)
	{
		if(i <4)
			I[i] = halfXOR[i];
		else
			I[i] = leftI[i-4];
	}
	
	for(int i = 0; i<8; i++)
		cout<<I[i]<< " ";
}
