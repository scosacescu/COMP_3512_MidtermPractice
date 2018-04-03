#include <fstream>
#include <iostream>
#include <istream>
#include <limits>

using namespace std;

// C++ Winter 2018 lecture 3: Quiz 1
// Stephanie Cosacescu A00977073
// A program to count the number of vowels in the banned novel 
// The Rainbow by D.H. Lawrence

int main() {
	//open the file
	ifstream fin;
	fin.open("therainbow.txt");

	int countA{ 0 };
	int countE{ 0 };
	int countI{ 0 };
	int countO{ 0 };
	int countU{ 0 };
	int countY{ 0 };
	int c;

	while ((c = fin.get()) != EOF)
	{
		//Count A's
		if (c == 'a' || c == 'A') {
			countA++;
		}
		//Count E's
		if (c == 'e' || c == 'E') {
			countE++;
		}
		//Count I's
		if (c == 'i' || c == 'I') {
			countI++;
		}
		//Count O's
		if (c == 'o' || c == 'O') {
			countO++;
		}
		//Count U's
		if (c == 'u' || c == 'U') {
			countU++;
		}
		//Count Y's
		if (c == 'y' || c == 'Y') {
			countY++;
		}
	}

	cout << "Number of A's: " << countA << endl;
	cout << "Number of E's: " << countE << endl;
	cout << "Number of I's: " << countI << endl;
	cout << "Number of O's: " << countO << endl;
	cout << "Number of U's: " << countU << endl;
	cout << "Number of Y's: " << countY << endl;

	fin.close();

	system("pause");
}

void restrictedVowels() {

}