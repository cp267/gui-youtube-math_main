#include "stdio.h"
#include "math.h"
#include "string.h"
#include "stdlib.h"
#include "conio.h"

void quadratic_main(float a,float b,float c)	
// variable declarations have been done where they have been first used.
	
{
	printf("\n");
	 // here is file input and output declaration, and there reading of a,b,c.	
	FILE *f_in, *f_out;

	// input from file
	if((f_in = fopen("input.dat", "r")) == NULL) 
	{
		printf("\nError - cannot open the designated file\n");  
		// error because file reading not possible
	}
	else                                                        
	// read and display each character from file
	{
		while(!feof(f_in))                                     
		{
			fscanf(f_in, "%f",&a);
			fscanf(f_in, "%f",&b);
			fscanf(f_in, "%f",&c);
		}
	}
	
    	
	// To write output for all the various possible values entered by the user.
	
	if((f_out = fopen("output.res", "w")) == NULL)  // this should never happen though, but still a good habit to take care of this exception
		{
		printf("\nError - cannot open the designated file\n");  
		//  error because file opening not possible
		}
	else
	{	
		float d;                         // Discriminant = d, simplifies typing.
		d = ((b*b) - (4*a*c));

		float ans1,ans2;                 // only for real roots
		if (a != 0)  // this section takes care of equations with a not equal to 0, and all possible quadratic equations
		{
			if ( d >0 )                  // real answers, dissimilar roots
			{
				ans1 = ( ((-b) + (sqrt(d))) / 2*a );
				ans2 = ( ((-b) - (sqrt(d))) / 2*a );
				fprintf(f_out,"\n");
				fprintf(f_out,"The roots of the quadratic equation are \"%.3f\" and \"%.3f\" \n",ans1,ans2);
			}	
			
			else if ( d ==0 )            // real answers, similar roots
			{
				ans1 = ( (-b)/2*a );
				fprintf(f_out,"\n");
				fprintf(f_out,"The roots are similar and equal and is %.3f \n",ans1);
			}
		
			else if ( d <0)              // complex roots
			{
				float real,complex;      // solving real and complex parts individually and then printing them out.
				complex = ( (sqrt(-d))/(2*a) );
				real = ( (-b)/(2*a) );
				fprintf(f_out,"\n");
				fprintf(f_out,"The roots of the quadratic equation are complex and are,\n");
				fprintf(f_out,"\"%.3f + %.3fi\" and \"%.3f - %.3fi\" \n",real,complex,real,complex);
			}	
		
			else
			{
				fprintf(f_out,"Unexpected error occured \n");
				fprintf(f_out,"\n");
				exit(1);
			}		
		}
	
		else if (a == 0)             	 // now this for linear equations, no x^2 part.	
		{
			ans1 = ((-c)/b) ;
			fprintf(f_out,"\n");
			fprintf(f_out,"The given equation is a linear equation and its solution is \"%.3f\" \n",ans1);
		}	
		
		else	
		{
		fprintf(f_out,"Unexpected error occured \n");
		fprintf(f_out,"\n");
		exit(1);
		}	
		
		// closing file
		fclose(f_in);
		fclose(f_out);
		exit(0);
		
		// exit(0) are for clean exits, like this one at last.
		// exit(1) for exits where errors are expected.
    }	
}