#include<iostream>
#include <string>
using namespace std;
int** box;
char** signbox;

	void LCS_Calculation(string x, string y) 
	{
		int p, q;
		p = x.length();
		q = y.length();
		box = new int*[p + 1];
		signbox = new char*[p];
		
		for (int i = 0; i < p + 1; i++) 
		{
			box[i] = new int[q + 1];
		}

		for (int i = 0; i < p; i++) 
		{
			signbox[i] = new char[q];
		}
		for (int i = 0; i < p + 1; i++) 
			for (int j = 0; j < q + 1; j++) box[i][j] = 0;

		for (int i = 1; i < p + 1; i++) 
		{
			for (int j = 1; j < q + 1; j++) 
			{
				if (x[i - 1] == y[j - 1]) 
				{
					box[i][j] = box[i - 1][j - 1] + 1;
					signbox[i - 1][j - 1] = 'd';
				}
				else if (box[i - 1][j] > box[i][j - 1])
				{
					box[i][j] = box[i - 1][j];
					signbox[i - 1][j - 1] = 'u';
				}
				else if (box[i][j] = box[i][j - 1]) 
				{
					box[i][j] = box[i][j - 1];
					signbox[i - 1][j - 1] = 'l';
				}
			}
		}
	}

	void Create_CH(char x)
	{
		cout << x;
	}

	void Printing_vAlue_of_LCS(char *var[], string s, int l, int m) 
	{
		if (l == -1 || m == -1) return;
		else if (var[l][m] == 'd')
		{
			Printing_vAlue_of_LCS(var, s, l - 1, m - 1);
			Create_CH(s[l]);
		}
		else if (var[l][m] == 'u')
		{
			Printing_vAlue_of_LCS(var, s, l - 1, m);
		}
		else
			Printing_vAlue_of_LCS(var, s, l, m - 1);
	}	


	int main()
	{
		string s1,s2;
		s1= "10011010";
		s2 = "1001100";
		LCS_Calculation(s1, s2);
		cout << "Calculating LCS of : "<<endl;
		cout << "string1:" << s1 << endl;
		cout << "string2:" << s2 << endl;
		cout << endl << "RESULTS : "<<endl<<"\t\t\t";
		Printing_vAlue_of_LCS(signbox, s1, s1.length() - 1, s2.length() - 1);
		return 0;
	}