#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

vector<int> extendedGCD(int a, int b)
{
	int r1 = a, r2 = b;
	int  s1 = 1, s2 = 0, t1 = 0, t2 = 1;
	while(r2 > 0)
	{
		int q = r1 / r2;
		int r = r1 - q*r2;
		r1 = r2;
		r2 = r;
		
		int s = s1 - q*s2;
		s1 = s2;
		s2 = s;
		
		int t = t1 - q*t2;
		t1 = t2;
		t2 = t;
	}
	if(t1 < 0)
		t1 = t1 % a;
	return {r1, t1};
}

int GCD(int a, int b)
{
	if(a == 0)
		return b;
	return GCD(b%a, a);
}

int main()
{
	int p, q, M;
	cout<<"Enter two prime Number p:"<<endl;
	cin>>p;
	cout<<"Enter the value of q:"<<endl;
	cin>>q;
	int n = p*q;
	int phiN = (p-1)*(q-1);
	
	vector<int> key;
	for(int i = 2; i<phiN; i++)
	{
		int gcd = GCD(phiN, i);
		if(gcd == 1)
			key.push_back(i);
	}
	int e = key[1];
	cout<<"Public Key Encryption:{"<<e<<","<<n<<"}"<<endl;
	vector<int> rd = extendedGCD(phiN, e);
	int r = rd[0], d = rd[1];
	if(r == 1)
		cout<<"Private key Decryption:{"<<d<<","<<n<<"}"<<endl;
	else
		cout<<"Multiplicative Inverse for the given Encryption key does not exit. Choose Different Encryption key."<<endl;
	
	cout<<"Enter the number to encrypt:"<<endl;
	
	cin>>M;
	int encrypt = fmod(pow(M, d), n);
	cout<<"Encrypted:"<<encrypt<<endl;
	
	int decrypt = fmod(pow(encrypt, e), n);
	cout<<"Decrypted:"<<decrypt<<endl;
	
}