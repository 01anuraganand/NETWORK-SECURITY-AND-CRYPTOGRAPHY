//Write file using password
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;
int main()
{
	string firstName, lastName, DOB;
	
	cout<<"Enter the first Name:"<<endl;
	cin>>firstName;
	cout<<"Enter the last Name:"<<endl;
	cin>>lastName;
	cout<<"Enter the DOB"<<endl;
	cin>>DOB;
	
	string password = "";
	int firstNameLen = firstName.size();
	int lastNameLen = lastName.size();
	
	string fPass = firstName.substr(0,2);
	string sPass = lastName.substr(lastNameLen -2);
	
	transform(fPass.begin(), fPass.end(), fPass.begin(), ::toupper);
	transform(sPass.begin(), sPass.end(), sPass.begin(), ::tolower);
	password += fPass;
	password += sPass;
	password += DOB.substr(4);
	
	cout<<"Enter the password to open the file."<<endl;
	string inputPass;
	cin>>inputPass;

	if(inputPass == password)
	{
		ofstream fout;
		string filename;
		cout<<"Enter the file name:"<<endl;
		cin>>filename;
		fout.open(filename+".txt", ios::out);
		fout<<"File Created Successfully.";
		cout<<"check the file in folder."<<endl;
		fout.close();
	}
	else
		cout<<"Password is wrong."<<endl;
}