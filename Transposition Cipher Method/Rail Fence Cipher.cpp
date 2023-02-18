#include <iostream>
#include <string.h>
#define TEXT_SIZE 100
using namespace std;

char *Encryption(char plainText[])
{
    int i, j;
    int len = strlen(plainText);
    char * encryptedText = new char[len];
    for(i = 0, j = 0; i<len; i++)
    {
        if(i % 2 == 0)
            encryptedText[j++] = plainText[i];
    }
    for(i = 0; i<len; i++)
    {
        if(i % 2 == 1)
            encryptedText[j++] = plainText[i];
    }
    encryptedText[j] = '\0';
    return encryptedText;
}

char * Decryption(char encryptedText[])
{
    int i, j, mid;
    int len = strlen(encryptedText);
    char * decryptedText = new char[len];
    
    //to get the bound
    if(len%2 == 0)    
        mid = len/2;
    else
        mid = (len/2) +1;
    
    for(i = 0, j = 0; i<mid; i++)
    {    
        decryptedText[j] = encryptedText[i];
        j =j+ 2;
    }
    
    for(i = mid, j = 1; i<len; i++)
    {
        decryptedText[j] = encryptedText[i];
        j =j+ 2;
    }
    decryptedText[j] = '\0';
    return decryptedText;
}

int main()
{
    char plainText[100];
    
    cout<<"Enter the plain text"<<endl;
    cin.getline(plainText, 100);
    
    char * encryptedText = Encryption(plainText);
    cout<<"Encrypted Text:"<<encryptedText<<endl;
    
    char * decryptedText = Decryption(encryptedText);
    cout<<"Decrytion Text:"<< decryptedText<<endl;    
}