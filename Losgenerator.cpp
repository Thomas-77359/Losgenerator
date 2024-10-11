#include <iostream>
#include <algorithm>
#include <list>
//#include "TB_Random.h"
//#include "TB_Fileaccess.h"
//#include "TB_Algorithmus.h"
//#include "TB_csv.h"
//#include "TB_String.h"
//#include "TB_TippSorting.h"
//#include "TB_LosSorting.h"
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <fstream>
#include <ctime>
#include <iomanip>


using namespace System;
using namespace std;

struct CoordXY{
	CoordXY();	
	CoordXY(float x, float y);
	float x;
	float y;
};

//Dient dem Sortieren des Loses.
struct sortClass {
  bool operator() (vector<int> i,vector<int> j) { 
	  
	  if(i[0]<j[0]){
		return true;
	  }else if(i[0]==j[0]){
		if(i[1]<j[1]){
			return true;
		}else if(i[1]==j[1]){
			return false; //hier muss es false sein, sonst wirft der sortieralgo einen Fehler.
		}else if(i[1]>j[1]){
			return false;
		}
	  }else if(i[0]>j[0]){
		return false;
	  }
	  
	  return (false);
  }
} sortObject;

CoordXY::CoordXY(){}
CoordXY::CoordXY(float x, float y):x(x), y(y){}

vector<int> baseData;
vector<vector<int>> labLot;
vector<vector<int>> resultLot;
map<int,CoordXY> coordinates;



void testBench(void){
	std::cout << "Dieses Hallo, du sch\x94ne Welt, kommt aus der Testbench!" << std::endl;
	
//	TB_Random *testbenchA = new TB_Random();
	//testbenchA->startTest();

//	TB_Fileaccess *testbenchB = new TB_Fileaccess();
	//testbenchB->startTestbench();

//	TB_Algorithmus *testbenchC = new TB_Algorithmus();
	//testbenchC->startTestbench();

//	TB_csv *testbenchD = new TB_csv();
	//testbenchD->startTestbench();

//	TB_String *testbenchE = new TB_String();
	//testbenchE->startTestbench();

//	TB_TippSorting *testbenchF = new TB_TippSorting();
	//testbenchF->startTestbench();

//	TB_LosSorting *testbenchG = new TB_LosSorting();
	//testbenchG->startTestbench();
}

//oeffnet das gegebene File wenn moeglich und liesst die Ausgangszahlen in den entsprechenden Vektor
void prepareBaseVector(string &filename){
	cout << "Entnehme Rohdaten aus folgendender Datei: " << filename << endl;
	//cin.get();

	ifstream inFile;
	inFile.open(filename);
	if(inFile.fail()){
		cerr << "Das Oeffnen der Datei ist schiefgelaufen." << endl;
	}

	string line;
	string number;
	const string separator("\t");
	
	while(getline(inFile, line)){
		string::size_type beginOfNumber, endOfNumber;
		beginOfNumber = line.find_first_not_of(separator);
		while(beginOfNumber != string::npos){
			endOfNumber = line.find_first_of(separator, beginOfNumber);

			if(endOfNumber == string::npos){
				endOfNumber = line.length();
			}

			number = line.substr(beginOfNumber, endOfNumber-beginOfNumber);
			baseData.push_back(atoi(number.c_str()));
			beginOfNumber = line.find_first_not_of(separator, endOfNumber);
		}
	}
}

//prueft den Vektor mit den Ausgangszahlen ob alle im Bereich zwischen [1..42] sind.
bool checkBaseVector(void){
	if(fmod(baseData.size(),6)!=0){
		cerr << "Die Anzahl Basis-Zahlen ergeben einen unvollstaendigen Tipp" << endl;
		return false;
	}
	
	for (vector<int>::iterator it=baseData.begin(); it!=baseData.end(); ++it){
		if(*it<1 || *it>42){
			return false;
		}
	}
	return true;
}

// random generator function:
int randomGenerator(int i) { 
	return rand()%i;
}

//schuettelt die den Basisvektor durch und fuellt dessen Zahlen in das labLot.
void fillRandomLabLot(void){
	srand ( unsigned ( time(0) ) );
	random_shuffle ( baseData.begin(), baseData.end(), randomGenerator);

	for (vector<vector<int>>::iterator it1=labLot.begin(); it1!=labLot.end(); ++it1){
		it1->clear();
	}

	vector<int>::iterator baseDataIt = baseData.begin();
	for (vector<vector<int>>::iterator it2=labLot.begin(); it2!=labLot.end(); ++it2){
		for(int c=1; c<=6; ++c){
			it2->push_back(*baseDataIt);
			++baseDataIt;
		}
	}
}

