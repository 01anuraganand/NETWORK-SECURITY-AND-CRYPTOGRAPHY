#include <iostream>
#include <vector>
#include <string>
#include <utility>
using namespace std;

pair<string, vector<vector<char>>> Encryption(vector<vector<char>> &pTmatrix)
{
	
	int row = pTmatrix.size(), col = pTmatrix[0].size();
	vector<vector<char>> eTmatrix(col, vector<char>(row));
	string encryptedText = "";
	for(int i = 0; i<col; i++)
		for(int j = 0; j<row; j++)
			eTmatrix[i][j] = pTmatrix[j][i];
		
	for(auto vec1: eTmatrix)
	{
		for(auto it: vec1)
			if(it != '\0')
				encryptedText += it;
	}
	return {encryptedText, eTmatrix};
}

string Decryption(vector<vector<char>> &eTmatrix)
{
	int row = eTmatrix.size(), col = eTmatrix[0].size();
	
	vector<vector<char>> oTmatrix(col, vector<char>(row));
	string decryptedText = "";
	for(int i = 0; i<col; i++)
		for(int j = 0; j<row; j++)
			oTmatrix[i][j] = eTmatrix[j][i];
		
	for(auto vec1 : oTmatrix)
		for(auto it : vec1)
			if(it != '\0')
				decryptedText += it;
	return decryptedText;
}

int main()
{
	string plainText = "anurag anand";
	int row, col = 5, k;
	if(plainText.size() % col == 0)
		row = plainText.size()/col;
	else
	{
		row = (plainText.size()/col) + 1;
		k = plainText.size()%col;
	}
	
	vector<vector<char>> pTmatrix(row, vector<char>(col));
	//Building columar table
	for(int i = 0, count = 0; i<row; i++)
	{
		for(int j = 0; j<col; j++)
			if(i == row-1 && j >=k)
				pTmatrix[i][j] = '\0';
			else
				pTmatrix[i][j] = plainText[count++];
	}
	
	
	pair<string, vector<vector<char>>> encryptedText = Encryption(pTmatrix);
	cout<<"Encrypted Text:"<<encryptedText.first<<endl;
	
	string decryptedText = Decryption(encryptedText.second);
	cout<<"Decrypted Text:"<< decryptedText<<endl;
}