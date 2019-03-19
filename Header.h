//
//  Header.h
//  
//
//  Created by rongminjin on 3/19/19.
//

#ifndef Header_h
#define Header_h
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;

vector<string> split(const string& str, const string& delim);

bool isEqual (double input1, double input2);

void check (string outputFileName);

void calculation (vector<int> input, string outputFileName);

void  transformInput(string inputFileName, string outputFileName);

#endif /* Header_h */
