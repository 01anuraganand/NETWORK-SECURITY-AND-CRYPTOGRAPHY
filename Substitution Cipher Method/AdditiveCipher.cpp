#include <iostream>
#include <string.h>
#define size 100
using namespace std;

char *Encryption(char plainText[], int key, char alphabet[],int mapIndex[])
{
	char * encryptedText = new char[strlen(plainText)];
	int i;
	for(i = 0; plainText[i] != '\0'; i++)
	{
		int additive = (int(plainText[i]) + key)%26;
		for(int j = 0; j<26; j++)
			{
				if(additive == mapIndex[j])
					encryptedText[i] = alphabet[j];
			}
	}
	encryptedText[i] = '\0';
	return encryptedText;
}

char *Decryption(char encryptedText[], int key, char alphabet[],int mapIndex[])
{
	char * decryptedText = new char[strlen(encryptedText)];
	int i;
	for(i = 0; encryptedText[i] != '\0'; i++)
	{
		int additive = (int(encryptedText[i]) - key)%26;
		for(int j = 0; j<26; j++)
			{
				if(additive == mapIndex[j])
					decryptedText[i] = alphabet[j];
			}
	}
	decryptedText[i] = '\0';
	return decryptedText;
}

int main()
{
	char plainText[size];
	int key;
	int mapIndex[26] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25};
	char alphabet[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N','O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
	
	cout<<"Enter the plain text:"<<endl;
	cin.getline(plainText, size);
	
	cout<<"Enter the key:"<<endl;
	cin>>key;
	
	//changeing small letter to capital in plaintext
	for(int i = 0; plainText[i]!= '\0'; i++)
	{
		if(plainText[i]>=97 && plainText[i]<=122)
			plainText[i] = plainText[i]-32;
	}
	
	cout<<"Plain Text:"<< plainText<<endl;
	
	char * encryptedText = Encryption(plainText, key, alphabet, mapIndex);
	cout<<"Encrypted Text:"<<encryptedText<<endl;
	
	char * decryptedText = Decryption(encryptedText, key, alphabet, mapIndex);
	cout<<"Decrypted Text:"<<decryptedText<<endl;
}
