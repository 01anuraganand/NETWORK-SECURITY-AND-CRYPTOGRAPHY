//Read file using password
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int main()
{
	string firstName = "ANURAG";
	string lastName = "ANAND";
	string DOB = "23022023";
	
	string password = "";
	int firstNameLen = firstName.size();
	int lastNameLen = lastName.size();
	password += firstName.substr(firstNameLen-2);
	password += lastName.substr(lastNameLen -2);
	password += DOB;
	
	cout<<"Enter the password to open the file."<<endl;
	string inputPass;
	cin>>inputPass;
	char ch;
	if(inputPass == password)
	{
		ifstream fin;
		fin.open("abc.txt", ios::in);
		while(!fin.eof())
		{
			fin.get(ch);
			cout<<ch;
		}
		fin.close();
	}
	else
		cout<<"Password is wrong."<<endl;
}