/*
CIS 1057 HW 2
Author: John Glatts
Program: Triangle Determanation and Area Calculation
Contact: tug13361@gmail.com
Due Date: 
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int main(int argc, char const *argv[]) {
    // Ask user for input and store them in double variables 
    double side_one, side_two, side_three;  //user input for triangle sides 

    printf("\nEnter Length of Side 1\n");
    scanf("%lf", &side_one);
    printf("\nEnter Length of Side 2\n");
    scanf("%lf", &side_two);
    printf("\nEnter Length of Side 3\n");
    scanf("%lf", &side_three);
    triangleValid((int)side_one, (int)side_two, (int)side_three);
        
    return 0;
    
}

int triangleValid(s_one, s_two, s_three){
    /* Test to see if the input makes a valid triangle
       Formula:
            a + b > c
            a + c > b
            b + c > a
            = Valid Triangle
        
        Store the longest side in int longest_side
    
    */

    int a_plus_b, a_plus_c, b_plus_c, longest_side; 


    if(s_one + s_two > s_three && s_one + s_three > s_two && s_two + s_three > s_one)
    {
        printf("\n\n\nVALID Triangle");
        //Get longest side
        //WIP HOW TO FIND OTHER TYPE THAN ISOCELES
        //PUT ISOCELES UP HERE ??9
        //TRICKY BC IF ISOCELES, TRIANGLE IS EITHER RIGHT,OBTUSE, OR ACUTE 
        if(s_one > s_two && s_one > s_three){
            longest_side = s_one;   
            triangleType(s_two, s_three, longest_side);// Find the type
        }
        else if(s_two > s_one && s_two > s_three){
            longest_side = s_two;
            triangleType(s_one, s_three, longest_side);// Find the type
        }
        else if(s_three > s_one && s_three > s_two){
            longest_side = s_three; // would it be s_three??
            triangleType(s_one, s_two, longest_side);// Find the type
        }
    }
    else{
        printf("\n\nNOT A VALID TRIANGLE\n\n");
        return 1; // end the program if input is not valid 
    }
    return 0;
}


int triangleType(side_a, side_b, side_c){
    // Figure out type of triangle
    int side_a_squared, side_b_squared, side_c_squared;

    side_a_squared = pow(side_a, 2); 
    side_b_squared = pow(side_b, 2);
    side_c_squared = pow(side_c, 2);

    if (side_a == side_b && side_a == side_c && side_b == side_c && side_b == side_a)
    {
        printf("\nEQUILATERAL TRIANGLE\n");
    }
    else if (side_a_squared + side_b_squared == side_c_squared)
    {
        printf("\nRIGHT TRIANGLE\n");
    }
    // PLUG AND PLAY, LOGICAL ERROR 9/18/18
    else if (side_a_squared + side_b_squared < side_c_squared)
    {
        printf("\nOBTUSE TRIANGLE\n");
    }
    else if (side_a == side_b || side_a == side_b || side_b == side_c)
    {
        printf("\nISOCELES TRIANGLE\n");
        //after getting isoceles, find out what other type of triangle it is
    }
    // PLUG AND PLAY, LOGICAL ERROR 9/18/18
    else if (side_a_squared + side_b_squared > side_c_squared)
    {
        printf("\nACUTE TRIANGLE\n");
    }
    else {
        return 1;
    }

    printf("\n\nLongest Side: %d\n", side_c);
    printf("%d\n", side_a_squared);
    printf("%d\n", side_b_squared);
    printf("%d\n", side_c_squared);

    return 0;
} 
