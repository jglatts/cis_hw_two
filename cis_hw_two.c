/*

CIS 1057 HW 2
Author: John Glatts
Program: Triangle Determination and Area Calculation
Contact: tug13361@gmail.com
Due Date: 9/27/18 

*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>


//Function Prototypes, traiangleValid verifies triangle
//triangleType finds the type of triangle
double triangleValid(double s_one, double s_two, double s_three);
double triangleType(double side_a, double side_b, double side_c);


int main(int argc, char const *argv[]) {
    //ask user for input and store them in double variables 
    double side_one, side_two, side_three;  //user input for triangle sides 

    printf("\nEnter Length of Side 1\n");
    printf("l");
    scanf("%lf", &side_one);
    printf("\nEnter Length of Side 2\n");
    scanf("%lf", &side_two);
    printf("\nEnter Length of Side 3\n");
    scanf("%lf", &side_three);
    triangleValid(side_one, side_two, side_three); //call triangleValid, to verify
        
    return 0;
    
}

double triangleValid(double s_one, double s_two, double s_three){
    /* Test to see if the input makes a valid triangle
    
       Formula:
            a + b > c
            a + c > b
            b + c > a
            = Valid Triangle
        
        Store the longest side in int longest_side
    
    */

    if(s_one + s_two > s_three && s_one + s_three > s_two && s_two + s_three > s_one)
    {

        printf("\n\n\nVALID Triangle\n");

        //double to store the longest side 
        double longest_side;

        //find the longest side, which side is greater
        if(s_one > s_two && s_one > s_three){
            longest_side = s_one;   
            triangleType(s_two, s_three, longest_side); //find the type, with arguments
        }
        //see if the triangle ie isoceles, then run the longest side tests
        else if (s_one == s_two && s_one != s_three || s_one == s_three && s_one != s_two || s_two == s_three && s_two != s_one)
        {     
            //find the longest side 
            if(s_one > s_two && s_one > s_three){
                printf("ISOSCELES TRIANGLE");
                printf("ALSO: ");
                longest_side = s_one;   
                triangleType(s_two, s_three, longest_side); //find the type
            }
            else if(s_two > s_one && s_two > s_three){
                printf("ISOSCELES TRIANGLE\n");
                printf("ALSO: ");                
                longest_side = s_two;
                triangleType(s_one, s_three, longest_side); //find the type
            }
            else{
                printf("ISOSCELES TRIANGLE\n");
                printf("ALSO: ");                
                longest_side = s_three; 
                triangleType(s_one, s_two, longest_side);   //find the type
            }
        }
        else if(s_two > s_one && s_two > s_three){
            longest_side = s_two;
            triangleType(s_one, s_three, longest_side); //find the type
        }
        else if(s_three > s_one && s_three > s_two){
            longest_side = s_three; 
            triangleType(s_one, s_two, longest_side);   //find the type
        }
        else if (s_one == s_two && s_one == s_three)
        {
            printf("\nEQUILATERAL TRIANGLE\n");
            longest_side = s_one;
            triangleType(s_two, s_three, longest_side);
        }
    }
    else{
        printf("\n\nNOT A VALID TRIANGLE\n\n");
        return 1; //end the program if input is not valid 
    }
    return 0;
}


double triangleType(double side_a, double side_b, double side_c){
    //Figure out type of triangle
    //Find Area using Heron's Formula
    double side_a_squared, side_b_squared, side_c_squared;
    double formula_s, multiply_sides, triangle_area;
/
    side_a_squared = pow(side_a, 2); 
    side_b_squared = pow(side_b, 2);
    side_c_squared = pow(side_c, 2);

    //Heron's Formula
    formula_s = (side_a + side_b + side_c) / 2; 
    multiply_sides = (formula_s - side_a) * (formula_s - side_b) * (formula_s - side_c);
    triangle_area = sqrt(multiply_sides * formula_s); 

    if (side_a_squared + side_b_squared == side_c_squared)
    {
        printf("RIGHT TRIANGLE");
    }
    else if (side_a_squared + side_b_squared < side_c_squared)
    {
        printf("OBTUSE TRIANGLE");
    }
    else if (side_a_squared + side_b_squared > side_c_squared)
    {
        printf("ACUTE TRIANGLE");
    }
    else {
        return 1;
    }

    printf("\nArea = %lf\n", triangle_area);


    return 0;
}   
