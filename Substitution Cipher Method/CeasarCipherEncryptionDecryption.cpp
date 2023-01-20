#include <iostream>
using namespace std;
char *Encryption(char message[], int key)
{
	char ch;
	for(int i = 0; message[i] != '\0'; i++)
	{
		ch = message[i];
		if(ch >= 'a' && ch <= 'z')
		{
			ch += key;
			if(ch > 'z')
				ch = ch - 'z' + 'a' - 1;
		}
		else if (ch >= 'A' && ch <= 'Z')
		{
			ch += key;
			if(ch>'Z')
				ch = ch - 'Z' + 'A' -1;
		}
		message[i] = ch;
	}
	return message;
}
char *Decryption(char message[], int key)
{
	char ch;
	for(int i = 0; message[i] != '\0'; i++)
	{
		ch = message[i];
		if(ch >= 'a' && ch <= 'z')
		{
			ch -= key;
			if(ch < 'a')
				ch = ch + 'z' - 'a' + 1;
		}
		else if(ch >='A' && ch <='Z')
		{
			ch -= key;
			if(ch<'A')
				ch = ch +'Z' -'A' +1;
		}
		message[i] = ch;
	}
	
	return message;
}

int main()
{
	int size = 100;
	char message[size];
	
	cout<<"Enter the Message to Encrypt:"<<endl;
	fflush(stdin);
	cin.getline(message, size);
	cout<<"Enter the Key:"<<endl;
	int key;
	cin >> key;
	cout<<"Encrypted Message:"<< Encryption(message , key)<<endl;
	cout<<"Decrypted Message:"<< Decryption(message, key);
}