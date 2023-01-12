#include <iostream>
using namespace std;
int naiveGCD(int a, int b)
{
	while(a != b)
	{
		if(a > b)
			a -= b;
		else
			b -= a;
	}
	return a;
}
int main()
{
	cout<<"Enter two number to find GCD:"<<endl;
	int a, b, GCD;
	cin >> a >> b;
	GCD = naiveGCD(a, b);
	cout<< "GCD of a and b :"<< GCD;
	
	
	// Naive GCD for array
	int arr[5] = {12, 54, 36, 99, 102 };
	GCD = arr[0];
	for(int i = 1; i<5; i++)
		GCD = naiveGCD(arr[i], GCD);
	cout<< "\nGCD of given array:"<< GCD<<endl;
}