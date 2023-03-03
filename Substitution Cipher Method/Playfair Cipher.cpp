#include <iostream>
#include <string>
#include <vector>
#define TEXT_SIZE 30
using namespace std;

void toUpperCase(string &str)
{
	int n = str.size();
	for(int i = 0; i<n; i++)
		if(str[i] >= 'a' && str[i] <='z')
			str[i] -= 32;
}

void spaceRemove(string &plainText)
{
	int n = plainText.size(), j = 0;
	string spaceRemoved;
	for(int i = 0; i<n; i++)
		if(plainText[i] != ' ')
			spaceRemoved += plainText[i];
	plainText = spaceRemoved;
}

vector<vector<char>> generate5x5KeyTable(string key)
{
	toUpperCase(key);
	vector<vector<char>> key5x5(5, vector<char> (5, ' '));
	int keyMap[26] = {0};
	int n = key.size(), i, j, k;
	for(i = 0; i<n; i++)
		if (key[i] != 'J')
			keyMap[key[i] - 'A'] = 2;
	keyMap['J' - 'A'] = 1;
	
	i = 0;
	j = 0;
			
	for(k = 0; k < n; k++) 
	{
		if(keyMap[key[k] - 'A'] == 2)
		{
			keyMap[key[k] - 'A'] -= 1;
			key5x5[i][j] = key[k];
			j++;
			if(j == 5)
				{i++; j = 0;}
		}
	}
	//fill the left portion in matrix
	for(k = 0; k <26; k++)
	{
		if(keyMap[k] == 0)
		{
			key5x5[i][j] = (char)(k + 'A');
			j++;
			if(j == 5)
				{i++; j = 0;}
		}
	}
	return key5x5;
}

void replaceJwithI(string plainText)
{
	for(int i = 0; i<plainText.size(); i++)
		if(plainText[i] == 'J')
			plainText[i] = 'I';
}

string Encrypt(string plainText, vector<vector<char>> &key5x5)
{
	toUpperCase(plainText);
	spaceRemove(plainText);
	replaceJwithI(plainText);
	// insert filler between any two consecutive identical letter
	for(int i = 0; i<plainText.size()-1; i += 2)
	{
		if(plainText[i] == plainText[i+1])
			plainText.insert(i+1, "X");
	}
	
	
	if(plainText.size() % 2 != 0)
		plainText += 'Z';
	cout<<plainText<<endl;
	string cipherText;
	for(int i = 0; i<plainText.size(); i+=2)
	{
		char ch1 = plainText[i];
		char ch2 = plainText[i+1];
		int r1, c1, r2, c2;
		for(int row = 0; row < 5; row++)
		{
			for(int col = 0; col <5; col++)
			{
				if(key5x5[row][col] == ch1)
				{
					r1 = row;
					c1 = col;
				}
				else if(key5x5[row][col] == ch2)
				{
					r2 = row;
					c2 = col;
				}
			}
		}
		if(r1 == r2)
		{
			cipherText += key5x5[r1][(c1+1)%5];
			cipherText += key5x5[r2][(c2+1)%5];
		}
		else if(c1 == c2)
		{
			cipherText += key5x5[(r1+1)%5][c1];
			cipherText += key5x5[(r2+1)%5][c2];
		}
		else
		{
			cipherText += key5x5[r1][c2];
			cipherText += key5x5[r2][c1];
		}
	}
	return cipherText;
}

int main()
{
	string plainText = "insstrumen";//"instr uments";
	string key = "Monarchy";
	
	//toUpperCase(plainText);
	//spaceRemove(plainText);
	cout<<"Plaintext:"<<plainText<<endl;
	
	//toUpperCase(key);
	cout<<"Key:"<<key<<endl;
	vector<vector<char>> key5x5 = generate5x5KeyTable(key);
	for(auto vec1: key5x5)
	{
		for(auto it: vec1)
			cout<< it << " ";
		cout<<endl;
	}
	
	cout<<Encrypt(plainText, key5x5);	
}