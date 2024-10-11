#pragma once

#include <conio.h>
#include <iostream>
#include <cmath>
#include <map>

using namespace System;
using namespace std;

struct CoordXY{
	CoordXY();	
	CoordXY(float x, float y);
	float x;
	float y;
};

CoordXY::CoordXY(){}
CoordXY::CoordXY(float x, float y):x(x), y(y){}

//Das machen wir nicht weil je nach dem der Abstand fuer alle Zahlen einer Zeile 
//oder Spalte jeweils der selbe ist. Das ist zu ungenau.
//int Distance(CoordXY &a, CoordXY &b){
//	return max(abs(a.x-b.x), abs(a.y-b.y));
//};

float computeDistance(CoordXY &a, CoordXY &b){
	return sqrt(pow(abs(a.x-b.x),2.0f) + pow(abs(a.y-b.y),2.0f));
};



class TB_Algorithmus
{
public:
	TB_Algorithmus();
	~TB_Algorithmus();
	void startTestbench(void);
private:
	map<int,CoordXY> numbers;
	void initNumbersMap(void);
};

TB_Algorithmus::TB_Algorithmus(){}
TB_Algorithmus::~TB_Algorithmus(){}

void TB_Algorithmus::startTestbench(void){
	cout << "Hallo aus der Algorithmus Testbench." << endl;
	_getch();

	initNumbersMap();

	cout << "Der Abstandswert ist: " << computeDistance(numbers[35], numbers[16]) << endl;
	_getch();

}


void TB_Algorithmus::initNumbersMap(void){
	numbers[1] = CoordXY(1.25f,1.625f);
	numbers[2] = CoordXY(4.75f,1.625f);
	numbers[3] = CoordXY(8.25f,1.625f);
	numbers[4] = CoordXY(11.75f,1.625f);
	numbers[5] = CoordXY(15.25f,1.625f);
	numbers[6] = CoordXY(18.75f,1.625f);
	
	numbers[7] = CoordXY(1.25f,5.625f);
	numbers[8] = CoordXY(4.75f,5.625f);
	numbers[9] = CoordXY(8.25f,5.625f);
	numbers[10] = CoordXY(11.75f,5.625f);
	numbers[11] = CoordXY(15.25f,5.625f);
	numbers[12] = CoordXY(18.75f,5.625f);
	
	numbers[13] = CoordXY(1.25f,9.625f);
	numbers[14] = CoordXY(4.75f,9.625f);
	numbers[15] = CoordXY(8.25f,9.625f);
	numbers[16] = CoordXY(11.75f,9.625f);
	numbers[17] = CoordXY(15.25f,9.625f);
	numbers[18] = CoordXY(18.75f,9.625f);
	
	numbers[19] = CoordXY(1.25f,13.625f);
	numbers[20] = CoordXY(4.75f,13.625f);
	numbers[21] = CoordXY(8.25f,13.625f);
	numbers[22] = CoordXY(11.75f,13.625f);
	numbers[23] = CoordXY(15.25f,13.625f);
	numbers[24] = CoordXY(18.75f,13.625f);
	
	numbers[25] = CoordXY(1.25f,17.625f);
	numbers[26] = CoordXY(4.75f,17.625f);
	numbers[27] = CoordXY(8.25f,17.625f);
	numbers[28] = CoordXY(11.75f,17.625f);
	numbers[29] = CoordXY(15.25f,17.625f);
	numbers[30] = CoordXY(18.75f,17.625f);
	
	numbers[31] = CoordXY(1.25f,21.625f);
	numbers[32] = CoordXY(4.75f,21.625f);
	numbers[33] = CoordXY(8.25f,21.625f);
	numbers[34] = CoordXY(11.75f,21.625f);
	numbers[35] = CoordXY(15.25f,21.625f);
	numbers[36] = CoordXY(18.75f,21.625f);
	
	numbers[37] = CoordXY(1.25f,25.625f);
	numbers[38] = CoordXY(4.75f,25.625f);
	numbers[39] = CoordXY(8.25f,25.625f);
	numbers[40] = CoordXY(11.75f,25.625f);
	numbers[41] = CoordXY(15.25f,25.625f);
	numbers[42] = CoordXY(18.75f,25.625f);
}