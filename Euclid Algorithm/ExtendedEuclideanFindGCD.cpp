#include <iostream>
using namespace std;
//log(N)
int extendedGCD(int a, int b, int *x, int *y)
{
	if(a == 0)
	{
		*x = 0;
		*y = 1;
		return b;
	}
	int GCD, x1 = 0, y1 = 0;
	GCD = extendedGCD(b%a, a, &x1, &y1);
	*x = y1 - (b/a)*x1;
	*y = x1;
	return GCD;
}

int main()
{	
	//ax + by = gcd(a, b);
	int a, b;
	int x, y;
	cout<<"Enter a and b:";
	cin>> a >> b;
	int GCD  = extendedGCD(a, b, &x, &y);
	cout<<"GCD by Extended Euclidean:"<<GCD;
}
