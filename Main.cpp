//
//  Main.cpp
//  
//
//  Created by Andrew Jackson on 12/29/18.
//
//

#include "Regression_Analysis.h"

int main(int argc, char** argv)
{
    std::ifstream dataIn("Step 9 data adjusted.txt");
    
    if (!dataIn.is_open())
    {
        std::cout << "There is a problem opening the dataIn file." << std::endl;
    }
    
    std::string store;
    
    std::istringstream char_element;
    
    int count = 0;
    
    int new_count = 0;
    
    while (getline(dataIn, store))
    {
        
        count++;
        
    }
    
    dataIn.clear();
    dataIn.seekg(0, dataIn.beg);
    char_element.clear();
    char_element.seekg(0, char_element.beg);
    
    //double Coordinates[count][new_count];
    double* x_coordinates = new double[count];
    double* y_coordinates = new double[count];
    
    int i = 0;
    
    int j = 0;
    
    while (getline(dataIn, store))
    {
    
        std::stringstream convert(store);
        
        double result;
        
        while (convert >> result)
        {
            
            if ((new_count % 2) == 1)
            {
            
                y_coordinates[j] = result;
                
                std::cout << "y_coordinates[" << j << "]: " << y_coordinates[j] << std::endl;
                
                j++;
                
                //the reason why it is not working is because new_count in this if statement bumps the new_count to 3 and that is why it enters the if statement below, new_count (3) % 2 == 1.
                
            }
            
            if ((new_count % 2) == 0)
            {
            
                x_coordinates[i] = result;
                
                std::cout << "x_coordinates[" << i << "]: " << x_coordinates[i] << std::endl;
                
                i++;
                
            }
            
            new_count++;
            
        }
        
        std::cout << "The new_count is " << new_count << std::endl;
        
    }
    
    /*double element_size = sizeof(x_coordinates[0]);
    double array_amount = sizeof(x_coordinates);
    int array_size = sizeof(x_coordinates)/sizeof(x_coordinates[0]);
    
    std::cout << element_size << std::endl;
    std::cout << array_amount << std::endl;
    std::cout << array_size << std::endl;*/
    std::cout << "The new_count is " << new_count << std::endl;
    
    Regression_Analysis Training_Data;
    
    Training_Data.set_x_coordinates(x_coordinates);
    
    Training_Data.set_y_coordinates(y_coordinates);
    
    double* parameters_array = Training_Data.Least_Squares_Linear_Regression(count);
    
    std::cout << parameters_array[1] << "x + " << parameters_array[0] << std::endl;
    
}
            
    
    

