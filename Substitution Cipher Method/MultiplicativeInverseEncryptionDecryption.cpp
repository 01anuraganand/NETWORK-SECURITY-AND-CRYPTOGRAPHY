#include <iostream>
#include <string.h>
#define size 100
using namespace std;

/*
MUltiplicative Inverse
En = (plain_text * key)%26
De = (encrypted_text *(1/key))%26
In multiplative cipher , the plain text and cipher text are encrypted in integer
*/

int multiplicativeInverse(int number)
{
    int multiInverse;
    for(int i = 1; i<=number; i++)
    {
        multiInverse = (i*26)+1;
        if(multiInverse % number == 0)
                break;
    }
    multiInverse /= number;
    return multiInverse;
}

char *Encryption(char plainText[], int key, char alphabet[], int mapIndex[])
{
	char * encryptedText = new char[strlen(plainText)];
	int i;
	for(i = 0; plainText[i] != '\0'; i++)
	{
		for(int j = 0; j<26; j++)
			if(plainText[i] == alphabet[j])
				{encryptedText[i] = alphabet[(mapIndex[j] * key)%26];}
			
	}
	encryptedText[i] = '\0';
	return encryptedText;
}

char *Decryption(char encryptedText[], int key, char alphabet[], int mapIndex[])
{
	int multiInv = multiplicativeInverse(key);
	char * decryptedText = new char[strlen(encryptedText)];
	int i;
	for(i = 0; encryptedText[i] != '\0'; i++)
	{
		for(int j = 0; j<26; j++)
			if(encryptedText[i] == alphabet[j])
				{decryptedText[i] = alphabet[(mapIndex[j] *multiInv)%26];}
			
	}
	decryptedText[i] = '\0';
	return decryptedText;
}

int main()
{
	int mapIndex[26] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25};
	char alphabet[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
	char plainText[size];
	
	int key;
	cout<<"Enter the Plain text in lowecase letter:"<<endl;
	cin.getline(plainText, size);
	cout<<"Enter the key(int) for encrypt:"<<endl;
	cin>>key;
	char * encryptedText = Encryption(plainText, key, alphabet, mapIndex);
	cout<<"Encrypted Text:"<<encryptedText<<endl;
	
	char * decryptedText = Decryption(encryptedText, key, alphabet, mapIndex);
	cout<<"Decrypted Text:" << decryptedText<<endl;
}