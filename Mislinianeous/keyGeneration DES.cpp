#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
	vector<int> p8{6, 7, 8, 9, 1, 2, 3, 4};
	vector<int> p10{6, 7, 8, 9, 10, 1, 2, 3, 4, 5};
	string input;
	cout<<"Enter the 10 bit input:"<<endl;
	cin>>input;
	vector<int> p10permuted(10);
	vector<int> k1(8);
	//Applying p10 permutation
	for(int i = 0; i<10; i++)
		p10permuted[i] = input[p10[i]-1]-48;
	
	cout<<"P10 key is:"<<endl;
	for(int i = 0; i<10; i++)
		cout<<p10[i]<< " ";
	
	cout<<"Bits after p10:"<<endl;
	for(int i = 0; i<10; i++)
		cout<< p10permuted[i]<< " ";
	
	
	//performing left shift on first halp of p10 permuted
	int firstbit = p10permuted[0];
	for(int i = 0; i<5; i++)
	{
		if(i == 4)
			p10permuted[i] = firstbit;
		else
			p10permuted[i] = p10permuted[i+1];
	}
	
	//Performing left shift on second half of p10 permuted
	firstbit = p10permuted[5];
	for(int i = 5; i<10; i++)
	{
		if(i == 9)
			p10permuted[i] = firstbit;
		else
			p10permuted[i] = p10permuted[i+1];		
	}
	
	cout<<"\np10permuted after left shift:"<<endl;
	for(int i = 0; i<10; i++)
		cout<<p10permuted[i]<< " ";
	
	cout<<"\np8 key:"<<endl;
	for(int i = 0; i<8; i++)
		cout<<p8[i]<<" ";
	
	cout<<"\nBits after p8 permutation"<<endl;
	for(int i = 0; i<8; i++)
	{
		k1[i] = p10permuted[p8[i]-1];
	}	
	cout<<"\nKey is : "<<endl;
	for(int i = 0; i<8; i++)
		cout<<k1[i]<<" ";
	
}