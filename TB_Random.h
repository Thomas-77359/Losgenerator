#pragma once

#include <conio.h>
#include <iostream>     // std::cout
#include <algorithm>    // std::random_shuffle
#include <vector>       // std::vector
#include <ctime>        // std::time
#include <cstdlib>      // std::rand, std::srand



using namespace System;
using namespace std;


// random generator function:
int myrandom(int i) { 
	return rand()%i;
}


class TB_Random{
public:
	TB_Random(void);
	void startTest(void);
};

TB_Random::TB_Random(void)
{}




void TB_Random::startTest(void){
	cout << "Hallo aus der Randomtestbench." << endl;
	_getch();

	srand ( unsigned ( time(0) ) );
	vector<int> myvector;

	// set some values:
	for (int i=1; i<10; ++i){
		myvector.push_back(i); // 1 2 3 4 5 6 7 8 9
	}

	// using built-in random generator:
	random_shuffle ( myvector.begin(), myvector.end() );

	// using myrandom:
	random_shuffle ( myvector.begin(), myvector.end(), myrandom);

	// print out content:
	cout << "myvector contains:";
	for (vector<int>::iterator it=myvector.begin(); it!=myvector.end(); ++it){
		cout << ' ' << *it;
	}

	cout << endl;

	_getch();

}













