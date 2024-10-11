#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>


using namespace System;
using namespace std;


class TB_TippSorting{
public:
	TB_TippSorting();
	~TB_TippSorting();
	void startTestbench(void);

private:
	bool isTippValid(vector<int>& tipp);
};

TB_TippSorting::TB_TippSorting(){}

TB_TippSorting::~TB_TippSorting(){}

bool TB_TippSorting::isTippValid(vector<int>& tipp){
	for(vector<int>::iterator it1=tipp.begin(); it1!=tipp.end(); ++it1){
		for(vector<int>::iterator it2=tipp.begin(); it2!=tipp.end(); ++it2){
			if(it1!=it2){
				if(*it1 == *it2){
					return false;
				}
			}
		}
	}
	return true;
}



void TB_TippSorting::startTestbench(void){
	cout << "Hallo aus der Testbench fuer das Sortieren von Vektoren." << endl;
	cin.get();

	int tipp[] = {6,5,4,3,2,1}; 
	vector<int> tippVector (tipp, tipp + sizeof(tipp) / sizeof(int));

	cout << "myvector contains:";
	for (vector<int>::iterator it=tippVector.begin(); it!=tippVector.end(); ++it){
		cout << ' ' << *it;
	}
	cout << endl;

	string res(isTippValid(tippVector)?"Ja":"Nein");

	cout << "Ist der Vektor gueltig: " << res << endl;
	cin.get();

	sort(tippVector.begin(), tippVector.end());

	cout << "myvector contains:";
	for (vector<int>::iterator it=tippVector.begin(); it!=tippVector.end(); ++it){
		cout << ' ' << *it;
	}
	cout << endl;
	cin.get();

}

