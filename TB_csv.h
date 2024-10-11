#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>


using namespace System;
using namespace std;

class TB_csv{
public:
	TB_csv();
	~TB_csv();
	void startTestbench(void);
private:

};

TB_csv::TB_csv(){}

TB_csv::~TB_csv(){}

void TB_csv::startTestbench(void){
	cout << "Hallo aus der Testbench fuer die Behandlung von csv-Dateien." << endl;
	cin.get();

	ifstream inFile;
	inFile.open("testzahlen.cvs");
	if(inFile.fail()){
		cerr << "Das Oeffnen der Datei ist schiefgelaufen." << endl;
	}

	string line;
	string number;
	vector<int> numbers;
	const string separator(",");
	
	//cout << "In der Datei ist folgender Text enthalten: " << endl;
	while(getline(inFile, line)){
		cout << line << endl;
	
		string::size_type beginOfNumber, endOfNumber;
		
		beginOfNumber = line.find_first_not_of(separator);

		while(beginOfNumber != string::npos){
			endOfNumber = line.find_first_of(separator, beginOfNumber);

			if(endOfNumber == string::npos){
				endOfNumber = line.length();
			}

			number = line.substr(beginOfNumber, endOfNumber-beginOfNumber);
			numbers.push_back(atoi(number.c_str()));

			beginOfNumber = line.find_first_not_of(separator, endOfNumber);
		
		}
	
	}
	// print out content:
	cout << "numbers contains:";
	for (vector<int>::iterator it=numbers.begin(); it!=numbers.end(); ++it){
		cout << ' ' << *it;
	}

	cin.get();

}