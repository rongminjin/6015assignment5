//
//  main.cpp
//  assignment3
//
//  Created by Rongmin Jin on 1/16/19.
//  Copyright © 2019 Rongmin Jin. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;

ifstream myif("input.txt");
ofstream myof("output.txt");

int x =0 , y = 0, x2, y2 , x3, y3, x4, y4;
double side1, side2, side3, side4;
double angle1, angle2, angle3, angle4;
double diagonal1, diagonal2;
double PI = 3.14159, ANGLE_PER_PI= 180;

vector<int>  transformInput ( ) {
    vector<int> temp ;
    
    int tempCor;
    while (myif >> tempCor) {
        temp.push_back(tempCor);
    }
    
    
    return temp; 
    
}

bool isEqual (double input1, double input2) {
    if (abs(input1-input2)<0.1)
        return true;
    return false;
}

void check ( ) {
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
    else
        myof <<"quadrilaterals" << endl;
    
}

bool errorCheck ( ) {
    if (temp.size() % 6 !=0 ) {
        myof << "error 1" << endl;
        return true;
    }



    return false;
}

void calculation (vector<int> input) {
    
    for (int i = 0; i < input.size(); i +=6) {
        
        x2 = input[i]; y2 = input[i+1];
        x3 = input[i+2]; y3 = input[i+3];
        x4 = input[i+4]; y4 = input[i+5];
        
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
        check();
    }
}

int main(int argc, const char * argv[]) {
    
    calculation (transformInput ( ));
//    if (errorCheck)
//        return
    
    return 0;
}
