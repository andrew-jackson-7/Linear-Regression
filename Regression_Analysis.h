//
//  Regression_Analysis.h
//  
//
//  Created by Andrew Jackson on 12/22/18.
//
//

#ifndef ____Regression_Analysis__
#define ____Regression_Analysis__

#include <iostream>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <stdlib.h>

class Regression_Analysis
{
    private:
    
    double* x_coordinates;
    double* y_coordinates;
    
    public:
    
    // get functions
    
    double* get_x_coordinates();
    double* get_y_coordinates();
    
    // set functions
    
    void set_x_coordinates(double* x_coordinates);
    void set_y_coordinates(double* y_coordinates);
    
    // other functions
    
    double* Least_Squares_Linear_Regression(int array_size);
};

#endif /* defined(____Regression_Analysis__) */
