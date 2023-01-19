#include <iostream>
using namespace std;
int main()
{
	char str[100];
	cout<<"Enter the string to convert to ASCII code:"<<endl;
	cin.getline(str, 100);
	for(int i = 0; str[i] != '\0'; i++)
		cout<<str[i] << "\t"<< int(str[i])<<endl;
	
}