//fuellt die LosVektoren mit leeren Vektoren
void initLotVectors(int tippCount){
	for(int i=1; i<=tippCount; i++){
		vector<int> *labTipp = new vector<int>();
		labLot.push_back(*labTipp);
		vector<int> *resultTipp = new vector<int>();
		resultLot.push_back(*resultTipp);
	}
}

//prueft ob in einem Tipp eine Zahl nur einmal vorkommt.
bool isTippValid(vector<int>& tipp){
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

//Berechnet die geometrische Distanz zwischen zweier Zahlen auf dem Tippfeld.
float computeDistance(CoordXY &a, CoordXY &b){
	return sqrt(pow(abs(a.x-b.x),2.0f) + pow(abs(a.y-b.y),2.0f));
};

//initialisiert ein Map mit den Koordinaten jeder Zahl des Tippfeldes.
void initCoordinatesMap(void){
	coordinates[1] = CoordXY(1.25f,1.625f);
	coordinates[2] = CoordXY(4.75f,1.625f);
	coordinates[3] = CoordXY(8.25f,1.625f);
	coordinates[4] = CoordXY(11.75f,1.625f);
	coordinates[5] = CoordXY(15.25f,1.625f);
	coordinates[6] = CoordXY(18.75f,1.625f);
	
	coordinates[7] = CoordXY(1.25f,5.625f);
	coordinates[8] = CoordXY(4.75f,5.625f);
	coordinates[9] = CoordXY(8.25f,5.625f);
	coordinates[10] = CoordXY(11.75f,5.625f);
	coordinates[11] = CoordXY(15.25f,5.625f);
	coordinates[12] = CoordXY(18.75f,5.625f);
	
	coordinates[13] = CoordXY(1.25f,9.625f);
	coordinates[14] = CoordXY(4.75f,9.625f);
	coordinates[15] = CoordXY(8.25f,9.625f);
	coordinates[16] = CoordXY(11.75f,9.625f);
	coordinates[17] = CoordXY(15.25f,9.625f);
	coordinates[18] = CoordXY(18.75f,9.625f);
	
	coordinates[19] = CoordXY(1.25f,13.625f);
	coordinates[20] = CoordXY(4.75f,13.625f);
	coordinates[21] = CoordXY(8.25f,13.625f);
	coordinates[22] = CoordXY(11.75f,13.625f);
	coordinates[23] = CoordXY(15.25f,13.625f);
	coordinates[24] = CoordXY(18.75f,13.625f);
	
	coordinates[25] = CoordXY(1.25f,17.625f);
	coordinates[26] = CoordXY(4.75f,17.625f);
	coordinates[27] = CoordXY(8.25f,17.625f);
	coordinates[28] = CoordXY(11.75f,17.625f);
	coordinates[29] = CoordXY(15.25f,17.625f);
	coordinates[30] = CoordXY(18.75f,17.625f);
	
	coordinates[31] = CoordXY(1.25f,21.625f);
	coordinates[32] = CoordXY(4.75f,21.625f);
	coordinates[33] = CoordXY(8.25f,21.625f);
	coordinates[34] = CoordXY(11.75f,21.625f);
	coordinates[35] = CoordXY(15.25f,21.625f);
	coordinates[36] = CoordXY(18.75f,21.625f);
	
	coordinates[37] = CoordXY(1.25f,25.625f);
	coordinates[38] = CoordXY(4.75f,25.625f);
	coordinates[39] = CoordXY(8.25f,25.625f);
	coordinates[40] = CoordXY(11.75f,25.625f);
	coordinates[41] = CoordXY(15.25f,25.625f);
	coordinates[42] = CoordXY(18.75f,25.625f);
}


//berechnet die mittlere Distanz fuer einen Tipp
float computeAverageTippDistance(vector<int>& tipp){
	
	int aktNr;
	float tippSum = 0.0f;
	float nrSum = 0.0f;

	for(vector<int>::iterator it1=tipp.begin(); it1!=tipp.end(); ++it1){
		aktNr = *it1;

		for(vector<int>::iterator it2=tipp.begin(); it2!=tipp.end(); ++it2){
			if(aktNr != *it2){
				//cout << "Die Distanz zwischen " << aktNr << " und " << *it2 << " betraegt: " << computeDistance(coordinates[aktNr], coordinates[*it2]) << endl;
				nrSum += computeDistance(coordinates[aktNr], coordinates[*it2]);
			}
		}
		//cout << "Die summe betraegt: " << nrSum << endl;
		//cout << "Die mittlere Nummer-Distanz fuer Nummer " << aktNr << " ist: " << nrSum / 5 << endl;
		//cin.get();
		tippSum += nrSum / 5;
		nrSum = 0.0;
	}
	//cout << "Die mittlere Tipp-Distanz ist: " << tippSum / 6 << endl;
	//cin.get();
	return tippSum / 6;
}

vector<float> tippDistances;

//berechnet die mittlere Distanz fuer ein Los
float computeAverageLabLotDistance(void){
	
	float sum = 0.0;
	float result = 0.0;
		
	tippDistances.clear();
	for (vector<vector<int>>::iterator it1=labLot.begin(); it1!=labLot.end(); ++it1){
		result = computeAverageTippDistance(*it1);
		sum += result;
		tippDistances.push_back(result);
	}
	return (sum - *max_element(tippDistances.begin(), tippDistances.end())) / (labLot.size() - 1);
}


//Sortiert erst die Zahlen innerhalb der Tipps.
//Anschliessend sortiert es die Tipps innerhalb des Los.
void sortLabLot(void){
	for (vector<vector<int>>::iterator it1=labLot.begin(); it1!=labLot.end(); ++it1){
		sort(it1->begin(), it1->end());
	}
	sortClass sortierer;
	sort(labLot.begin(), labLot.end(), sortierer);
}


int main(int argc_, char *argv_[])
{
	int argc = argc_;
	vector<string> argv;

    argv.resize(argc);
    copy(argv_,argv_+argc,argv.begin());

	if(argc < 2){
		cerr << "Es muss mindestens ein String mit einem Dateinamen als Argument mitgegeben werden." << endl;
		cin.get();
		return 1;
	}

	vector<string>::iterator it1=argv.begin();
	++it1;

	string filename(*it1);

	prepareBaseVector(filename);
	if(!checkBaseVector()){
		cerr << "Ein oder mehrere Basis-Zahlen befinden sich ausserhalb des Bereichs [1..42]." << endl;
		cin.get();
		return 1;
	}

	//initialisiert die Losvektoren mit je 14 Elementen.
	initLotVectors(14);
	initCoordinatesMap();
	
	bool fail=false;
	float lotMiddleDistance = 0.0;
	long lotNr = 0;
	double distanceValue = 0.0;
	string input;

	if(argc <= 2){
		cout << "Welcher mittlere Distanzwert soll gesucht werden (muss eine float sein): ";
		cin >> input;
		distanceValue =  atof(input.c_str());		
	}else{
		++it1;
		distanceValue =  atof(it1->c_str());
		cout << "Als mittlerer Distanzwert wird verwendet: " << distanceValue << endl;
		//cin.get();
	}
	
	while(true){
		fillRandomLabLot();
		lotNr++;
		
		for (vector<vector<int>>::iterator it4=labLot.begin(); it4!=labLot.end(); ++it4){
			if(!isTippValid(*it4)){
				fail = true;
				break;
			}
		}	
		if(fail==true){
			cout << lotNr << ": Fehler: Ungueltiges Los" << endl;
			fail = false;
			//cin.get();
			continue;
		}

		lotMiddleDistance = computeAverageLabLotDistance();
		cout << "Der Distanzwert ist: " << distanceValue;

		if(distanceValue < (double)lotMiddleDistance ){
			cout << lotNr << ": Fehler: Ungueltige mittlere Distanz" << endl;
			fail = false;
			continue;
		}

		sortLabLot();

		int nr = 1;
		cout << lotNr << ": Das Los sieht wie folgt aus:" << endl;
		for (vector<vector<int>>::iterator it2=labLot.begin(); it2!=labLot.end(); ++it2){
			cout << "Tipp " << setw(2) << setfill('0') << nr << ":  ";		
			for (vector<int>::iterator it3=it2->begin(); it3!=it2->end(); ++it3){
				cout << ' ' << *it3;
			}
			cout << endl;
			nr++;
		}
		
		cout << "Die mittlere Distanz des Loses ist: " << lotMiddleDistance << endl;

		cout << endl;
		fail = false;
		
		//cin.get();
		cout << "Welcher mittlere Distanzwert soll gesucht werden (muss eine float sein): ";
		cin >> input;
		distanceValue =  atof(input.c_str());

	}

  return 0;
}




