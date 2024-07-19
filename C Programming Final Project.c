#include<stdio.h>
#include<stdlib.h>
#include<math.h>    /* This library already includes the modulus for float values that I previously used fmod() and the function for powers of numbers pow(), also includes trig functions */
#include<stdbool.h>


/* Thomas Childers CSE 130-50-4245 ID#5349355 Final Coding Project*/


float sum(float No1, float No2);
float sub(float No1, float No2);
float mult(float No1, float No2);
float divid(float No1, float No2);
void fib(int No1, int output);


bool is_prime(int No1) {         //This bool is to test if a number is prime and is called later

    if (No1 <= 1) {
        return false;
    }
    for (int i = 2; i <= No1 / 2; i++) {
        if (No1 % i == 0) {
            return false;
        }
    }
    return true;
}

float sum(float No1, float No2){  //addition function
	return No1 + No2;
}

float sub(float No1, float No2){ //subtraction function
	return No1 - No2;
}

float mult(float No1, float No2){ //multiplication function
	return No1 * No2;
}

float divid(float No1, float No2){  //division function
	return No1 / No2;
}

unsigned long long int fact(unsigned long long int n) //factorial function
{
	if (n == 0)
		return 1;
	return n * fact(n-1);
}

//fmod function included in math.h
//pow function included in math.h

void fibo(int No1, int *output)  //fibonacci function
{
	output[0] = 0;
	output[1] = 1;
	for (int i = 2; i < No1; i++)
	{
		output[i] = output[i-1] + output[i-2];
	}
}

// Binary Conversion Function Called at 10

void binaryconvert(int No1)
{

	int binary[32];
	
	int i = 0;
	while (No1 > 0) {
		binary[i] = No1 % 2;
		No1 = No1 / 2;
		i++;
	}
	for (int j = i - 1; j >= 0; j--)
		printf("%d",binary[j]);	
		printf("\n");
}




