#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace System;
using namespace std;



struct sortClass {
  bool operator() (vector<int> i,vector<int> j) { 
	  
	  if(i[0]<j[0]){
		return true;
	  }else if(i[0]==j[0]){
		if(i[1]<j[1]){
			return true;
		}else if(i[1]==j[1]){
			return true;
		}else if(i[1]>j[1]){
			return false;
		}
	  }else if(i[0]>j[0]){
		return false;
	  }
	  
	  return (false);
  }
} sortObject;


class TB_LosSorting{
public:
	TB_LosSorting();
	~TB_LosSorting();
	void startTestbench(void);
private:
};

TB_LosSorting::TB_LosSorting(){}

TB_LosSorting::~TB_LosSorting(){}

void TB_LosSorting::startTestbench(void){
	cout << "Hallo aus der Testbench fuer die Sortierung eines Losvektors." << endl;
	cin.get();

	int tipp1[] = {10,5,4,3,2,1}; vector<int> tippVector1 (tipp1, tipp1 + sizeof(tipp1) / sizeof(int));
	int tipp2[] = {6,5,4,3,2,1}; vector<int> tippVector2 (tipp2, tipp2 + sizeof(tipp2) / sizeof(int));
	int tipp3[] = {7,5,4,3,2,1}; vector<int> tippVector3 (tipp3, tipp3 + sizeof(tipp3) / sizeof(int));
	int tipp4[] = {3,5,4,3,2,1}; vector<int> tippVector4 (tipp4, tipp4 + sizeof(tipp4) / sizeof(int));
	int tipp5[] = {1,5,4,3,2,1}; vector<int> tippVector5 (tipp5, tipp5 + sizeof(tipp5) / sizeof(int));
	int tipp6[] = {2,5,4,3,2,1}; vector<int> tippVector6 (tipp6, tipp6 + sizeof(tipp6) / sizeof(int));
	int tipp7[] = {4,5,4,3,2,1}; vector<int> tippVector7 (tipp7, tipp7 + sizeof(tipp7) / sizeof(int));
	int tipp8[] = {8,5,4,3,2,1}; vector<int> tippVector8 (tipp8, tipp8 + sizeof(tipp8) / sizeof(int));
	int tipp9[] = {7,6,4,3,2,1}; vector<int> tippVector9 (tipp9, tipp9 + sizeof(tipp9) / sizeof(int));
	int tipp10[] = {11,5,4,3,2,1}; vector<int> tippVector10 (tipp10, tipp10 + sizeof(tipp10) / sizeof(int));

	vector<vector<int>> losVector;

	losVector.push_back(tippVector1);
	losVector.push_back(tippVector2);
	losVector.push_back(tippVector3);
	losVector.push_back(tippVector4);
	losVector.push_back(tippVector5);
	losVector.push_back(tippVector6);
	losVector.push_back(tippVector7);
	losVector.push_back(tippVector8);
	losVector.push_back(tippVector9);
	losVector.push_back(tippVector10);

	sort(losVector.begin(), losVector.end(),sortObject);

	for (vector<vector<int>>::iterator it1=losVector.begin(); it1!=losVector.end(); ++it1){
		for (vector<int>::iterator it2=it1->begin(); it2!=it1->end(); ++it2){
			cout << ' ' << *it2;
		}
		cout << endl;
	}
	cin.get();
}
