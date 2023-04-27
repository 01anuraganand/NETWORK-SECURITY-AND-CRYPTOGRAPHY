#include <iostream>
#include <string>
#include <fstream>
using namespace std;
char alphabet[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L','M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
string encryption(string plainText, string key)
{
	string encryptedText = "";
	for(int i = 0; i<plainText.size(); i++)
	{
		int val = (plainText[i]-'A') + int(key[i]-'A');
		if(val > 25)
			encryptedText += alphabet[val-26];
		else if(val >=0 && val <=25 )
			encryptedText += alphabet[val];
	}
	return encryptedText;
}
string decryption(string encryptedText, string key)
{
	string decryptedText = "";
	for(int i = 0; i<encryptedText.size(); i++)
	{
		int val = int(encryptedText[i]-'A') - int(key[i] - 'A');
		if(val < 0)
			decryptedText += alphabet[val+26];
		else if(val >=0 && val <=25 )
			decryptedText += alphabet[val];
		
	}
	return decryptedText;
}


int main()
{
	string plainText, key;
	cout<<"Enter the PlainText:"<<endl;
	cin>>plainText;
	ifstream fin;
	string line;
	string wholeLine;
	fin.open("vernamText.txt", ios::in);
	
	while(!fin.eof())
	{
		getline(fin, line);
		wholeLine += line;
	}
	fin.close();
	cout<<"Key from file:"<<wholeLine<<endl;
	
	key = wholeLine;
	string EncryptedText = encryption(plainText, key);
	cout<<"Encrypted Text:"<<EncryptedText<<endl;
	ofstream fout;
	fout.open("vernamText.txt", ios::app);
	fout<<"\n";
	fout<<EncryptedText;
	
	string DecryptedText = decryption(EncryptedText, key);
	cout<<"Decrypted Text:"<<DecryptedText<<endl;
}