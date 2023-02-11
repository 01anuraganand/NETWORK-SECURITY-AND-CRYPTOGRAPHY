#include <iostream>
#include <string.h>
using namespace std;
#define TEXT_SIZE 100

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

char *Encryption(char plainText[], int key1, int key2, int mapIndex[], char alphabet[])
{
	int len = strlen(plainText);
	char *multiEncrypt = new char[len];
	char *addiEncrypt = new char[len];
	//Mulitplicative Encryption key1
	int i;
	for(i = 0; plainText[i] != '\0'; i++)
	{
		if(plainText[i] != ' ')
		{
			int multi = (int(plainText[i]) * key1)%26;
			for(int j = 0; j<26; j++)
			{
				if( multi == mapIndex[j])
					multiEncrypt[i] = alphabet[j];
			}
		}
		else
		{
			multiEncrypt[i] = plainText[i];
		}
	}
	multiEncrypt[i] = '\0';
	
	//Additive Encryption key2
	for(i = 0; multiEncrypt[i] != '\0'; i++)
	{
		if(multiEncrypt[i] != ' ')
		{
			int addi = (int(multiEncrypt[i]) + key2)%26;
			for(int j = 0; j<26; j++)
			{
				if( addi == mapIndex[j])
					addiEncrypt[i] = alphabet[j];
			}
		}
		else
		{
			addiEncrypt[i] = multiEncrypt[i];
		}
	}
	addiEncrypt[i] = '\0';
	return addiEncrypt;
}

char *Decryption(char encryptedText[], int key1, int key2, int mapIndex[], char alphabet[])
{
	int len = strlen(encryptedText);
	char * multiDecrypt = new char[len];
	char * addiDecrypt = new char[len];
	
	//Additive Decryption key2
	int i;
	for(i = 0; encryptedText[i] != '\0'; i++)
	{
		if(encryptedText[i] != ' ')
		{
			int addi = (int(encryptedText[i]) -key2)%26;
			for(int j = 0; j <26; j++)
			{
				if(addi == mapIndex[j])
					addiDecrypt[i] = alphabet[j];
			}
		}
		else
		{
			addiDecrypt[i] = encryptedText[i];
		}
	}
	addiDecrypt[i] = '\0';
	
	//Multiplicative Decryption key1
	
	int multiInverse = multiplicativeInverse(key1);
	for(i = 0; addiDecrypt[i] != '\0'; i++)
	{
		if(addiDecrypt[i] != ' ')
		{
			int multi = (int(addiDecrypt[i]) * multiInverse)%26;
			for(int j = 0; j <26; j++)
			{
				if(multi == mapIndex[j])
					multiDecrypt[i] = alphabet[j];
			}
		}
		else
		{
			multiDecrypt[i] = addiDecrypt[i];
		}
	}
	multiDecrypt[i] = '\0';
	
	return multiDecrypt;
}

int main()
{
	char plainText[TEXT_SIZE];
	int key1, key2;
	int mapIndex[26] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25};
	char alphabet[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N','O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
	cout<<"Enter the text to Encrypt:"<<endl;
	cin.getline(plainText, TEXT_SIZE);
	cout<<"Enter the key1 (Multiplicative) & key2 (Additive):"<<endl;
	cin>> key1 >> key2;
	
	
	//converting to upper case
	for(int i=0; plainText[i]!='\0';i++)
    {
        if(plainText[i]>='a' && plainText[i]<='z')
        {
           plainText[i] -= 32;
        }
    }
	
	char * encryptedText = Encryption(plainText, key1, key2, mapIndex, alphabet);
	cout<< "Encrypted Text:"<<encryptedText<<endl;
	
	char * decryptedText = Decryption(encryptedText, key1, key2, mapIndex, alphabet);
	cout<< "Decrypted Text:"<<decryptedText<<endl;
	
}