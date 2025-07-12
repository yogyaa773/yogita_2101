#include<stdio.h>
void main()
{
	float celsius,fahrenheit;
	printf("enter the temperature celsius:");
	scanf("%f",&celsius);
	celsius=(fahrenheit*9/5)+32;
	printf("temperature in fahrenheit:%.2f",fahrenheit);
}