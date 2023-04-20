#include <iostream>
#include <string>
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
	cout<<"Enter the key (equal to size of PlainText):"<<endl;
	cin>>key;
	string EncryptedText = encryption(plainText, key);
	cout<<"Encrypted Text:"<<EncryptedText<<endl;
	string DecryptedText = decryption(EncryptedText, key);
	cout<<"Decrypted Text:"<<DecryptedText<<endl;
}