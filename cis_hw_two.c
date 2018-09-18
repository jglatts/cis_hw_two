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
	// 
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

	// Store addition results 
	a_plus_b = s_one + s_two;
	a_plus_c = s_one + s_three;
	b_plus_c = s_two + s_three;

	if(s_one + s_two > s_three && s_one + s_three > s_two && s_two + s_three > s_one)
	{
		//Get longest side
		printf("\n\n\nVALID Triangle");
		//Get longest side
		if(s_one > s_two && s_one > s_three){
			longest_side = s_one;
			//Find the type 
			triangleType(s_one, s_two, s_three, a_plus_b, a_plus_c, b_plus_c, longest_side);
		}
		else if(s_two > s_one && s_two > s_three){
			longest_side = s_two;
			//Find the type 
			triangleType(s_one, s_two, s_three, a_plus_b, a_plus_c, b_plus_c, longest_side);
		}
		if(s_three > s_one && s_three > s_two){
			longest_side = s_three;
			//Find the type 
			triangleType(s_one, s_two, s_three, a_plus_b, a_plus_c, b_plus_c, longest_side);
		}
	}
	else{
		printf("\n\nNOT A VALID TRIANGLE\n\n");
		return 1;
	}

	return 0;
}


int triangleType(s_one, s_two, s_three, a_plus_b, a_plus_c, b_plus_c, longest_side){
	//Figure out type of triangle
	int right_tri_check_one, right_tri_check_two, right_tri_check_longest;

	right_tri_check_one = pow(s_one, 2);
	right_tri_check_two = pow(s_two, 2);
	right_tri_check_longest = pow(longest_side, 2);

	if (s_one == s_two && s_one == s_three && s_two == s_three)
	{
		printf("\nEQUILATERAL TRIANGLE\n");
	}
	else if (right_tri_check_one + right_tri_check_two == right_tri_check_longest)
	{
		printf("\nRIGHT TRIANGLE\n");
	}
	else if (right_tri_check_one + right_tri_check_two < right_tri_check_longest)
	{
		printf("\nOBTUSE TRIANGLE\n");
	}
	else if (right_tri_check_one + right_tri_check_two < right_tri_check_longest)
	{
		printf("\nOBTUSE TRIANGLE\n");
	}
	else {
		printf("\nNOT EQUILATERAL TRIANGLE");		
		printf("\nNOT RIGHT TRIANGLE\n");		
	}

	printf("Longest Side: %d\n", longest_side);
	printf("%d\n", right_tri_check_one);
	printf("%d\n", right_tri_check_two);
	printf("%d\n", right_tri_check_longest);

	return 0;
}