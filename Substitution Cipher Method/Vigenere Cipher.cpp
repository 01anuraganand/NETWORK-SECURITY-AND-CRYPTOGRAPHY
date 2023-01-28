#include <iostream>
#include <string.h>
#include <fstream>
#define TEXT_SIZE 100
using namespace std;

char *generateKey(char key[], int message_length)
{
	int i, j;
	char *newkey = new char[message_length];
	int keylen = strlen(key);
	//generate new key according to message length
	for(i = 0, j = 0; i<message_length; i++, j++)
	{
		if(j == keylen)
			j = 0;
		newkey[i] = key[j];
	}
	return newkey;
}

char *encryption(char message[], char newkey[])
{
	int message_length = strlen(message);
	int keylen = strlen(newkey);
	char * encrMessage =  new char[message_length];
	for(int i = 0; i<message_length; i++)
	{
		encrMessage[i] = ((message[i] + newkey[i])%26) + 'A';
	}
	return encrMessage;
}

char *decryption(char encrMessage[], char newkey[])
{
	int message_length = strlen(encrMessage);
	char * decrMessage = new char[message_length];
	for(int i = 0; i<message_length; i++)
	{
		decrMessage[i] = (((encrMessage[i] - newkey[i]) + 26)%26) + 'A';
	}
	return decrMessage;
}

int main()
{
	char msg[TEXT_SIZE];
	char key[TEXT_SIZE];
	ifstream fin;
	fin.open("vigenereCipher.txt",ios::in);
	fin>>msg;
	fin>>key;
	fin.close();
	cout<<endl;
	cout<<"Given Message from Text file\n";
	cout<<msg;
	cout<<endl;
	cout<<"Given Key from Text file\n";
	cout<<key;
	cout<<endl;
	int message_length = strlen(msg);
	
	// Generate key equal to msg length
	char *newkey = generateKey(key, message_length);
	char *encrMessage = encryption(msg, newkey);
	char *decrMessage = decryption(encrMessage, newkey);

	cout<<"\nEncryption of msg: "<< encrMessage;
	ofstream fout;
	fout.open("vigenereCipher.txt",ios::app);
	fout<<endl;
	fout<<encrMessage;
	
	//Decrytion
	cout<<"\nDecrypted text:"<<decrMessage;
	fout<<endl;
	fout<<decrMessage;
	fout.close();
	
}