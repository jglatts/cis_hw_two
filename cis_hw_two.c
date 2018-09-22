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
        //TRICKY BC IF ISOCELES, TRIANGLE IS EITHER RIGHT,OBTUSE, OR ACUTE 
        if(s_one > s_two && s_one > s_three){
            longest_side = s_one;   
            s_one = s_three; // this allows user to enter sides in any given order   
            triangleType(s_one, s_two, s_three, longest_side);// Find the type
        }
        else if(s_two > s_one && s_two > s_three){
            longest_side = s_two;
            s_two = s_one; // this allows user to enter sides in any given order      
            triangleType(s_one, s_two, s_three, longest_side);// Find the type
        }
        else{
            //ISOCELES TRIANGLE
            longest_side = s_three; // would it be s_three??
            triangleType(s_one, s_two, s_three, longest_side);// Find the type
        }
    }
    else{
        printf("\n\nNOT A VALID TRIANGLE\n\n");
        return 1; // end the program if input is not valid 
    }
    return 0;
}


int triangleType(s_one, s_two, s_three, a_plus_b, longest_side){
    // Figure out type of triangle
    int right_tri_check_one, right_tri_check_two, right_tri_check_longest;

    right_tri_check_one = pow(s_one, 2); 
    right_tri_check_two = pow(s_two, 2);
    right_tri_check_longest = pow(longest_side, 2);

    if (s_one == s_two && s_one == s_three && s_two == s_three && s_three == s_one)
    {
        printf("\nEQUILATERAL TRIANGLE\n");
    }
    else if (right_tri_check_one + right_tri_check_two == right_tri_check_longest)
    {
        printf("\nRIGHT TRIANGLE\n");
    }
    // PLUG AND PLAY, LOGICAL ERROR 9/18/18
    else if (right_tri_check_one + right_tri_check_two < right_tri_check_longest)
    {
        printf("\nOBTUSE TRIANGLE\n");
    }
    else if (s_one == s_two || s_one == s_three || s_two == s_three)
    {
        printf("\nISOCELES TRIANGLE\n");
        //after getting isoceles, find out what other type of triangle it is
    }
    // PLUG AND PLAY, LOGICAL ERROR 9/18/18
    else if (right_tri_check_one + right_tri_check_two > right_tri_check_longest)
    {
        printf("\nACUTE TRIANGLE\n");
    }
    else {
        return 1;
    }

    printf("\n\nLongest Side: %d\n", longest_side);
    printf("%d\n", right_tri_check_one);
    printf("%d\n", right_tri_check_two);
    printf("%d\n", right_tri_check_longest);

    return 0;
} 
