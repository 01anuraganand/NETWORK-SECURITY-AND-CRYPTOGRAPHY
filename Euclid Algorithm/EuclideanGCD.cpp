#include <iostream>
using namespace std;
int EuclideanGCD(int a, int b)
{
	if(a == 0)
		return b;
	return EuclideanGCD(b % a, a);
}
int main()
{
	cout<<"Enter two number to find GCD:"<<endl;
	int a, b, GCD;
	cin >> a >> b;
	GCD = EuclideanGCD(a, b);
	cout<< "GCD of a and b :"<< GCD;
	
	
	// Euclidean GCD for array
	int arr[5] = {12, 54, 36, 99, 102 };
	GCD = arr[0];
	for(int i = 1; i<5; i++)
		GCD = EuclideanGCD(arr[i], GCD);
	cout<< "\nGCD of given array:"<< GCD<<endl;
}