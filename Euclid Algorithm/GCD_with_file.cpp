#include <iostream>
#include <fstream>
using namespace std;

int EuclideanGCD(int a, int b)
{
	if (a == 0)
		return b;
	return EuclideanGCD(b % a, a);
}

int main()
{
	int a, b, GCD;
	ifstream fin;
	fin.open("GCD_with_file.txt", ios::in);
	fin>> a;
	fin>> b;
	a = int(a);
	b = int(b);
	fin.close();
	ofstream fout;
	fout.open("GCD_with_file.txt", ios::app);
	GCD = EuclideanGCD(a, b);
	fout<<endl;
	fout<<GCD;
	fout.close();
	cout<<"GCD for two readed Variable is : "<< GCD<<endl;
}