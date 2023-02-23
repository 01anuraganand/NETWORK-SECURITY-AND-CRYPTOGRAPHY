#include <iostream>
#include<string.h>
#include <math.h>
using namespace std;
bool isPrime(int number)
{
	int divCount = 0;
	for(int i = 1; i<=number; i++)
	{
		if(number % i == 0)
			divCount++;
	}
	return divCount==2 ? true:false;
}
int main()
{
	int a, p;
	cout<<"Enter the value of p:"<<endl;
	cin>>p;
	cout<<"Enter the value of a:"<<endl;
	cin>>a;
	if(p % a == 0)
		cout<<"Fermat Theorem not satisfied."<<endl;
	else if(isPrime(p) && a > 0)
	{
		int x = pow(a, p-1);
		cout<<"X value:"<<x <<endl;
		if(x % p == 1) 
			cout<<"Fermat Theorem sttisfied."<<endl;
		else
			cout<<"Fermat Theorem not satisfied."<<endl;
	}
}