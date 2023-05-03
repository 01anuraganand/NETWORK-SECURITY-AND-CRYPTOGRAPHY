#include <stdio.h>
#include <math.h>
#include<iostream>
using namespace std;
long long int power(long long int a, long long int Xa, long long int q)
{
	if(Xa == 1)
		return a;
	else
		return ((long long int)pow(a, Xa) % q);
}

int main()
{
	long long int  q, a, Xa, Xb, Ya, Yb;
	cout<<"Enter the q(prime Number):"<<endl;
	cin>>q; // 23
	
	cout<<"Enter the a:"<<endl;
	cin>>a; //9
	
	cout<<"Enter Random Secret Key Xa and Xb:"<<endl;
	cin>>Xa >> Xb; // 4 3
	
	cout<<"Respective Public Key:"<<endl;
	Ya = power(a, Xa, q);
	Yb = power(a, Xb, q);
	
	cout<<Ya<<endl;
	cout<<Yb<<endl;
	
	cout<<"Compute Shared Session Key."<<endl;
	long long int Kab = fmod(pow(Yb, Xa), q);
	long long int  Kba = fmod(pow(Ya, Xb), q);
	cout<<Kab <<endl;
	cout<<Kba <<endl;	
}