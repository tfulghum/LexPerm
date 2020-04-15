#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<iomanip>

using namespace std;

// Author: Tyler Fulghum

void bubbleSort(vector<string> &strings);
bool next_permutation(vector<string> str);
void permutations(vector<string> str);

int main()
{
	bool goFlag = true;
	vector<string> lex;
	string iString = "";

	//Adds string to vector until quit is said
	while(goFlag == true)
	{
		//Breaks if vector too big
		if(lex.size() >= 100)
		{
			cout << "Max array size reached" << endl;
			break;
		}
		
		//Gets info
		cout << "Enter a string or type quit: ";
		getline(cin, iString);
		
		if(iString == "quit")
			goFlag = false;
		else
			lex.push_back(iString);
		cout << endl;
	}
	
	cout << endl << "The size of your array is " << lex.size() << " elements." << endl;
	
	//Outputs sorted vector
	cout << endl;
	//Lexicographic algorithm
	cout << endl;
	permutations(lex);
}

//Bubble sort to sort the vector
void bubbleSort(vector<string> &strings)
{
    typedef vector<string>::size_type size_type;
    for (size_type i = 1; i < strings.size(); ++i)
    {
        for (size_type j = 0; j < (strings.size() - 1); ++j)
        {
            if(strings[j] > strings[j+1])
            {
                string const temp = strings[j];
                strings[j] = strings[j + 1];
                strings[j+1] = temp;
            }
        }
    }
	
	for(int i = 0; i < strings.size(); i++)
		cout << strings[i] << "   ";
}

bool next_permutation(vector<string> &str, int n) 
{
	int i = n - 1;
	while (str[i - 1] >= str[i])
	{
		if (--i == 0)
			return false;
	}

	//Finding the consecutive i and j values
	int j = n - 1;
	while (j > i && str[j] <= str[i - 1])
		j--;
 
	// Swap characters at index i-1 with index j
	iter_swap(str.begin() + (i - 1), str.begin() + j);
	
	reverse(str.begin() + i, str.end());
	
	// Reverse the substring str[i..n) and return true
 
	return true;
}

void permutations(vector<string> str)
{
	// sort the string in ascending order
	bubbleSort(str);
	cout << endl << endl;
	int numTimes = 1;
	cout << left;
	while(1)
	{
		// print current permutation
		cout<<setw(7)<<numTimes;
		for(int i = 0; i < str.size(); i++)
			cout << str[i] << "    ";

		// find next lexicographically ordered permutation
		if(next_permutation(str, str.size()) == false)
		{
			break;
		}
		numTimes++;
		cout << endl;
	}
}