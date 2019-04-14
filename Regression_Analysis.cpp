//
//  Regression_Analysis.cpp
//  
//
//  Created by Andrew Jackson on 12/22/18.
//
//

#include "Regression_Analysis.h"

double* Regression_Analysis::get_x_coordinates()
{
   return this -> x_coordinates;
}

double* Regression_Analysis::get_y_coordinates()
{
    return this -> y_coordinates;
}

void Regression_Analysis::set_x_coordinates(double* x_coordinates)
{
    this -> x_coordinates = x_coordinates;
}

void Regression_Analysis::set_y_coordinates(double* y_coordinates)
{
    this -> y_coordinates = y_coordinates;
}

double* Regression_Analysis::Least_Squares_Linear_Regression(int array_size)
{
    double* parameters_array = new double[2];

    int coordinates_size;
    
    double x_coordinates_sum;
    double y_coordinates_sum;
    double x_coordinates_squared_sum;
    double coordinates_product;
    
    double parameter_coefficient;
    
    coordinates_size = array_size;
    
    x_coordinates_sum = 0;
    y_coordinates_sum = 0;
    x_coordinates_squared_sum = 0;
    coordinates_product = 0;
    
    for (int i = 0; i < coordinates_size; i++)
    {
        x_coordinates_sum = x_coordinates_sum + x_coordinates[i];
        
        x_coordinates_squared_sum = x_coordinates_squared_sum + pow(x_coordinates[i], 2);
        
        y_coordinates_sum = y_coordinates_sum + y_coordinates[i];
        
        coordinates_product = coordinates_product + x_coordinates[i] * y_coordinates[i];
    }
    
    parameter_coefficient = (1 /(coordinates_size * x_coordinates_squared_sum - pow(x_coordinates_sum, 2)));
    
    parameters_array[0] = parameter_coefficient * ((y_coordinates_sum * x_coordinates_squared_sum) - (x_coordinates_sum * coordinates_product));
    
    parameters_array[1] = parameter_coefficient * ((coordinates_size * coordinates_product) - (x_coordinates_sum * y_coordinates_sum));
    
    return parameters_array;
    
}
    
    
    
    
    
        