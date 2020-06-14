// Math_main - For solving all types of maths equations

#include "stdio.h"
#include "math.h"
#include "string.h"
#include "stdlib.h"
#include"conio.h"
#include "quad.c"                                   // quad.c file reference here

void quadratic_main(float a,float b,float c);       // quadratic function

void main()
{
	float x,y,z;
	quadratic_main(x,y,z);
	
}	

// main file here calls quad.c, this is so as to make it scalable, in future if we want to add more operations than we will give refernce to that c-file here
// and add definition of that maths function in that c-file.