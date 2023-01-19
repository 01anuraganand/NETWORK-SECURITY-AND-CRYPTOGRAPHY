#include <iostream>
using namespace std;
#define TEXT_SIZE 1000
int main()
{
	char alphabet[53] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K','L', 'M','N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z','\0'};
	// Create replacement key according to which you want to encrypt
	char replacement[53] = {'Z', 'Y', 'X', 'W', 'V', 'U', 'T', 'S', 'R', 'Q', 'P', 'O', 'N','M', 'L', 'K', 'J', 'I', 'H', 'G', 'F', 'E', 'D', 'C','B','A','z', 'y', 'x', 'w', 'v', 'u', 't', 's', 'r', 'q', 'p', 'o', 'n', 'm', 'l', 'k', 'j', 'i', 'h', 'g', 'f', 'e', 'd', 'c', 'b', 'a', '\0'};
	char plainText[TEXT_SIZE] = {'\0'};
	char encryptedText[TEXT_SIZE] = {'\0'};
	char originalText[TEXT_SIZE] = {'\0'};
	
	cout<<"Enter the Plain Text:"<<endl;
	cin.getline(plainText, TEXT_SIZE);
	
	for(int i = 0; plainText[i] != '\0'; i++)
	{
		for(int j = 0; j<52; j++)
			if(plainText[i] == alphabet[j])
				encryptedText[i] = replacement[j];
	}
	
	cout<<"Encryted Message:"<<encryptedText<<endl;
	
	for(int i = 0; encryptedText[i] != '\0'; i++)
	{
		for(int j = 0; j<52; j++)
			if(encryptedText[i] == replacement[j])
				originalText[i] = alphabet[j];
	}
	cout<<"Decrypted/Orignal Text:"<<originalText<<endl;
}