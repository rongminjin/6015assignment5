
//
//  main.cpp
//  assignment5
//
//  Created by Rongmin Jin on 1/16/19.
//  Copyright © 2019 Rongmin Jin. All rights reserved.
//


#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

ifstream myif("input.txt");
ofstream myof("output.txt");

int x =0 , y = 0, x2, y2 , x3, y3, x4, y4;
double side1, side2, side3, side4;
double angle1, angle2, angle3, angle4;
double diagonal1, diagonal2;
double PI = 3.14159, ANGLE_PER_PI= 180;

vector<string> split(const string& str, const string& delim)
{
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

void  transformInput() {
    string tempCor;
    while (getline(myif, tempCor)) {
        vector<int> temp;
        vector<string> stringTemp = split(tempCor, " ");
        
        try {
            for (int i = 0 ; i < stringTemp.size() ; ++ i) {
                
                int intTemp = stoi(stringTemp[i]);
                if (intTemp < 0 || intTemp > 100 ) {
                    cout << "error1" << endl;
                    exit (11);
                }
                temp.push_back(intTemp);
            }
        } catch (exception e1) {
            cout << "error1" << endl;
            exit (21);
        }
        
        if (temp.size() % 6 !=0 ) {
            cout << "error 1" << endl;
            exit(32);
        }
        calculation (temp);
        check();
    }
    
}

bool isEqual (double input1, double input2) {
    if (abs(input1-input2)<0.1)
        return true;
    return false;
}

void check () {
    if (isEqual(side1, side2)  && isEqual(side2, side3)  && isEqual(diagonal1, diagonal2))
        myof << "square" << endl;
    else if ( isEqual(side1, side2)  && isEqual(side1, side3)   &&  isEqual(side1, side4))
        myof << "rhombi" << endl;
    else if (isEqual(side1, side3)   && isEqual(side2, side4)  && isEqual(diagonal1, diagonal2))
        myof << "rectangle" << endl;
    else if (isEqual(side1, side3)   && isEqual(side2, side4))
        myof << "parallelograms" << endl;
    else if (isEqual((angle1 + angle2), 180) || isEqual((angle3 + angle2), 180)) {
        myof << "trapezoid" << endl;
    }
    else if ((isEqual(side1, side4) && isEqual(side2, side3)) || (isEqual(side1, side2) &&isEqual(side4, side3)))
        myof << "kite" << endl;
    else{
        if (isEqual((angle1 + angle2), (angle3 + angle4) ) || isEqual((angle1 + angle3), (angle2 + angle4) ) ) {
            cout << "error 3" << endl;
            exit(10);
        }
        myof <<"quadrilaterals" << endl;
    }
    
}



void calculation (vector<int> input) {
    
        x2 = input[0]; y2 = input[1];
        x3 = input[2]; y3 = input[3];
        x4 = input[4]; y4 = input[5];
    
        side1 = sqrt(pow(x2-x,2)+ pow (y2-y, 2));
        side2 = sqrt(pow(x3-x2,2)+ pow (y3-y2, 2));
        side3 = sqrt(pow(x4-x3,2)+ pow (y4-y3, 2));
        side4 = sqrt(pow(x-x4,2)+ pow (y-y4, 2));
    
    
    //Nullspace transformation for random test
    double tempSide1 = 1000 + side1 -1000;
    double tempSide2 = 1000* side2 /1000;
    double tempSide3 = 1.0 * side3 ;
    double tempSide4 = 4000 + side4 - 4000;
    
    //assert for random test
    assert(isEqual(tempSide1, side1));
    assert(isEqual(tempSide2, side2));
    assert(isEqual(tempSide3, side3));
    assert(isEqual(tempSide4, side4));



    
    
        diagonal2 =sqrt(pow(x3-x,2)+ pow (y3-y, 2));
        diagonal1 = sqrt(pow(x2-x4,2)+ pow (y2-y4, 2));
        
        if (side1 == 0  ||  side2 == 0 || side3 == 0 || side4 == 0 || diagonal1 == 0 || diagonal2 == 0 ) {
            cout << "error 2" << endl;
            exit(10);
        }
        angle1 = acos((pow(side1,2)+pow(side4,2) -pow(diagonal1, 2))/(2 *side1 *side4)) /PI * ANGLE_PER_PI;
        angle2 = acos((pow(side1,2)+pow(side2,2) -pow(diagonal2, 2))/(2 *side1 *side2)) /PI * ANGLE_PER_PI;
        angle3 = acos((pow(side2,2)+pow(side3,2) -pow(diagonal1, 2))/(2 *side2 *side3)) /PI * ANGLE_PER_PI;
        angle4 = acos((pow(side3,2)+pow(side4,2) -pow(diagonal2, 2))/(2 *side3 *side4)) /PI * ANGLE_PER_PI;
    cout << angle1 << " | " << angle2 << " | "<< angle3 << " | "<< angle4 << endl;
        
        double angle180 = 180;
        if (isEqual(angle1, angle180)|| isEqual(angle2, angle180) || isEqual(angle3, angle180) ||isEqual(angle4, angle180)) {
            cout << "error 4" << endl;
            exit(10);
        }
    
}

int main(int argc, const char * argv[]) {
    
   transformInput ( );
    
    return 0;
}
