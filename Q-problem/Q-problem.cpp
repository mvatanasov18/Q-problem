#include <iostream>
#include <vector>
using namespace std;
int attempts = 0;
int solutions = 0;

void displaySolution(const vector<int> v) {
	
	for (int i=0;i<int(v.size());i++)
		cout<<"  " << char(int('A') + i) <<v[i]+1;
	cout << endl;
}
bool isLegal(const vector<int>& v)
{
	attempts++;
	int value = v[v.size()-1];
	for (size_t i =	0; i < v.size()-1; i++)
	{
		if (v[i]==value)
			return 0;
	}
	int diagonal = 1;
	for (int i = v.size()-2; i >= 0; i--)
	{
		if (value==v[i]-diagonal || value==v[i]+diagonal) 
			return 0;
		diagonal++;
	}
	return 1;
}

void placeQueens(vector<int>& v, int left, int total)
{
	if (left==0)
	{
		solutions++;
		displaySolution(v);
		return;
	}

	v.push_back(0);
	for (int i = 0; i < total; ++i)
	{
		v.back() = i;

		if (isLegal(v))
		{
			placeQueens(v, left - 1, total);
		}
	}
	v.pop_back();
}

int main()
{
	vector<int>v;  int userInput;

	cout << "Type how many queens there has to be: ";
	cin >> userInput;
	cout << endl;

	placeQueens(v, userInput, userInput);

	cout << "\nAll solutions:          " << solutions << endl;
	cout << "All validation checks:  " << attempts << endl;
}