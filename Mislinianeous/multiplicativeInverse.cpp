#include <iostream>
using namespace std;
/*
	Multiplicative Inverse Property 
	X*(1/X) = 1
*/
int main()
{
	int i, number, multiInverse;
	cout<<"Enter the Number to find Multiplicative Inverse:"<<endl;
	cin>>number;
	for(int i = 1; i<=number; i++)
	{
		multiInverse = (i*26)+1;
		if(multiInverse % number == 0)
				break;
	}
	multiInverse /= number;
	cout<<"Multiplicative Inverse:"<<multiInverse<<endl;
}