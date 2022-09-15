#include<bits/stdc++.h>
#include <iostream>
#include <fstream>
using namespace std;

// A quick way to split strings separated via any character
// delimiter.
void adv_tokenizer(string s, char del, vector<vector<double>> &matrix, vector<double> &vals)
{
	stringstream ss(s);
	string word;
	vector<double> temp;
	while (!ss.eof()) {
		getline(ss, word, del);
		temp.push_back(stod(word));
	}
	vals.push_back(temp[temp.size()-1]);
	temp.pop_back();
	matrix.push_back(temp);
	ss.clear();
	return;
}

void Making_vectors(vector<vector<double>> &A, vector<double> &B)
{
	string b;
	// Read from the text file
	ifstream MyReadFile;
	MyReadFile.open("test.txt", ios::in);
	// Use a while loop together with the getline() function to read the file line by line
	while (getline(MyReadFile, b))
	{
  		// Output the text from the file
		// cout<<b;
		adv_tokenizer(b, ',', A, B);
		// cout << endl;
	}
	// int n = A.size();
	// cout<<"\nValues initialized are...\n";
	// cout << "A            | B\n\n";
	// for(int i=0;i<n;i++)
	// {
	// 	for(int j=0;j<n;j++)
	// 	{
	// 		cout << A[i][j] << ' ';
	// 	}
	// 	cout << "| " << B[i] << '\n';
	// }
	MyReadFile.close();
	return;
}

int main(int argc, char const* argv[])
{
	vector<vector<double>> A;
	vector<double> B;
	Making_vectors(A, B);

	return 0;
}