int main()
{
	menu:
	while (1){           //Loop to make it so that you can exit out of the calculator
	
	int symbol;

	printf ("Calculator Menu: \n [1] Addition (Numbers) \n [2] Subtraction (Numbers) \n [3] Multiplication (Numbers) \n [4] Division (Numbers) \n [5] Modulus (Integers Only) \n [6] Test if Prime (Integers only) \n [7] Factorial (Integers up to 20 only) \n [8] Power (Numbers) \n [9] Fibonacci (Numbers) \n [10] Binary Converter (Numbers) \n [11] Trigonometric Functions \n [12] Hexadecimal Converter \n [0] Exit \nPlease Choose an operation: ");
	scanf("%d", &symbol);    //Menu with input from user for calculator

	switch (symbol){
		case 1:  //addition section
	{
			float No1, No2, output; //local float so that the function can handle decimals
		printf ("Type the First number you want to be used in the operation\n");
		scanf("%f", &No1);
		printf ("Type the Second number you want to be used in the operation\n");
		scanf("%f", &No2);
		output = sum(No1, No2); //addition function called here
	printf("%f + %f = %f\n",No1 ,No2, output);
	break;
	}
	
	case 2: //subtraction section
	{
			float No1, No2, output; //local float so that the function can handle decimals
		printf ("Type the First number you want to be used in the operation\n");
		scanf("%f", &No1);
		printf ("Type the Second number you want to be used in the operation\n");
		scanf("%f", &No2);
			output = sub(No1, No2); //subtraction function called here
	printf("%f - %f = %f\n",No1 ,No2 ,output);
	break;
	}	
	
		case 3:  //multiplication section
		{
			float No1, No2, output; //local float so that the function can handle decimals
		printf ("Type the First number you want to be used in the operation\n");
		scanf("%f", &No1);
		printf ("Type the Second number you want to be used in the operation\n");
		scanf("%f", &No2);
			output = mult(No1, No2); //multiplication function called here
	printf("%f * %f = %f\n",No1 ,No2 ,output);
	break;
	}	
	
		case 4: //division section
		{
			float No1, No2, output; //local float so that the function can handle decimals
		printf ("Type the First number you want to be used in the operation\n");
		scanf("%f", &No1);
		printf ("Type the Second number you want to be used in the operation\n");
		scanf("%f", &No2);			
			output = divid(No1, No2); //division function called here
	printf("%f / %f = %f\n",No1 ,No2 ,output);
	break;
	}	
	
		case 5:     //modulus section
		{
			int No1, No2, output;  //integers here so that the function works
		printf ("Type the First number you want to be used in the operation\n");
		scanf("%d", &No1);
		printf ("Type the Second number you want to be used in the operation\n");
		scanf("%d", &No2);
			output = fmod(No1,No2); //modulus function called here from math.h
	printf("%d Modulated by %d = %d\n",No1 ,No2, output);
	break;
	}	
		case 6:  //prime number tester
		{
			int No1, No2, output; //integers here so that the function works
		printf("Enter Number to be tested\n");
		scanf("%d", &No1);
			if (No1 < 2) {
				printf("Not prime: %d is less than 2",No1);
							}
			if (is_prime(No1)) //Bool is called here
			{
				printf("%d is a prime number\n",No1);			
			}
			else 
			{
				for (int i = 2; i <= No1 / 2; i++) {
					if (No1 % i == 0) {
						printf("Not prime: %d x %d = %d\n", i, No1 / i, No1); //various conditions for prime number
										}			
						}	
			}
			break;
	}
		case 7:
		{
				int No1;  //Factorial section
			printf("Pick a Number between 0 and 20\n");
			scanf("%d",&No1);
					if (No1 > 20)
						printf("Please pick a number between 0 and 20\n"); //range so that the facotrial works properly
					else if (No1 < 0)
						printf("Please pick a number between 0 and 20\n");
					else
		printf("The factorial of %d is %lld \n",No1, fact(No1)); //factorial function called here
		break;
	}
		
		case 8:
		{
			float No1, No2, output; //local float so that the function can handle decimals
		printf ("Type the base number\n");
		scanf("%f", &No1);
		printf ("Type the number you want it to be a power to\n");
		scanf("%f", &No2);			
			output = pow(No1, No2); //power fucntion called from math.h
		printf("%f to the power of %f = %f\n",No1 ,No2 ,output);
		break;			
	}
		case 9:
		{
				int No1, i; //integers so that the function works
			printf("Enter the number of terms\n");
			scanf("%d", &No1);
			if (No1 <= 0)
				{
					printf("The number must be positive\n");
				}
			else
				{
					int output[No1]; //array of the outputs so that it is stored and called later in the function
					fibo(No1, output); //fibonacci function
					printf("The first %d numbers of the Fibonacci Sequence are ", No1);
					for (i = 0; i < No1; i++)
						{
							printf("%d ", output[i]);
						}
						printf("\n");
						break;
				}
	}
		case 10: {
		int No1 = '\0';
		printf("What number do you wish to convert?\n");
		scanf("%d",&No1);
		binaryconvert(No1);
			break;
		}
		
		case 11: {

				while(1){
			
				int symbol2;
			
				printf("Trigonometric Functions Menu \n [1] Sin \n [2] Cos \n [3] Tan \n [4] Arc-sin (Number Between -1 to 1) \n [5] Arc-cos (Number Between -1 to 1) \n [6] Arc-Tan (Number Between -1 to 1) \n [0] Back to Menu \n Please Choose an function \n");
				scanf("%d", &symbol2);
			
				switch (symbol2){
					case 1:{
					double No1, output;
					printf("Intput the angle for the sine function \n");
					scanf("%lf", &No1);
					output = sin(No1);
					printf("sin(%lf) = %.2lf \n", No1, output);
					break;
				}
				case 2:{
					double No1, output;
					printf("Intput the angle for the cosine function \n");
					scanf("%lf", &No1);
					output = cos(No1);
					printf("cos(%lf) = %.2lf \n", No1, output);
					break;
				}
				case 3:{
					double No1, output;
					printf("Intput the angle for the tangent function \n");
					scanf("%lf", &No1);
					output = tan(No1);
					printf("tan(%lf) = %.2lf \n", No1, output);
					break;
				}
				case 4:{
					double No1, output;
					printf("Intput the angle for the arc-sine function \n");
					scanf("%lf", &No1);
					output = asin(No1);
					printf("arc-sin(%lf) = %.2lf \n", No1, output);
					break;
				}
				case 5:{
					double No1, output;
					printf("Intput the angle for the arc-cosine function \n");
					scanf("%lf", &No1);
					output = acos(No1);
					printf("arc-cos(%lf) = %.2lf \n", No1, output);
					break;
				}
				case 6:{
					double No1, output;
					printf("Intput the angle for the arc-tangent function \n");
					scanf("%lf", &No1);
					output = atan(No1);
					printf("arc-tan(%lf) = %.2lf \n", No1, output);
					break;
				}
				case 0: {
					printf("Returning to main menu \n");
					goto menu;
				}
				default: {
					printf("Operation not recognized \n");
					break;
				}
			}
			}	
		
		}
		
		case 12: {
			char hex[] = "";
			printf("Enter what you wish to convert. \n");
			scanf("%s", &hex);
			int num = (int)strtol(hex, NULL, 16);       						// number base 16
			printf("%d converted as a decimal\n", num);                        // print it as decimal
			printf("%X converted into hexadecimal\n", num);   				  // print in hexadecmial
			break;
		}
	
			
			
		break;
		
		case 0:
		{
		printf("Goodbye!\n"); //exit section
		return 0;	
		}
	
	
	
		default: 
		{
		printf("Operator Not Recognized\n"); //if the user inputs anything other than the selected number it cycles
		break;

	}

}
}
}
