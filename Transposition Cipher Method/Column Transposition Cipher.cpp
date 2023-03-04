#include <iostream>
#include <map>
#include <string>
using namespace std;

void setPermutation(string &key, map<int, int> &alphabetOrder)
{
	
	for(int i = 0; i<key.size(); i++)
		alphabetOrder[key[i]] = i;		
}

string Encryption(string plainText, string key)
{
	map<int, int> alphabetOrder;
	setPermutation(key, alphabetOrder);
	
	int col = key.size();
	int row = plainText.size()/col;
	if(plainText.size() % col)
		row +=1;
	
	string table[row][col];
	int k = 0;
	for(int i = 0; i<row; i++)
	{
		for(int j = 0; j<col; j++)
		{
			if(plainText[k] == '\0')
				table[i][j] = '_',k++;
			else
				table[i][j] = plainText[k++];
		}
	}
	
	string encryptedText = "";
	for(auto it: alphabetOrder)
	{
		int j = it.second; //store column number
		for(int i = 0; i<row; i++)
			encryptedText += table[i][j];
	}
	
	for(int i = 0; i<row; i++)
	{
		for(int j = 0; j<col; j++)
			cout<<table[i][j]<< " ";
		cout<<endl;
	}
	return encryptedText;
}
int main()
{
	string plainText = "Geeks for Geeks";
	string key = "HACK";
	string encryptedText = Encryption(plainText, key);
	cout<<"Encrypted Text:"<<encryptedText<<endl;
	
}