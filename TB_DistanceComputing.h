#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>


using namespace System;
using namespace std;


class TB_DistanceComputing{
public:
	TB_DistanceComputing();
	~TB_DistanceComputing();
	void startTestbench(void);

private:
};


TB_DistanceComputing::TB_DistanceComputing(){}

TB_DistanceComputing::~TB_DistanceComputing(){}

void TB_DistanceComputing::startTestbench(void){
	cout << "Hallo aus der Testbench fuer die Berechnung des mittleren Distanzwertes." << endl;
	cin.get();
}