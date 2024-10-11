#pragma once

#include <iostream>
#include <string>

using namespace System;
using namespace std;


class TB_String{
public:
	TB_String();
	~TB_String();
	void startTestbench(void);
private:
};

TB_String::TB_String(){}

TB_String::~TB_String(){}

void TB_String::startTestbench(void){

	cout << "Hallo aus der Testbench fuer die Behandlung von Strings." << endl;
	cin.get();

	const string trenner(" \t,.;");
	string zeile;

	//laeuft wenn Enter gedrueckt wurde.
	while(getline(cin,zeile)){
		string::size_type anf, end;

		//findet den index des ersten buchstaben der kein Trennzeichen ist
		anf = zeile.find_first_not_of(trenner); 
		
		//laeuft wenn anf nicht -1 steht. find gibt das zurueck wenn nichts gefunden wurde.
		while(anf != string::npos){
			end = zeile.find_first_of(trenner, anf);

			if(end == string::npos){
				end = zeile.length();
			}
			for(int i=end-1; i>=(int)anf; i--){
				cout << zeile[i];
			}
			cout << endl;

			anf = zeile.find_first_not_of(trenner, end);
		}
	}
}

