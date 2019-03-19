
//
//  main.cpp
//  assignment5
//
//  Created by Rongmin Jin on 1/16/19.
//  Copyright © 2019 Rongmin Jin. All rights reserved.
//


#include "Header.h"


bool error1Flag ;

int x =0 , y = 0, x2, y2 , x3, y3, x4, y4;
double side1, side2, side3, side4;
double angle1, angle2, angle3, angle4;
double diagonal1, diagonal2;
double PI = 3.14159, ANGLE_PER_PI= 180;

vector<string> split(const string& str, const string& delim) {
    vector<string> tokens;
    size_t prev = 0, pos = 0;
    do
    {
        pos = str.find(delim, prev);
        if (pos == string::npos) pos = str.length();
        string token = str.substr(prev, pos-prev);
        if (!token.empty()) tokens.push_back(token);
        prev = pos + delim.length();
    }
    while (pos < str.length() && prev < str.length());
    return tokens;
}

bool isEqual (double input1, double input2) {
    if (abs(input1-input2)<0.1)
        return true;
    return false;
}

void check (vector<int> input, string outputFileName) {
    
    ofstream myof;
    myof.open(outputFileName, ios::app);
    
    double angle180 = 180;
    
    if (error1Flag) {
        myof << "error1" << endl;
        error1Flag=false;
    }
    
    else if (side1 == 0  ||  side2 == 0 || side3 == 0 || side4 == 0 || diagonal1 == 0 || diagonal2 == 0 ) {
        myof << "error2" << endl;
        
    }
    
    else if (isEqual(angle1, angle180)|| isEqual(angle2, angle180) || isEqual(angle3, angle180) ||isEqual(angle4, angle180)) {
        myof << "error4" << endl;
        
    }
    
    else if (isEqual(side1, side2)  && isEqual(side2, side3)  && isEqual(diagonal1, diagonal2)) {
        myof << "square" << endl;
    }
    else if ( isEqual(side1, side2)  && isEqual(side1, side3)   &&  isEqual(side1, side4)) {
        myof << "rhombi" << endl;
    }
    else if (isEqual(side1, side3)   && isEqual(side2, side4)  && isEqual(diagonal1, diagonal2 && isEqual(angle1, 90.00) && isEqual(angle2, 90.00))) {
        myof << "rectangle" << endl;
    }
    else if (isEqual(side1, side3)   && isEqual(side2, side4) && isEqual(angle1+angle2, 180.00)) {
        myof << "parallelograms" << endl;
    }
    else if (isEqual((angle1 + angle2), 180) || isEqual((angle3 + angle2), 180)) {
        myof << "trapezoid" << endl;
    }
    else if ((isEqual(side1, side4) && isEqual(side2, side3)) || (isEqual(side1, side2) &&isEqual(side4, side3)))
        myof << "kite" << endl;
    
    else if (isEqual((angle1 + angle2), (angle3 + angle4) ) || isEqual((angle1 + angle3), (angle2 + angle4) ) ) {
        myof << "error3" << endl;
        
    }
    else
        myof <<"quadrilaterals" << endl;
}

void calculation (vector<int> input, string outputFileName) {
    x2 = input[0]; y2 = input[1];
    x3 = input[2]; y3 = input[3];
    x4 = input[4]; y4 = input[5];
    cout << x2  << " | " << y2  << " | "<< x3 << " | "<< y3  << endl;
    
    side1 = sqrt(pow(x2-x,2)+ pow (y2-y, 2));
    side2 = sqrt(pow(x3-x2,2)+ pow (y3-y2, 2));
    side3 = sqrt(pow(x4-x3,2)+ pow (y4-y3, 2));
    side4 = sqrt(pow(x-x4,2)+ pow (y-y4, 2));
    
    diagonal2 =sqrt(pow(x3-x,2)+ pow (y3-y, 2));
    diagonal1 = sqrt(pow(x2-x4,2)+ pow (y2-y4, 2));
    
    angle1 = acos((pow(side1,2)+pow(side4,2) -pow(diagonal1, 2))/(2 *side1 *side4)) /PI * ANGLE_PER_PI;
    angle2 = acos((pow(side1,2)+pow(side2,2) -pow(diagonal2, 2))/(2 *side1 *side2)) /PI * ANGLE_PER_PI;
    angle3 = acos((pow(side2,2)+pow(side3,2) -pow(diagonal1, 2))/(2 *side2 *side3)) /PI * ANGLE_PER_PI;
    angle4 = acos((pow(side3,2)+pow(side4,2) -pow(diagonal2, 2))/(2 *side3 *side4)) /PI * ANGLE_PER_PI;
    cout << angle1  << " | " << angle2  << " | "<< angle3  << " | "<< angle4  << endl;
}

void  transformInput(string inputFileName, string outputFileName) {
    error1Flag =false;
    ifstream myifa(inputFileName);
    ofstream myofa(outputFileName);
    string tempCor;
    while (getline(myifa, tempCor)) {
        vector<int> temp;
        vector<string> stringTemp = split(tempCor, " ");
        
        try {
            for (int i = 0 ; i < stringTemp.size() ; ++ i) {
                
                int intTemp = stoi(stringTemp[i]);
                
                if (intTemp < 0 || intTemp > 100 ) {
                    error1Flag=true;
                }
                temp.push_back(intTemp);
            }
        } catch (exception e1) {
            error1Flag=true;
            
        }
        
        if (temp.size() % 6 !=0 ) {
            error1Flag=true;;
            
        }
        calculation (temp, outputFileName);
        check(temp, outputFileName);
    }
    
}



int main(int argc, const char * argv[]) {
    string inputFileName = "input.txt";
    string outputFileName = "output.txt";
    
    transformInput(inputFileName, outputFileName);
    
    cout << "hello" << endl;
    
    return 0;
}
