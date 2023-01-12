#include <iostream>
using namespace std;
int main()
{
	cout<<"Enter two number to find GCD:"<<endl;
	int a, b;
	cin >> a >> b;
	while(a != b)
	{
		if(a > b)
			a -= b;
		else
			b -= a;
	}
	cout<< "GCD of and b :"<< a;
}