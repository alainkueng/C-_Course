#include<iostream>
#include<fstream>
#include<string>
#include <vector>


using namespace std;

int main() 
{
	bool MSDOS = false;
	bool UNIX = false;
	string fileName;
	string answer;
	ifstream file;
	char currentChar;

	// Asking for fileName
	cout << "Hello World" << endl; cout << "Which file do you want to convert?" << endl;
	cin >> fileName;

	//create new converted File
	ofstream ofs("Converted" + fileName, ofstream::out);


	file.open(fileName);
	if (!file.is_open())
	{
		cout << "Either file doesn't exist or you don't have permission" << endl;
		exit(1);
	}

	for (; ;) {
		cout << "Do you want a MSDOS or a UNIX conversion?" << endl;
		cin >> answer;
		if (answer == "MSDOS") { MSDOS = true; }
		if (answer == "UNIX") { UNIX = true; }
		if (MSDOS || UNIX) { break; }
		else { cout << "Try Again" << endl; }
	}

	char lastChar = ' ';
	while (file.get(currentChar)) 
	{
		if (UNIX) {
			if (currentChar == '\n' & '\r' == lastChar) {
				ofs << '\n';
			}
			else if (currentChar != '\n' & currentChar != '\r') {
				ofs << currentChar;
			}
		}
		if (MSDOS)
		{
			if (currentChar == '\n' & lastChar ) {
				ofs << '\n';
			}
			else if (currentChar != '\n' & currentChar != '\r') {
				ofs << currentChar;
			}
		}
		lastChar = currentChar;
	}
	file.close();

	return 0;
}