#pragma once

#include <conio.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace System;
using namespace std;

class TB_Fileaccess

{
public:

	TB_Fileaccess(void);
	~TB_Fileaccess(void);
	void startTestbench(void);

};

TB_Fileaccess::TB_Fileaccess(void){}

TB_Fileaccess::~TB_Fileaccess(void){}


void TB_Fileaccess::startTestbench(void){

	cout<< "Hallo aus der TB_Fileaccess" << endl;
	_getch();

	ofstream outFile;
	outFile.open("input.txt", ofstream::ate | ofstream::trunc);
	if(outFile.fail()){
		cerr << "Das Oeffnen der Datei ist schiefgelaufen." << endl;
	}

	cout << "Geben Sie einen Text ein der in die Datei soll: " << endl;
	string str;
	getline(cin, str);
	outFile << str;
	outFile.close();
	

	ifstream inFile;
	inFile.open("input.txt");
	if(inFile.fail()){
		cerr << "Das Oeffnen der Datei ist schiefgelaufen." << endl;
	}

	string content;

	cout << "In der Datei ist folgender Text enthalten: " << endl;
	getline(inFile, content);
	cout << content << endl;
	_getch();


}

